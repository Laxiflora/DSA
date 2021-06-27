#include <iostream>
#include <cstdlib>
using namespace std;

int KMP(string alpha,string beta,int* error){
	int j=0;
	if(alpha.length()<beta.length()) return -1;  //error
	
	for(int i=0;i<alpha.length();i++){
		if(alpha[i]==beta[j]) j++;    //compatible
		else j=error[j-1]+1;               //not compatible
		if(j==beta.length()){
			return i-j+1;                   //found
		} 
	}
	return -1;               //GG
}


void errorFunction(int* error,string beta){
	int curFail=1;
	bool first=true;
	error[0]=-1;
	for(int i=1;i<beta.length();i++){
		if(beta[i]!=beta[0]&&first){
			error[i]=-1;
			
		}
		else if(first&&beta[i]==beta[0]){
			error[i]=0;
			
		}
		else{
			if(beta[i]==beta[curFail]){error[i]=curFail++;}
			else{curFail=0; error[i]=-1;}
		}
	}
}


int main(void){
	string alpha,beta;
	cin>>alpha>>beta;
	int error[beta.length()];
	errorFunction(error,beta);
	int ans=KMP(alpha,beta,error);
	for(int i=0;i<beta.length();i++){
		cout<<error[i]<<" ";
	}
	cout<<endl<<ans;
}


//S = dueduedueoeiowieduedueoeienexeandsdufufdueoeienexeandsjdklsk
//Pat = duedueoeienexeands
