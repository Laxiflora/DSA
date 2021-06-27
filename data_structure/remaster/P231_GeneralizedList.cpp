#include <iostream>
#include <cstdlib>
using namespace std;
class ElementNode;
class GeneralizedList{
    private:
        ElementNode* first;
    public:
        Insert(int,char);    //flag=0,variable
        Insert(int,int,int);   //flag=2, coef ,exp
        Insert(int,ElementNode*)    //flag=1,down
};

class ElementNode{
    friend class GeneralizedList;
    private:
        int flag;
        int coef;
        int exp;
        char variable;
        ElementNode* next;
        ElementNode* down;
};

int main(void){

}
