#include <stdio.h>
#include <math.h>

int ceiler(float angle){
    if (ceil(angle)==floor(angle)) return (int)ceil(angle)+1;
    else return (int)ceil(angle);
}

int main(void){
    int x_from,y_from,x_to,y_to;
    const double pi=3.14159265358979323846;

    printf("공의 좌표를 입력하세요: ");
    scanf("%d %d",&x_from,&y_from);

    printf("목표지점의 좌표를 입력하세요: ");
    scanf("%d %d",&x_to,&y_to);

    int dx=x_to-x_from; //x좌표 이동거리
    int dy=y_to-y_from; //y좌표 이동거리

    float angle=atan2(dy,dx)*(180/pi);
    if (angle<0) angle+=360.0;

    //printf("%f\n",angle);
    printf("목표: %d-%d도 사이",(int)floor(angle),ceiler(angle));
}