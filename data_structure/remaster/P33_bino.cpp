#include <iostream>
#include <cstdlib>
using namespace std;

int bio(int n,int m,int& k,int& l){
	k*=n;
	l*=m;
	if(m==1) return k/l;
	bio(n-1,m-1,k,l);
}


int main(void){
	int n,m,k=1,l=1;
	cin>>n>>m;	
	int ans=bio(n,m,k,l);
	cout<<ans;
}
