#include <iostream>
#include <cstdlib>
using namespace std;

void swap(string& a,const int k,const int i){
	cout<<"swap called k="<<k<<" i="<<i<<" a="<<a<<endl;
	char temp=a[k];
	a[k]=a[i];
	a[i]=temp;
	cout<<"swap terminated a="<<a<<endl<<endl;
}
void permutations(string a,int k,int m){
	cout<<"Recursive: k="<<k<<" m="<<m<<" a="<<a<<endl<<endl;
	if(k==m){
		for(int i=0;i<=m;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	else{
		for(int i=k;i<=m;i++){
		//	cout<<k<<" "<<i<<endl;
			swap(a,k,i);
		//	swap(a[k],a[i]);
			permutations(a,k+1,m);
		//	swap(a[k],a[i]);
			swap(a,k,i);
		}
	}
}

int main(void){
	string a="abcde";
	permutations(a,2,4);
	return 0;
} 
