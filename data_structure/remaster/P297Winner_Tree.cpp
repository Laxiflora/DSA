#include <iostream>
#include <cstdlib>
using namespace std;

/*
struct PracticeNode{
    int value;
    int operator[](int i)const{cout<<"Read Called"; return value;}
    int operator[](int i){cout<<"Write Called"; value = i;}
};

istream& operator>>(istream& is,PracticeNode& Prac){
    cin>>Prac.value;
}

ostream& operator<<(ostream& os,PracticeNode& Prac){
    cout<<Prac.value;
}
*/


template <class T>
class WinnerTree{
    public:
        WinnerTree<T>(int);
        T Sort();
    private:
        int number,n;
        T* arraylist;
};

template <class T>
WinnerTree<T>::WinnerTree(int n){
    this->n=n;
    arraylist = new T [2*n];
    for(int i=n;i<2*n;i++){
        cin>>arraylist[i];
    }
}

template <class T>
T WinnerTree<T>::Sort(){
    for(int i=2*n-1;i>1;i-=2){
        if(arraylist[i]>arraylist[i-1]){
            arraylist[i/2]=arraylist[i-1];
        }
        else arraylist[i/2]=arraylist[i];
    }
    return arraylist[1];
}

int main(void){
    int n;
    cin>>n;
    WinnerTree<int> alpha(n);  //n must be 2^n -1
        int ans=alpha.Sort();
    cout<<ans;
}

/*
8
4 8 7 2 4 5 9 1
*/

