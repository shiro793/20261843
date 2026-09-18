#include <stdio.h>

int main(void){
    float c=300000.0; //km/s 단위
    float distance=149600000.0; //km 단위
    float time=distance/c; //초 단위

    printf("빛의 속도는 %fkm/s\n태양과 지구 사이의 거리는 약 %fkm\n도달 시간은 %f초",c,distance,time);
    
    return 0;
}
