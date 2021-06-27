/*巢狀: 
	print();
	for(int i=1;i<=項數;i++){
		for(int j=i;j>0;j--){
			swap(array[j-1]);  //0轉1 1轉0 
			print();
		}
	}
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void print(int array[],const int len){
	for(int i=0;i<len;i++){
			switch(array[i]){
				case 1: {
					cout<<"T";
					break;
				}
				case 0:{
					cout<<"F";
					break;
				} 
				default: cout<<"Error!";
			}
		}
	cout<<"\n";	
}

void swap(int array[],int j){
	if(array[j]==1)
		array[j]=0;
	else array[j]=1;
}


int truth_table(int array[],int n,const int len,int& num){
	if(n!=0){
		truth_table(array,n-1,len,num);
		swap(array,n-1);
		truth_table(array,n-1,len,num);
	}
	else{
		num++;
		print(array,len);
	}
}

int main(void){
	int n,num=0;
	cin>>n;
	int array[n]={1};
	truth_table(array,n,n,num);
	cout<<"共"<<num<<"個可能\n";
	return 0;
}
