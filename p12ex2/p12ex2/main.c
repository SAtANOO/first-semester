//
//  main.c
//  p12ex2
//
//  Created by Ashish Acharya on 08/01/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if (argc<2) {
        printf("Syntax Error \n");
        return -1;
    }
    int i;
    double max , min;
    max = min =atof(argv[i]);
    for (i=2; i<argc; i++) {
        double num = atof(argv[i]);
        if (max<num)
            max=num;
        if (min>num)
            min=num;
        
    }
    printf("min: %lf , max : %lf , count = %d \n ", min , max , argc-1);
}
