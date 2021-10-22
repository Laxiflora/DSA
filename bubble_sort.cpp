#include <iostream>
#include <cstdlib>
using namespace std;

void bubbleSort(int* data , int n){
    while(true){ // compare n-1 times at most
        bool flag = false;
        for(int i=0;i<n-1;i++){   //yield a mininum value per loop
            if(data[i]<data[i+1]){
                int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

int main(void){
    int n;
    cin>>n;
    int* data = new int[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }

    bubbleSort(data,n);
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
}