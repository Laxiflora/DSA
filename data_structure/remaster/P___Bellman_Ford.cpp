#include <iostream>
#include <cstdlib>
using namespace std;
/*
struct Edge{
    //friend class Graph;
    int start,end;
    char token;
};
*/
class Graph{
    public:
        int BellMan_Ford(int,int);
        Graph(int,int);
        void PrintGraph();
    private:
      int** Adjscency_Matrix;
      int node_num;
      int edge_num;
};

void Graph::PrintGraph(){
    for(int i=0;i<node_num;i++){
        for(int j=0;j<node_num;j++){
            cout<<Adjscency_Matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

Graph::Graph(int n,int m){
    node_num=n;
    edge_num=m;
    //-----------initialize--------
    Adjscency_Matrix = new int* [n];
    for(int i=0;i<n;i++){
        Adjscency_Matrix[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Adjscency_Matrix[i][j]=-1;
        }
    }
    //-----------initialize;--------
    for(int i=0;i<m;i++){
        int start,end,weight;
        cin>>start>>end>>weight;
        Adjscency_Matrix[start][end] = weight;
        //for undirected graph
        Adjscency_Matrix[end][start] = weight;
        //
    }
}

int Graph::BellMan_Ford(int start,int end){  //O(k*n)
    int path[node_num];
    for(int i=0;i<node_num;i++){
        path[i]=100000;
    }
    path[start]=0;
    bool change = true;
    while(change){
        change = false;
        for(int i=0,j=start;i<node_num;i++,j=(j+1)%node_num){
            for(int k=0;k<node_num;k++){
                if(Adjscency_Matrix[k][j]!=-1){       //if to node k is accessable
                    if(path[j]+Adjscency_Matrix[k][start]<path[k]){
                        path[k] = path[j]+Adjscency_Matrix[k][start];
                        change=true;
                    }
                }
            }
        }
    }
    return path[end];
}


int main(void){
    int n,m;
    cout<<"Node Number:";
    cin>>n;
    cout<<"Enter Edge Number:";   //undirected graph
    cin>>m;
    Graph alpha(n,m);
    alpha.PrintGraph();
    int ans=alpha.BellMan_Ford(0,3);
    cout<<ans;
    return 0;
}

/*
4 4
0 1 8
0 2 1
0 3 5
3 2 0
*/
