#include <stdio.h>

void selection_sort(int a[],int n){
    for (int i=0;i<n;i++){
        int least=i;
        for (int j=i;j<n;j++){
            if (a[j]<a[least]) least=j;
        } 
        
        int temp=a[i]; //포인터 못하겠어요
        a[i]=a[least];
        a[least]=temp;
    }
}

int binary_search(const int a[], int n, int key){
    int low=0, high=n-1;
    while (low<=high){
        int mid=(high+low)/2;
        if (a[mid]==key) return mid;
        if (a[mid]>key) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(void){
    int scores[5]={};
    int search;

    printf("점수 입력>>> ");
    scanf("%d %d %d %d %d",&scores[0],&scores[1],&scores[2],&scores[3],&scores[4]);

    printf("찾을 점수 입력>>> ");
    scanf("%d",&search);

    selection_sort(scores,5);

    for (int i=0;i<5;i++){printf("%d ",scores[i]);}
    printf("\n%d",binary_search(scores,5,search));

    return 0;
}
