#include <iostream>
#include <cstdlib>
using namespace std;

/*
5
4 2 
5 1
6 4
6 8
9 8

assume the array is sorted!
*/
struct Node{
    int x,y;
};

void Convex(Node* subgraph,int first,int last){
    int mid = (first+last)/2;
    if(first<last){ Convex(subgraph,first,mid);  Convex(subgraph,mid+1,last); }



}
int main(void){
    int n;
    cin>>n;
    Node graph[n];
    for(int i =0;i<n;i++){
        cin>>graph[i].x>>graph[i].y;
    }
    Convex(graph,0,n-1);
    for(int i=0;i<n;i++){
        cout<<"("<<graph[i].x<<","<<graph[i].y<<") ";
    }
    return 0;
}
