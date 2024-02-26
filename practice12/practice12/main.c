//
//  main.c
//  practice12
//
//  Created by Ashish Acharya on 08/01/2024.
//

#include <stdio.h>  //creaating the command line program..
#include<stdlib.h>

void main(int argc, char * argv[]) {
    int result;
    if (argc!=4) {
        printf("Syntax Error!!");
        return;
    }
    int n1 = atoi(argv[1]);
    char *op = argv[2];
    int n2 = atoi(argv[3]);
    switch (*op) {
        case '+':
           result = n1+n2;
            break;
        case '-':
           result = n1-n2;
            break;
        case '*':
            result = n1*n2;
            break;
        case '/':
            if (n2==0) {
                printf("Error cannot divide by zero\n");
                return;
            }
            else
            result= n1/n2;
            break;
        default:
            printf("Error select the valid data..");
            break;
    }
    printf("the value is %d %s %d = %d\n",n1, op , n2 ,result);
    
}
