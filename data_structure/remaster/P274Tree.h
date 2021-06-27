class BinaryTree{
    private:
        TreeNode* root;
    public:
        BinaryTree Swap();
        BinaryTree BuildCalTree(string);    //postorder
        BinaryTree();
        void InorderBuildTree(string);  //inorder
        int InorderPriority(char);
}

template <class T>
class TreeNode{
    private:
        T data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode();
        TreeNode(T);
};

TreeNode::TreeNode(){
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(T dat){
    this->data = dat;
}


BinaryTree::BinaryTree(){
    root = NULL;
}

int BinaryTree::InorderPriority(char op){
    if(char == '+' || '-') return 1;
    if(char == '*' || '/') return 2;
    else return 0;
}

void BinaryTree::BuildCalTree(string input){
    char op;
    Stack<TreeNode> s;
    for(int i=0;i<input.length();i++){

        if(op == '+'||'-' || '*'||'/'){

        }
    }
}

void BinaryTree::InorderBuildTree(string input){
    int Stack<char> s;
    string output;
    char op='';
    for(int i=0;i<input.length();i++){
        op = input[i];
        if(op == '+'||'-' || '*'||'/'){
            while(this->InorderPriority(s.top())>=InorderPriority(op)){
                output+=s.top();
                s.pop();
            }
            s.push(op);
        }
        else if(op==')'){
            while(s.top()!='('){
                output+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            s.push(op);
        }
    }
    while(!s.empty()){
        output+=s.top();
        s.pop();
    }
    BuildCalTree(output);
}
