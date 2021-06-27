#include <iostream>
#include <cstdlib>
#define INPUT 10000
using namespace std;

int DP[INPUT][INPUT];

int ack(int m,int n){
	cout<<"m= "<<m<<" n= "<<n<<endl;
	if(m==0) return n+1;
	if(n==0) return ack(m-1,1);
	DP[m][n]=ack(m-1,ack(m,n-1));
	if(DP[m][n]!=0){
		cout<<"DPn_ed\n";
		return DP[m][n];
	}
}


int main(void){
	int m,n;
	cin>>m>>n;
	ack(m,n);
	cout<<DP[m][n];
}
