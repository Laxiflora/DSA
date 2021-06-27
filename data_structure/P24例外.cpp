#include <iostream>
#include <cstdlib>
using namespace std;

int DivZero(int a,int b,int c){
	if(a<0&&b<0&&c<0){
		throw 1;
	}
	else if(a==0 && b==0 && c==0){
		throw 2;
	}
	return a+b*c+b/c; 
} 

//若沒有catch，顯示terminate called after throwing an instance of 'int'
int main(void){
	try{cout<<DivZero(0,0,0)<<"\n";}
	catch(int e){
		cout<<"Wrong input!"<<"\n";
		cout<<"Error Code:"<<e;
	}
	return 0;
}
