/*
Caution: C++ <vector> still needs to be implement for route array.

*/
#include <iostream>
#include <cstdlib>
using namespace std;
struct Matrix{
    int left,right;
};

void Print(int n,int route[][6],int start,int end){
    if(start==end){cout<<"A";}
    else{
        cout<<"(";
        Print(n,route,start,route[start][end]);
        Print(n,route,route[start][end]+1,end);
        cout<<")";
    }
}


int main(void){
    int n;  //n matrix
    cin>>n;
    int DP[n][n];
    int route[6][6];
    Matrix Ma[n];
    for(int i=0;i<n;i++){
        cin>>Ma[i].left;       //matrix left*right
        cin>>Ma[i].right;
    }
    for(int i=0;i<n;i++){
        DP[i][i]=0;
    }

    for(int gap=1;gap<n;gap++){      //gap number
        for(int start=0;start<n-gap;start++){
            //if(Ma[j].right!=Ma[j+1].left){cout<<"Input incorrect!\n"; return 0;}
            int end = start+gap;
            DP[start][end]=INT_MAX;
            for(int i=start;i<end;i++){
                int temp = DP[start][i] + DP[i+1][end] + (Ma[start].left * Ma[end].right * Ma[i].right);
                if(temp<DP[start][end]){
                    DP[start][end]=temp;
                    route[start][end] = i;
                cout<<"Proceed! , min(DP)="<<temp<<" i="<<i<<" start="<<start<<" end="<<end<<endl;
                }
            }
        }
    }
    cout<<DP[0][n-1<<endl];

    //--------print-----------
    Print(n,route,0,n-1);



    //-----------------------



}
/*
6
30 35
35 15
15 5
5 10
10 20
20 25
*/
