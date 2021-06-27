#include "P334Graph_LinkList.h"
using namespace std;

int main(void){
    Graph alpha(10,11);
    alpha.DFS_Sort(3);
    for(int i=0;i<10;i++){
        cout<<alpha.vertexList[i]->low<<" "<<alpha.vertexList[i]->dfn<<endl;
    }
   // alpha.Showbiconnect();

}

/*
10 11
0 1 1
1 2 1
2 4 1
4 3 1
1 3 1
3 5 1
5 6 1
5 7 1
6 7 1
7 8 1
7 9 1
*/
