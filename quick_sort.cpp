#include <iostream>
#include <cstdlib>
using namespace std;


void swap(int& alpha,int& beta){
    int temp = alpha;
    alpha = beta;
    beta = temp;
}

int part(int* data, int low, int high){
    int pivot = data[low];  //leftist data
//    cout<<low<<" "<<high<<" "<<pivot<<endl;
    int i = high+1;
    for(int j=high;j>low;j--){
        if(data[j]>pivot){
            i--;
            swap(data[i],data[j]);
        }
    }
    i--;
    swap(data[i],data[low]);
    return i;
}


void quickSort(int* data , int low , int high){
    if(low<high){
        int flag = part(data,low,high);
        for(int i=0;i<5;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        quickSort(data,low,flag-1);
        quickSort(data,flag+1,high);
    }
}


int main(void){
    int n;
    cin>>n;
    int* data = new int[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    quickSort(data,0,n-1);
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }


}