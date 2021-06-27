#include "P214LinkedStack.h"
#include "P180LinkedList.h"
#include <iostream>
#include <cstdlib>
#include <stack>
template <class T>
class Equivalence{
    private:
        //LinkedStack* s;
        Chain<T>* first;
        bool* out;

    public:
        void SortClass(int);
        void EquivalenceSort(int);
};

template <class T>
void Equivalence<T>::EquivalenceSort(int n){
    stack<int> s;
    //int j;
    for(int i=0;i<n;i++) out[i]=false;
    //
    for(int i=0;i<n;i++){
        if(!out[i]){
            out[i] = true;
            cout<<endl<<"New Class: "<<endl<<i;
                for(int k=0;k<first[i].Quantity();k++){                   //first[i]'s number k node
                    if(!out[first[i][k]]){                            //if first[i]->data haven't been printed yet.
                        out[first[i][k]]=true;
                        cout<<" , "<<first[i][k];
                        s.push(first[i][k]);                 //stack first[i][k]
                    }//end of if
                }//end of for
                while(!s.empty()){                                  //while the stack has element
                    int j=s.top();
                    s.pop();
                    for(int X = 0;X<first[j].Quantity();X++){
                        if(!out[first[j][X]]){
                            cout<<" , "<<first[j][X];
                            out[first[j][X]]=true;
                            s.push(first[j][X]);
                        }
                    }
                }//end of while
        }//end of if
    }//end of for,start another line
}//end of function

template <class T>
void Equivalence<T>::SortClass(int n){
    first = new Chain<int>[n];                //node range: from 0~n-1
    out = new bool(n);
    while(true){
        int k,l;
            cin>>l>>k;           //pair(k,l)
            if(l==-1&&k==-1) return;
            first[k].Insert(l,0);
            first[l].Insert(k,0);
    }
}

/*
5
4 3
2 0
3 1
1 2
3 4


12
0 4
3 1
6 10
8 9
7 4
6 8
3 5
2 11
11 0

*/
using namespace std;
int main(void){
    int n;
    Equivalence<int> alpha;
    cin>>n;
    cout<<"enter the relation pairs, input -1 -1 to stop. (pair number must not > n) ";
    alpha.SortClass(n);
    alpha.EquivalenceSort(n);
    return 0;
}
