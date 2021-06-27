#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct Node{
    int ver;     //connected vertex.
    int weight;  //the edge value.
    int low;     //(for biconnected detection)the value 'low'
    int dfn;     //(for biconnected detection)the sequence that DFS run through
    Node* parent;  //the node's parent(DFS/BFS)
    Node* next;  //has next vertex connect.
    Node(){ver=0;weight=0;low=0;dfn=0; next=NULL;parent=NULL;}
};

class Graph{
    private:
        //Node** vertexList;  //vertex itself has no value.
        int num_vertex;
        int num_edge;
        void DFS(int,bool*,int&);  //internal DFS sort(dfn,low).
        void BFS(stack<Node*>,bool*,int&);
        //Use for DFS
        //Node* inverseVertexList;  //for digraph only
    public:
        Node** vertexList;

        Graph(int,int);      //bool weight? digraph? ... default is weight no direct graph
        void DFS_Sort(int);   //input root vertex.
        void insert();
        void BFS_Sort(int);

};
/*
void Graph::BFS_Sort(int root){
    int temp_bfn=1;
    stack<Node*> s;
    bool* visited = new bool[num_vertex];
    for(int i=0;i<num_vertex;i++){visited[i]=false;}
    this->BFS(s,visited,temp_bfn);
}

void Graph::BFS(stack<Node*> s,bool* visited,int& temp_bfn){


}
*/
void Graph::DFS_Sort(int root){
    int temp_dfn=1;
    bool* visited = new bool[num_vertex];
    for(int i=0;i<num_vertex;i++){visited[i]=false;}
    this->DFS(root,visited,temp_dfn);

}

Graph::Graph(int ver,int edg){
    vertexList = new Node*[ver];
    num_vertex=ver;
    num_edge = edg;
    for(int i=0;i<ver;i++){vertexList[i] = new Node; vertexList[i]->low=100000;}
    for(int i=0;i<edg;i++){
        this->insert();
    }
}

void Graph::insert(){       //for insert edge only!
    int tempEdgeStart,tempEdgeEnd,tempWeight;
    cin>>tempEdgeStart>>tempEdgeEnd>>tempWeight;
    //-----------------------Start->End------------------------------
    Node* current = vertexList[tempEdgeStart];
    while(current->next!=0){
        current=current->next;
    }
    current->next = new Node;
    current->next->ver=tempEdgeEnd;
    current->next->weight=tempWeight;
    //-----------------------End->Start------------------------------
    current = vertexList[tempEdgeEnd];
    while(current->next!=0){
        current=current->next;
    }
    current->next = new Node;
    current->next->ver=tempEdgeStart;
    current->next->weight=tempWeight;
    //-----------------------------------------------------
}

void Graph::DFS(int current_ver,bool* visited,int& dfn){
    //DFS_sequence[dfn++]=current_ver;
    vertexList[current_ver]->dfn=dfn;
    vertexList[current_ver]->low=dfn;
    Node* currentList = vertexList[current_ver];
    visited[current_ver]=true;
    while(currentList->next != 0){
        currentList = currentList->next;
        if(vertexList[currentList->ver]->dfn==0){
            vertexList[currentList->ver]->parent = vertexList[current_ver];
            DFS(currentList->ver,visited,++dfn);
            vertexList[current_ver]->low = min(vertexList[current_ver]->low,vertexList[currentList->ver]->low);
        }
        else if(vertexList[currentList->ver]->dfn!=0){ //visited
            if(vertexList[current_ver]->parent!=vertexList[currentList->ver]){       //if the node's parent isn't the connecting node->back edge
                vertexList[current_ver]->low = min(vertexList[current_ver]->low,vertexList[currentList->ver]->dfn);
            }
        }
    }
}
