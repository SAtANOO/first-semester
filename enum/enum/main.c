//
//  main.c
//  enum
//
//  Created by Ashish Acharya on 06/01/2024.
//

#include <stdio.h>
typedef enum color{ // user defined datatype consists of integral constant..
black,
    white,
    grey,
    green
};
// if we use enum instead of int and string char* we increase compile time checking and avoid errors from passing in invalid constant..
void printcolor(enum color chooseColor){
    char * color_name= "invalid color";
    switch (chooseColor) {
        case black:
            color_name="black";
            break;
        case white:
            color_name="white";
            break;
        case grey:
            color_name="grey";
            break;
        case green:
            color_name="green";
        default:
            break;
    }
    printf("%s\n",color_name);
    
}
// used designited initializer..
 
typedef enum{
    MON, TUE, WED, THU, FRI,SAT, SUN
}days;

char * DOW[]={  // DOW = days of weeks..
    [MON]="mon",[TUE]="tue",[WED]="wed",[THU]="thu",[FRI]="fri",[SAT]="sat",[SUN]="sun"
};
void printDOW(days weekd){
    printf("%s\n", DOW[weekd]);
    
};
int main(){
    enum color choosenumber;
    printf("enter the number between 0 - 3 to choose the color:");
    scanf("%d",&choosenumber);
    printcolor(choosenumber);
    printDOW(choosenumber);
    return 0;
    
}
