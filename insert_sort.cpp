#include <iostream>
#include <cstdlib>
using namespace std;

void insert_sort_iterative(int* data,int n){
    
}



int main(void){
    int n;
    cin>>n;
    int* data = new int[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }

    insert_sort_iterative(data,n);
}