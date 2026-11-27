#include <iostream>
using namespace std;

class MyVector{
    int *p;
    int size;
public:
    MyVector(int n=100){
        p=new int[n];
        size=n;
    }
    ~MyVector(){delete [] p;}
};

void fillLine(int n=25,char c='*'){
    for(int i=0;i<n;i++) cout<<c;
    cout<<endl;
}

int main(){
    fillLine();
    fillLine(10,'%');

    MyVector *v1,*v2;
    v1=new MyVector();
    v2=new MyVector(1024);
    delete v1;
    delete v2;
}