//
//  main.c
//  readingfiles
//
//  Created by Ashish Acharya on 29/12/2023.
//

#include <stdio.h>

int main() {
    FILE *ptr;
    char c;
    ptr=fopen("//Users//ashish//Desktop//structure//readingfiles//readingfiles//file.txt", "a");
//    fseek(ptr, 1, SEEK_CUR);
//    scanf("%c",&c);
//    fseek(ptr, 0, SEEK_END);
//    fwrite(&c, sizeof(char), 0,ptr);
//    char con[10000];
//    if (ptr !=NULL) {
//        while(fgets(con, 10000, ptr)){
//            printf("%s ",con);}
//    }
//    else{
//        printf("file cannot be opened...");
//    }
    scanf("%c",&c);
    fseek(ptr, 1, SEEK_END);
    fwrite(&c, sizeof(char), 1, ptr);
    
    fclose(ptr);
    
}
