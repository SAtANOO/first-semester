//
//  main.c
//  p10E4real
//
//  Created by Ashish Acharya on 08/01/2024.
//

#include <stdio.h>
#include <math.h>
typedef enum classificao
{
    dis,
    pre,
    area
}classificao;

typedef struct{
    double x;
    double y;
}Point;

typedef struct{
     Point A;
     Point B;
     Point C;
    
}Triangle;

double distance(Point a , Point b){
    return sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2));
}
double perimeter(Triangle T){
    return distance(T.A, T.B)+distance(T.B, T.C)+ distance(T.C, T.A);
}

//Point Ask_point(char *s){ // asking the points..
////    Point P;
////    printf("%s[x,y]:",s);
////    scanf("[%d,%d]",&P.x ,& P.y);
////    return P;
////}

double Area(Triangle T){
    double s = perimeter(T)/2;
    return (s*(s-distance(T.A, T.B))
            *(s-distance(T.B, T.C))*(s-distance(T.C, T.A)));
}


int main() {
//    Triangle T;
//    T.A= Ask_point("A");
//    T.B=Ask_point("B");
//    T.C = Ask_point("C");
//    printf("Perimeter = %2f\n",perimeter(T));
//    printf("Area = %2f\n",Area(T));
    Triangle ABC;
    
    printf("Enter the coordenada for points A B C :>");
    scanf("%lf,%lf %lf,%lf %lf,%lf ", &ABC.A.x,&ABC.A.y,&ABC.B.x,&ABC.B.y,&ABC.C.x,&ABC.C.y);
    double dis=distance(ABC.A, ABC.B);
    printf("\n Distance :> %lf ", distance(ABC.A, ABC.B));
    printf("perimeter: %lf ",perimeter(ABC));
    return 0;
}
