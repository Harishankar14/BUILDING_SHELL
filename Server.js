const express = require("express");
const cors = require("cors");
const multer = require("multer");
const { exec } = require("child_process");
const fs = require("fs");

const app = express();
const upload = multer();

app.use(cors());
app.use(express.json());

app.post("/validate", upload.single("text"), (req, res) => {
    if (!req.file) {
        return res.status(400).json({ error: "No input provided" });
    }

    const inputText = req.file.buffer.toString();
    fs.writeFileSync("input.txt", inputText);  // Save input text to a file

    exec("./validator < input.txt", (error, stdout, stderr) => {
        if (error) {
            return res.status(500).json({ error: stderr });
        }
        res.json({ result: stdout.split("\n").filter(line => line) });
    });
});

const PORT = 5000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
