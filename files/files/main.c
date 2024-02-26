//
//  main.c
//  files
//
//  Created by Ashish Acharya on 27/12/2023.
// C program to illustrate fopen()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* demo;
    char name;
    demo = fopen("//Users//ashish//Desktop//structure//files//files//demo_file.txt", "w+");//w+ searches the file exists , contents are overwritten
    printf("enter the string:");
 fseek(demo, 0, SEEK_END);
    fgets(&name, 100, stdin);

    // Creates a file "demo_file" with file access as write-plus mode
    fwrite(&name, sizeof(char), 1,SEEK_END );
//    fprintf(demo, "%s %s %s", "Welcome", "to",
//            "GeeksforGeeks");
    fclose(demo);//closes the file

    return 0;
}
