#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
/****
/ Implement KMP algorithm in DS-version (failure function index starts from 0)
/ KMP : search for the index that contain string p in t.
/ Complexity : O(m+n) (amortized)
/ strategy : Dynamic Programming (mapping pi to decrease compare counts)
****/

void debug(string p,int* pi){
    for(int i=0;i<p.length();i++){
        cout<<pi[i]<<" ";
    }
    cout<<endl;   //flush
}



void failure_fun(string p , int* pi){
    int m = p.length();
    /* initialize */
    for(int i =0;i<m;i++){
        pi[i]=-1;
    }

    pi[0]=-1; 
    int key=-1;      
    /*------------*/
    for(int pIndex=1 ; pIndex < p.length() ; pIndex++){
        while(key > -1 && p[key+1] != p[pIndex]){//while compare failed and the key wasn't the lowest position(compared from p's head)
            key = pi[key];                         //downgrade trace
        }
        if(p[key+1]==p[pIndex]){     //compare success
            key++;
        }
        pi[pIndex] = key;                      //record ith position value
    }
}

int KMP(string t, string p , int* pi){
    int key = -1;
    for(int i=0 ; i<t.length(); i++){
        while(key>-1 && p[key+1] != t[i]){ // same. while compare failed and the key wasn't = -1(compare head)
            key = pi[key];                 // route the index = pi[key]
        }
        if(p[key+1] == t[i]){              //compare success
            key++;
        }
        if(key == p.length()-1){
            return i - key;
        }
    }
    return -1;
}



int main(void){
    string t,p;
    cin>>t>>p;
    int* pi = new int[p.length()];
    failure_fun(p,pi);
    //debug(p,pi);
    int ans = KMP(t,p,pi);
    cout<<"index: "<<ans<<endl;
}