#include <stdio.h>

int main(void){
    for (int i=1;i<=32;i++){
        for (int j=0;j<i;j++){
            for (int k=0;k<i;k++){
                if ((j==0||j==i-1)||(k==0||k==i-1)||(i%2==0)) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
}