#include <iostream>
#include <cstdlib>
#ifndef TYPE_NAME
	#define TYPE 4
	#define TYPE_NAME int
#endif	
using namespace std;

class CppArray{
	private:
		TYPE_NAME* arg_zero;
		TYPE_NAME* current;
		int size;
	public:
		CppArray(int siz){
			cout<<"Switch on the power line, remember to put on protection.\n";
			arg_zero=new TYPE_NAME;
			current=arg_zero;
			size=siz;
			for(int i=0;i<size;i++){
				*current=i;
				current+=TYPE;
			}
			cout<<"Object creation complete. Let's begin the simulation.\n";
		}
	
	 	/*TYPE_NAME* operator[](int i){                         //l-value
			if(i>=size){
				cout<<"Error! Argument not exist. Programmer is always right.";
			}
			else{
				current=(arg_zero+i*TYPE);
			}
			return current;
		}*/
		
		
		TYPE_NAME operator[](int i)const{                         //r-value
			if(i>=size){
				cout<<"Error! Argument not exist. Programmer is always right.";
				return -1;
			}
			else{
				return *(arg_zero+i*TYPE);
			}
		}
	
	CppArray& operator[](int i){                                 //l-value operator <<
		if(i>=this->size){
			cout<<"Error! Argument not exist. Programmer is always right.";
		}
		else{
			this->current=(arg_zero+i*TYPE);
		}
		return *(this);
	}
	
	CppArray& operator=(CppArray& a){
		*(this->current)=*a.current;
	}
	
	friend ostream& operator<<(ostream& os,CppArray& a){
		cout<<*(a.current)<<endl;
		
		return os;
	}
	
	friend istream& operator>>(istream& os,CppArray& a){
		int temp;
		cin>>temp;
		*(a.current)=temp;
		return os;
	}
	
	
};



int main(void){
	CppArray a1(6),a2(10);
	cin>>a1[5];
	cout<<a1[5];
	//a1[2]=a2[7];
	cout<<a1[2];
	return 0;
}
