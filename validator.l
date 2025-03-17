%{
#include <stdio.h>
%}

%%

"http://"[^ \t\n]+  { printf("Unsafe URL: %s\n", yytext); }
"https://"[^ \t\n]+ { printf("Trusted URL: %s\n", yytext); }

.|\n                { /* Ignore other characters */ }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
