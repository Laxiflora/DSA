#include <iostream>
#include <cstdlib>
using namespace std;

struct record{
	int remain[100];
	int top=2;
};

elu(int a,int b,record r){
	r.remain[r.top++]=a%b;
	if((a%b)==0) return b;
	else elu(b,(a%b),r);
} 



int main(void){
	int a,b;
	record r;
	cin>>a>>b;
	a=a>b?a:b;
	b=a>b?b:a;
	r.remain[0]=a;
	r.remain[1]=b;
	int ans=elu(a,b,r);
	cout<<ans;
	return 0;
}
