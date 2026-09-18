#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void){
    double w,h,area,perimeter; //w=가로,h=세로

    printf("사각형의 넓이와 둘레를 구하기 위해 정수 2개 입력\n(\"A B\" 형식) >>> ");
    scanf("%lf %lf",&w,&h);
    area = w * h;
    perimeter = 2 * (w + h);

    printf("사각형의 넓이: %lf\n사각형의 둘레: %lf\n",area,perimeter);

    return 0;
}