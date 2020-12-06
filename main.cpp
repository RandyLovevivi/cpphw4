#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    matrix m1(2,2,3);
    matrix m2(2,2,3);
    matrix m3(2,2,5);
    cout<<"m1: "<<endl<<m1<<"m2: "<<endl<<m2<<"m3: "<<endl<<m3;
    m1.setmember(0,0,0);
    cout<<"m1: "<<endl<<m1;
    m1.setmember(0,0,3);
    cout<<"m1+m2: "<<endl<<m1+m2<<"m1-m2: "<<endl<<m1-m2;
    m1*3;
    cout<<"m1: "<<endl<<m1;
    3*m1;
    cout<<"m1: "<<endl<<m1;
    cout<<"m2: "<<endl<<m2;
    cout<<"m1*m2: "<<endl<<m1*m2;
    m1=m3;
    cout<<"m1: "<<endl<<m1;
}
