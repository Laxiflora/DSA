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
		cout<<"第"<<num<<"次遞迴，num="<<num<<",array[]="<<array[n]<<",n="<<n<<",ans="<<ans<<endl;
		horner(array,ans,--n,++num,x);
	}
}


int main(void){
	int n,x;
	cout<<"輸入次方數:";
	cin>>n;
	int arr[n+1];  //儲存多項式項數
	for(int i=0;i<=n;i++){
		cout<<"\n"<<"輸入第"<<n-i<<"次項:"; 
		cin>>arr[i]; //次方由大到小 
	}
	cout<<endl<<"請輸入x為多少:";
	cin>>x;
	//int ans=horner(arr,n-1);
	int ans=arr[n];
	horner(arr,ans,n-1,1,x); //從2次項開始 
	cout<<ans<<endl;
	return 0;
}
