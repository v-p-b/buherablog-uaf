#include<iostream>

using namespace std;

class A{
public: 
    void __construct__(){}
    virtual int vF1(){
        cout << "A::vF1" << endl;
        return 1; 
    }

    void doSomething(){
		cout << "A did something" << endl;
        return;
    }
};

class B: public A{
public:
    void __construct__(){}
    virtual int vF1(){
        cout << "B::vF1" << endl;
        return 2; 
    }
    virtual int vF2(){
        cout << "B::vF2" << endl;
        return 2; 
    }

	void doSomething(){
		cout << "B did something" << endl;
        return;
    }
};

int main(){
    A *arr[10];

	for (int i=0;i<10;i++){
		if (i%2==0){
			arr[i]=new A();
		}else{
			arr[i]=new B();
		}
	}

	for (int i=0;i<10;i++){
		arr[i]->vF1();
		arr[i]->doSomething();
	}

    return 0;
}
