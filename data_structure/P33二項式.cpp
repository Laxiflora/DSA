#include <iostream>
#include <cstdlib>
using namespace std;

double fac(int n){
	if (n == 0 || n == 1) 
        return 1;
    else
        return n*fac(n-1);
}


int main(void){
	int n,m;
	double ans=0;
	cin>>n>>m;  //Cn¨úm
	if(m>n)
		cout<<"¿ù»~,Error:"<<ans;
	else{
		double kid=fac(n);
		double mom_1=fac(n-m);
		double mom_2=fac(m);
		ans=kid/(mom_1*mom_2);
		
	}
	cout<<ans;
}
