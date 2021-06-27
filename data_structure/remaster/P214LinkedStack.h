
class StackNode;

class LinkedStack{
    private:
        StackNode* top;
    public:
        void Push(StackNode*);
        void Pop();
        StackNode& Top();
        LinkedStack();
};

class StackNode{
    friend LinkedStack;
    protected:
        int data;         //assume data = int, can be override to other type
        StackNode* next;
};

LinkedStack::LinkedStack(){
    top = 0;
}


void LinkedStack::Push(StackNode* enter){
    if(!top){
        top = enter;
    }
    else{
        enter->next = top;
        top = enter;
    }
}

StackNode& LinkedStack::Top(){
    if(top)
        return *top;
    else
        throw "GG";
}

void LinkedStack::Pop(){
    if(top->next) top = top->next;    //Stack>1
    else if(top) top = 0;          //Stack ==1
    //else cout<<"Stack Empty!";        //Stack ==0
}
