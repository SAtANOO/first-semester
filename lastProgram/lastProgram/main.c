//
//  main.c
//  lastProgram
//
//  Created by Ashish Acharya on 11/01/2024.
//

#include <stdio.h>
#include <stdlib.h>

void Up_string(char* str) {
while (*str != '\0') {
if (*str >= 'a' && *str <= 'z')*str -= 32;
str++;
}
}



int main(int argc,char *argv[]) {
if (argc < 3) {
printf("Invalid\n");
    return 0;
}
for (int i = 1; i < argc; i++) {
Up_string(argv[i]);
}
for (int j= 1; j< argc; j++) {
printf("%s ", argv[j]);
}
return 0;
}
