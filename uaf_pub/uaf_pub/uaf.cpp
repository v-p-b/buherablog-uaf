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
	A *a=new A();
	a->vF1();
	int size=sizeof(A);
	
	printf("Address of a: %p - Size: %d \n",a,size);
	free(a);

	void *p=malloc(size);
	printf("Address of p: %p - Size: %d \n",p,size);

	return 0;
}
