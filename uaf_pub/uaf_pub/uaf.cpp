#include<iostream>

using namespace std;

class A{
public: 
    void __construct__(){}

    virtual int vF1(){
        cout << "A::vF1" << endl;
        return 1; 
    }
};

int main(){
    A *a=new A();
    a->vF1();
    free(a);
    cout << "a freed" << endl;
    a->vF1();
    return 0;
}
