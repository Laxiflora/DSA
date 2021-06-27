#include <iostream>
#include <cstdlib>
using namespace std;
/*
15
6 4 9 8 2 11 23 17 59 48 37 24 18 19 21
*/
int Partition(int* subarray, int first,int last){
    int pivot = last;
    int store = first;
    //cout<<"Pivot = "<<subarray[pivot]<<" Start from:"<<subarray[store]<<endl;
    for(int i=first;i<last;i++){
        if(subarray[i]<=subarray[pivot]){
            int temp=subarray[i];
            subarray[i]=subarray[store];
            subarray[store]=temp;
            store++;
        }
    }
    int temp=subarray[pivot];
    subarray[pivot]=subarray[store];
    subarray[store]=temp;
    return store;
}

void QuickSort(int* subarray,int first,int last){
    if(first<last){
        int mid=Partition(subarray,first,last);
        QuickSort(subarray,mid+1,last);
        QuickSort(subarray,first,mid-1);
    }
}

int main(void){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    QuickSort(array,0,n-1);
    for(int i =0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
