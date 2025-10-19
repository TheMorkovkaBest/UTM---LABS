#include <stdio.h>

void main() {
    float a,b,c,result,Xnach,Xcon;
    printf("введите a:");
    scanf("%f",&a);
    printf("введите b:");
    scanf("%f",&b);
    printf("введите c:");
    scanf("%f",&c);
    printf("введите Xnach:");
    scanf("%f",&Xnach);
    printf("введите Xcon:");
    scanf("%f",&Xcon);
    for (int x=Xnach; x<=Xcon; x++) {
        if (x<3 && b!=0) result = a*x*x-b*x+c;
        else if (x>3 && b==0 && (x-c)) result = (x-a)/(x-c);
        else if (c==0 || (x-c)==0) {printf("† вы согрешили перед математикой †""\n");continue;}
        else result = x/c;
        if (c!=0 || (x-c)!=0) printf("x= ""%i""\t""\t""|""\t""   F=""%.3f\n",x,result);
    }
}