/*
This is a sparse matric class with its implement where there exist 3 class.
1.Matrix - the main object which includes the operations and storage.
2.ElementNode:ChainNode<matrix data type> - the element node storage the position(row,col) , data(value) and pointer(down,right);

Caution: the implement is pretty ugly, which the downHead and rightHead is confused.
but the result is clear , though.

[i][k] : row i , col k , cin>>m>>n -> m*n array, m=row, n=col;
*/


#include <iostream>
#include <cstdlib>
#include "P180LinkedList.h"
using namespace std;
class Matrix;
/*
11
30 30
4 3 20
8 8 21
0 1 13
8 20 40
1 3 9
4 11 23
12 24 30
23 21 70
21 23 60
21 10 5
4 3 10

8
30 25
4 10 18
3 4 20
8 5 7
20 15 49
28 0 11
0 16 0
3 15 21
1 3 5

5
5 4
0 0 1
1 0 1
2 0 1
3 0 1
4 0 1

5
4 5
0 0 1
0 1 1
0 2 1
0 3 1
0 4 1

5
5 5
0 0 1
1 0 1
2 0 1
3 0 1
4 0 1

9
3 3
0 0 1
0 1 2
0 2 3
1 0 4
1 1 5
1 2 6
2 0 7
2 1 8
2 2 9


9
3 3
0 0 4
0 1 5
0 2 6
1 0 7
1 1 8
1 2 9
2 0 1
2 1 2
2 2 3

*/
//////////////////////////////////////////////////////////////
class ElementNode:ChainNode<int>{       //int data;
    //T data,ChainNode* next
    friend class Matrix;
    friend class HeadNode;
    private:
        int row,col;
        ElementNode* down;
        ElementNode* right;
    public:
        ElementNode();
        ElementNode(int,int,int);
};

ElementNode::ElementNode(int co,int ro,int dat){
    this->data=dat;
    this->col=co;
    this->row=ro;
    down = NULL;
    right= NULL;
    //down=new ElementNode;
    //right=new ElementNode;
}

ElementNode::ElementNode(){
    down = NULL;
    right=NULL;
    data=0;
}



/////////////////////////////////////////////////////

class Matrix{     //linker with H0
    private:
        int numRows,numCols,numNodes,m,n;
       ElementNode** rightHead;
       ElementNode** downHead;
    public:
        Matrix(int,int,int);
        Matrix();
        Matrix(int,int);         //create empty matrix;
        Matrix Multiply(Matrix);
        void Insert(int,int,int);
        void Output();
};

Matrix::Matrix(int m,int n){
    this->m = m;
    this->n=n;
    numRows=0;
    numCols=0;
    rightHead = new ElementNode* [m];
    downHead = new ElementNode* [n];
    for(int i=0;i<m;i++) rightHead[i]=new ElementNode;
    for(int i=0;i<n;i++) downHead[i]=new ElementNode;
}

Matrix Matrix::Multiply(Matrix beta){
    Matrix output(this->m,beta.n);
    if(this->n!=beta.m){
        cout<<"Matrix incompatible.\n";
        return output;
    }
    /*
        NEEDS IMPLEMENT;
    */
    for(int i=0;i<beta.m;i++){           //for 0 to alpha.col number(m)
        ElementNode* alphaTravel = beta.downHead[i];
        if(alphaTravel->right==NULL){continue;}       //if col[i]==Empty
        //ElementNode* alphaTravel = rightHead[i]->down;
        while(alphaTravel->right!=NULL){                  //while col[i] has more elements
            for(int j=0;j<this->n;j++){                      //for 0 to beta.row number(n)
                ElementNode* betaTravel = this->rightHead[j];
                if(betaTravel->down==NULL){continue;}         //if row[j]==Empty
                //ElementNode* betaTravel = beta.downHead[j]->right;
                while(betaTravel->down!=NULL){
                    if(betaTravel->down->col==alphaTravel->right->row){                   //if betaTravel->col == current col's row  CAUTION
                        output.Insert(i,j, (alphaTravel->right->data)* (betaTravel->down->data));
                        break; //found
                    }
                    betaTravel = betaTravel->down;
                }
            }
            alphaTravel = alphaTravel->right;
        }
    }
    return output;
}

void Matrix::Insert(int c,int r,int value){
    ElementNode* node = new ElementNode(c,r,value); //create node

//------------------FOR DOWNHEAD-------------------------------
	ElementNode* travel = downHead[c];        //downHead traveler
        while(travel->right!=NULL){               //insert to Chain[sit]
            if(travel->right->col<=node->col){
                if((travel->right->row==node->row) && (travel->right->col==node->col)){  travel->right->data+=node->data;     return;} //perform plus
                if( (travel->right->row>node->row) && (travel->right->col==node->col) ) break;
                else{
                    travel=travel->right;
                }
            }
            else break;
        }
        node->right=travel->right;
        travel->right=node;
//---------------------FOR RIGHTHEAD------------------------
    ElementNode* downTravel=rightHead[r];     //rightHead traveler
        while(downTravel->down!=NULL){               //insert to Chain[sit]
            if(downTravel->down->row<=node->row){
                if( (downTravel->down->col>=node->col)&& (downTravel->down->row==node->row) ) break;
                else
                    downTravel=downTravel->down;
            }
            else break;
        }
        node->down=downTravel->down;
        downTravel->down=node;
}

void Matrix::Output(){
        //-------------------------DEBUG FUNCTION----------------
    cout<<endl;
    for(int i=0;i<m;i++){
        ElementNode* check=rightHead[i]->down;           //rightHead has more nodes
        while(check){
            cout<<"["<<check->row<<"]["<<check->col<<"] = "<<check->data<<" \n";
            check=check->down;
        }
    }
    cout<<endl;
    /*
    for(int i=0;i<n;i++){
        ElementNode* check=downHead[i]->right;      //downHead has more nodes
        while(check){
            cout<<check->data<<"  ";
            check=check->right;
        }
    }
    */
    // cout<<"\nCurrent rowNumber: "<<numRows<<"\nCurrent colNumber: "<<numCols;
    //----------------------------DEBUG FUNCTION--------------
}

Matrix::Matrix(int o,int m,int n){
    this->m=m;
    this->n=n;
    rightHead = new ElementNode*[m];
    downHead = new ElementNode* [n];
    for(int i=0;i<m;i++) rightHead[i]=new ElementNode();//rightHead[i]= new HeadNode();
    for(int i=0;i<n;i++) downHead[i]=new ElementNode();  //downHead[i]=new HeadNode();
    numCols=0;
    numRows=0;
    for(numNodes=0;numNodes<o;numNodes++){
        int r=0,c=0,value=0;
        cin>>r>>c>>value;
        if(this->rightHead[r]->down==NULL){         //if it is the first element for rightHead[cols];
            //cout<<" Row++\n";
            this->numRows++;
        }
        if(this->downHead[c]->right==NULL){         //if it is the first element for rightHead[cols];
            //cout<<"  Col++\n";
            this->numCols++;
        }
        Insert(c,r,value);       //Insert Process
    }
};

int main(void){
    int m,n,o;         //matrix mxn
    cin>>o>>m>>n;       //o:number of Nodes
    Matrix alpha(o,m,n);
    //cout<<"alpha Initialized.\n";
    cin>>o>>m>>n;
   Matrix beta(o,m,n);
   // cout<<"beta Initialized.\n";
    //alpha.Output();
    alpha = alpha.Multiply(beta);
    beta.Output();
    alpha.Output();

}
