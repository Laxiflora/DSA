#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
/*int horner(int array[],int n){
	static int num=1;
	if(n==0){
		return num*array[num-1]
	}
	return horner(array,--n);
}*/
void horner(int array[],int& ans,int n,int num,const int x){
	if(n>=0){
		ans+=pow(x,num)*array[n];
		cout<<"��"<<num<<"�����j�Anum="<<num<<",array[]="<<array[n]<<",n="<<n<<",ans="<<ans<<endl;
		horner(array,ans,--n,++num,x);
	}
}


int main(void){
	int n,x;
	cout<<"��J�����:";
	cin>>n;
	int arr[n+1];  //�x�s�h��������
	for(int i=0;i<=n;i++){
		cout<<"\n"<<"��J��"<<n-i<<"����:"; 
		cin>>arr[i]; //����Ѥj��p 
	}
	cout<<endl<<"�п�Jx���h��:";
	cin>>x;
	//int ans=horner(arr,n-1);
	int ans=arr[n];
	horner(arr,ans,n-1,1,x); //�q2�����}�l 
	cout<<ans<<endl;
	return 0;
}
