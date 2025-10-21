#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c){printf("not triangle\n");return 0;}
    if(a==b && b==c){printf("equilateral triangle\n");return 0;}
    if(a*a+b*b==c*c){printf("right triangle\n");return 0;}
    if(a*a+b*b<c*c){printf("obtuse");}
    else{printf("acute");}
    if(a==b || b==c){printf(" isosceles");}
    printf(" triangle\n");
    return 0;
}