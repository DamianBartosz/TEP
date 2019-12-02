#include <iostream>

using namespace std;

void double_1(int *p){
    *p *=2;
}

int double_2(int p){
    return p*2;
}

int main() {
    int p1 = 2;
    int *p2 = 0;
    *p2 = 3;

    cout<<double_2(p1)<<endl;
    double_1(&p1);
    cout<<p1<<endl;
    cout<<double_2(*p2)<<endl;
    double_1(p2);
    cout<<p2<<endl;
    return 0;
}