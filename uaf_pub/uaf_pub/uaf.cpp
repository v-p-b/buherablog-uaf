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
	int num0;
	int num;
	cout << "Number of initial allocations: ";
	cin >> num0;
	A **arr0=(A**)malloc(sizeof(A*)*num0);

	for(int i=0;i<num0;i++){
		arr0[i]=new A();
		//printf("tmp%d at %p\n",i,arr0[i]);
	} 
	
	A *a=new A();
	
	a->vF1();
	
	int size=sizeof(A);
	
	printf("Address of a: %p - Size: %d \n",a,size);
	cout << "Number of frees: ";
	cin >> num;

	for(int i=0;i<num0 || i<num;i++){
		free(arr0[i]);
		//printf("tmp%d freed\n",i);
	}

	free(a);
	cout << "a freed" << endl;

	
	cout << "Number of allocations: ";
	cin >> num;
	void **arr=(void**)malloc(size*num);
	for(int i=0;i<num;i++){
		arr[i]=malloc(size);
		memset(arr[i],0x41,size);
		printf("%d. item allocated to: %p \n",i,arr[i]);
		
		if (arr[i]==a){
			cout << "Memory reallocated! " << endl;
			return 1;
		}
	}

	a->vF1();

	return 0;
}
