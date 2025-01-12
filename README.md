# BUILDING_SHELL

Building a shell from scratch.

Date: December (22/12/2024)
Status: Uploaded main header file which basically contains the major prototypes.

Date: December (26/12/2024)
Status: Added a Server file.cpp, which is independent of these, but will be needed.
Have saved Cthe lient side internally.
For now simple prompts, but it works, I will modify it in the feature.


Date: January (12/01/2025)
I know its a bit long break.. nvm got busy.

Status: The main.c file that I uploaded today basically deals with the memory allocation and deadline.
The part that was hard to figure out was the allocation block of the memory if the user exceeds the BLOCK LIMIT.
Here we are allocating a fixed block size of 200000.
I could assign it as CONST INT BLOCK_SIZE=INF;
but still, the processing takes a bit too long.
so if the mem_allocation exceeds, the system will automatically divides the block, so this func is majorly handled by lsh_loop()

