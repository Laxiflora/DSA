/***
data[0] = trash , for stopping backward
data size = n+1 for n inputs
insert_sort iterates input data from data[1] to data[n] , insert them iteratively
insert needs to move array elements anytime they fail to insert data
worst time : O(n^2) , best time : O(n)  , space : O(1)
***/
#include <iostream>
#include <cstdlib>
using namespace std;

void insert(int* data , int input , int i){
    int j=i;
    while(data[j]>input){
        data[j+1] = data[j];
        j--;
    }
    data[j+1] = input;
}


void insert_sort(int* data,int n){
    for(int i=1;i<=n;i++){
        data[0] = data[i];
        insert(data,data[i],i-1);
    }
}


int main(void){
    int n;
    cin>>n;
    int* data = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>data[i];
    }
    insert_sort(data,n);
    for(int i=1;i<=n;i++){
        cout<<data[i]<<" ";
    }
}
