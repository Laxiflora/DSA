#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int KMP(string P,string S,int* fail){
	int pPos=0,sPos=0;
	while(pPos<P.length() && sPos<S.length()){
		cout<<"Start matching... jsPos = "<<sPos<<" , pPos = "<<pPos<<endl;
		if(S[sPos]==P[pPos]){
			pPos++; sPos++;
		}
		else if(pPos==0){
			sPos++;
		}
		else{
			pPos = fail[pPos-1]+1;              //失敗就往該字f函數的下一個字母比對 
			cout<<"Not match , sPos = "<<sPos<<" , pPos = "<<pPos<<endl; 
		}  //NO need to reset sPos , fail function already calculated the repeated alphabet  
		
	}
	if(pPos < P.length()) return -1;
	else return sPos - P.length() + 1;
}

void makeFail(string P,int* fail){
	fail[0]=-1;
	int cur_f=0;
	int start;
	for(start=1;P[start]!=P[0] && start<P.length();start++){
		fail[start]=-1;
	}
	start--;  //!!
	for(;start<P.length();start++){
		if(P[start]==P[cur_f]){
			fail[start]=cur_f++;
		}
		else{
			cur_f=0;
			fail[start]=-1;
		}
	}
	for(int j=0;j<start;j++){
		cout<<fail[j]<<" ";
	}
}


int main(void){
	string S;
	string P;
	cin>>S;
	cin>>P;
	int fail[P.length()]={-1};
	makeFail(P,fail);
	/*for(int i=0;i<P.length();i++){
		cout<<fail[i]<<"\n";
	}*/
	int ans=KMP(P,S,fail);
	cout<<ans;
	
	return 0;
}

//S = abcsdirodkwfisdkv
//Pat = sdirod

//S = dueduedueoeiowieduedueoeienexeandsdufufdueoeienexeandsjdklsk
//Pat = duedueoeienexeands
