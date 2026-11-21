#include <iostream>
using namespace std;

/****************************************************************/
long long absolute(long long x) {return (x<0)?-x:x;}

long long gcd(long long a,long long b){      //최대공약수 구하는 함수
    if(b==0) return a;
    else return gcd(b,a%b);
}
/****************************************************************/
class Fraction{
private:
    long long num,den; //num 분자, den 분모
    void reduce(){
        long long gcd_result=(absolute(num)>=absolute(den))
                            ? gcd(absolute(num),absolute(den))
                            : gcd(absolute(den),absolute(num));
        num/=gcd_result; den/=gcd_result; // 같은 수로 나눔

        if(den<0){num*=-1; den*=-1;}
    }
public:
    Fraction(long long num, long long den);
    void set(Fraction source);
    Fraction add(Fraction other);
    Fraction mul(Fraction other);
    void print();
};

Fraction::Fraction(long long num, long long den){
    this->num=num; this->den=den;
    reduce();
}

void Fraction::set(Fraction source){
    this->num=source.num; this->den=source.den;
}

Fraction Fraction::add(Fraction other){
    long long new_num=(num*other.den)+(den*other.num);
    long long new_den=den*other.den;

    Fraction result(new_num,new_den);
    return result;
}

Fraction Fraction::mul(Fraction other){
    long long new_num=num*other.num;
    long long new_den=den*other.den;

    Fraction result(new_num,new_den);
    return result;
}

void Fraction::print(){
    if(den==1) cout<<num;
    else cout<<num<<"/"<<den;
}
/****************************************************************/
int main(){
    cout<<"N을 입력하세요(40 이하 자연수): ";
    int n;
    cin>>n;

    Fraction out1(0,1);
    for(int i=1;i<=n;i++){
        Fraction temp(1,i);
        out1.set(out1.add(temp));
    }
    cout<<"(1) : "; out1.print(); cout<<endl;

    Fraction out2(1,1);
    for(int i=1;i<=n;i++){
        Fraction temp(i+1,i);
        out2.set(out2.mul(temp));
    }
    cout<<"(2) : "; out2.print(); cout<<endl;
}
