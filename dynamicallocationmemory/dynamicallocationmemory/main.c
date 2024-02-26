//
//  main.c
//  dynamicallocationmemory
//
//  Created by Ashish Acharya on 04/01/2024.
//

#include <stdio.h>
#include <stdlib.h>
double average(double *values , int q){ // to count the average of the varrable..
//    double average =0; // firstly inatilize the average by vlue 0 then it accepts the values further..
    double *ptr=values;// ptr points to the pointer to values..
//    for (ptr=values; ptr<values+q; ptr++) {
//        average+=*ptr++/q;
//    }
//   //    the above is same as...
    double sum=0; // inatilize the sum to 0...
    while (ptr<values+q) {
        sum= sum+(*ptr);
        ptr++;
    }
  return sum/q;
    
    
}

int main() {
    double *values=malloc(5*sizeof(double)); // malloc returns the values of pointer to something.. it was located for first five values
    int count =0;
    while (1) {
        if (count!=0 && count%5==0){
            int new_size=count+5;
            values=realloc(values, new_size*sizeof(double));// the input value after 5 is reallocates over here.. 
        }
        printf("#value %d :",count+1);
        if (scanf("%lf",values+count) !=1) break;
        
        count++;
    }
    printf("# media = %.2f \n",average(values, count));
    
   
}
