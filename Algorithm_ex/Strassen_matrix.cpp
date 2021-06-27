#include <iostream>
#include <cstdlib>
using namespace std;
struct MatricNode{
    friend class Matric;
    private:
        int value;
};

class Matric{
    private:
        int m,n;
    public:
        Matric(int,int);
        MatricNode** index;
        Multiply(Matric,int,int,Matric,int,int);
};
Matric Matric::operator+(Matric alpha,Matric beta){

}
Matric::Multiply(int a_rowstart,int a_rowlast,int a_colstart,int a_collast,Matric beta,int b_rowstart,int b_rowlast,int b_colstart,int b_collast,int b_last){
    if(a_rowstart==a_rowlast&& a_colstart==a_collast){
        return this->index[a_rowstart][a_colstart]*beta.index[b_rowstart][b_colstart];
    }
    else{
        int a_11 = a_rowstart
    }
}

Matric::Matric(int m,int n){  //[row][col],read left to right then move down.
    this->m=m;
    this->n=n;
    index = new MatricNode*[m];
    for(int i=0;i<m;i++){
        index[i] = new MatricNode[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>(index[i][j].value);
        }
    }
}

int main(void){
    int m,n;
    cin>>m>>n;  //row number(moving down),col number(moving right)
    Matric alpha(m,n);
    cin>>m>>n;
    Matric beta(m,n);
}
