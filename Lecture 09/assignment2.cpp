#include <iostream>
using namespace std;

/****************************************************************/
class Circle{
    int radius;
public:
    Circle(){radius=1;}
    ~Circle(){}
    void setRadius(int r){radius=r;}
    double getArea(){return 3.14*radius*radius;}
};
/****************************************************************/
class CircleManager{
    Circle* pArray=NULL; //동적생성된 배열주소
    int size=0; //동적생성된 배열크기
    void input(); //각 서클에 반지름 입력
    void decide(); //100<면적<200인 서클 객체 서치,출력
public:
    CircleManager() {}
    ~CircleManager() {}
    void run(); //서클 배열 관리 주함수
};

void CircleManager::input(){
    for(int i=0;i<size;i++){
        cout<<"Circle "<<i+1<<"의 반지름 입력(정수만)>> ";
        int r;
        cin>>r;

        pArray[i].setRadius(r);
    }
}

void CircleManager::decide(){
    for (int i=0;i<size;i++){
        if (pArray[i].getArea()>=100 && pArray[i].getArea()<=200){
            cout<<"Circle "<<i+1<<"의 면적은 "<<pArray[i].getArea()<<endl;
        }
    }
}

void CircleManager::run(){
    cout<<"Circle 개수 입력 >> "; //원 개수 입력받고, 그만큼 배열 동적 할당
    cin>>size;
    pArray=new Circle[size];
    input(); //반지름 각각 저장
    decide(); //조건 맞는 면적의 원 서치 및 출력
    delete [] pArray; //동적 배열 반환
}
/****************************************************************/
int main(){
    CircleManager* pMan=new CircleManager;
    pMan->run();
    delete pMan;
}
