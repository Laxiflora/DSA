using namespace std;
template <typename T>
class Chain;

template <class T>
class ChainNode{
	friend class Chain<T>;
	public:
		ChainNode();
		ChainNode(T);
	protected:
		T data;
		ChainNode* next;
};

template <class T>
class Chain{
	public:
		void Insert(T data,int);
		void Insert();           //insert to top node
		void Delete(int);
		int Quantity();
		T operator[](int)const;
		T& operator[](int);
		Chain();
	protected:
		ChainNode<T>* first;
};
//----------------------------------------------------------------------
template <class T>
ChainNode<T>::ChainNode(T dat){
	data = dat;
}
template <class T>
ChainNode<T>::ChainNode(){
	this->next=0;

}
//------------------------------------------------------------
template <class T>
T& Chain<T>::operator[](int sit){
	ChainNode<T>* travel = this->first;
	for(int i=0;i<=sit;i++){
		travel = travel->next;
	}
	return travel->data;
}
//-------------------------------------------------------------

template <class T>
void Chain<T>::Delete(int sit){
	ChainNode<T>* travel = first;
	for(int i=0;i<sit;i++){
		travel = travel->next;
	}
	travel->next = (travel->next)->next;
}

template <class T>
Chain<T>::Chain(){
	first = new ChainNode<T>;
}

template <class T>
void Chain<T>::Insert(T data,int sit){
	ChainNode<T>* node = new ChainNode<T>(data);
	ChainNode<T>* travel = this->first;
	for(int i=0;i<sit;i++){               //insert to Chain[sit]
		travel = travel->next;
	}
	node->next=travel->next;
	travel->next=node;
}
template <class T>
int Chain<T>::Quantity(){
    int k;
    ChainNode<T>* travel = this->first;
    for(k=0;travel->next;k++){               //return number of nodes
		travel = travel->next;
	}
	return k;
}
