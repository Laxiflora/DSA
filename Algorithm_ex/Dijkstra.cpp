#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int vertex;   //next vertex
    Node* next;
    int weight;
    Node();
    Node(int,int);
};

Node::Node(int vertex,int weight){
    this->vertex = vertex;
    this->weight = weight;
    next = 0;
}

Node::Node(){
    vertex = 0;
    next =0;
    weight=0;
}

class Graph{
private:
    Node** vertex_list;
    int vertex_num,edge_num;
    int dij(int,int,int*);
public:
    int Dijkstra();
    void printGraph();
    Graph();
};

Graph::Graph(){
    int n,m;
    cout<<"Enter Node Number";
    cin>>n;
    cout<<"Enter Edge Number";
    cin>>m;
    vertex_num = n; edge_num = m;
    vertex_list = new Node*[n];
    for(int i=0;i<n;i++){       //initlization
        vertex_list[i] = new Node;
    }
    for(int i=0;i<m;i++){
        int temp,connect,weight;
        Node* current;
        cin>>temp>>connect>>weight;       //temp connect weight
        current = vertex_list[temp];
        while(current->next != 0){
            current=current->next;
        }
        current->next=new Node(connect,weight);
        current = vertex_list[connect];
        while(current->next !=0){
            current =current->next;
        }
        current ->next = new Node(temp,weight);
    }
}

void Graph::printGraph(){
    Node* current;
    for(int i=0;i<vertex_num;i++){
        cout<<"Vertex: "<<i<<": \n";
        current = vertex_list[i];
        while(current ->next !=0){
            current = current->next;
            cout<<"Connects:"<<current->vertex<<" ,weights:"<<current->weight<<"\n";
        }
    }
}
int Graph::Dijkstra(){
    int start,end;
    cin>>start>>end;
    bool check[vertex_num];
    int dis[vertex_num];
    for(int i=0;i<vertex_num;i++){check[i]=false; dis[i]=INT_MAX; } dis[start]=0;
    return dij(start,end,check,dis);
}
int Graph::dij(int start,int end,int* check,int* dis){



    //------------------
    cout<<"Start "<<start;
    int next=INT_MAX;
    if(start==end) return check[start];
    Node* current = new Node;
    current = vertex_list[start]->next;
    while(current!=0){
        check[current->vertex]=min(current->weight+check[start],check[current->vertex]);
        next = min(next,check[current->vertex]);
    }
    return dij(next,end,check);
    //--------------------------
}

int main(void){
    Graph alpha;
    alpha.printGraph();
    int ans = alpha.Dijkstra();
}


