template <class T>
class Bag{
	public:
		Bag(int stackCapacity=10);
		bool IsEmpty() const;
		//T Top() const;
		T take();                  //use
		void Push(const T item);    //take
	protected:
		T* itemList;
		int capacity;
		//int top;
};

template <class T>
class Stack : public Bag<T>{
		public:
		Stack(int stackCapacity=10);
		T Top() const;
		void Pop();               //discard
	private:
		int top;
};
template <class T>
Stack<T>::Stack(int stackCapacity){
	this->capacity=stackCapacity;
	top=0;
	this->itemList = new T[this->capacity];
}
template <class T>
T Stack<T>::Top() const{
	return this->itemList[top-1];
} 

template <class T>
void Stack<T>::Pop(){
	top--;
} 
template <class T>
bool Bag<T>::IsEmpty() const{
	return this->capacity==0;        //wrong, testing only
}
template <class T>
Bag<T>::Bag(int stackCapacity){
	this->capacity=stackCapacity;
	this->itemList = new T[this->capacity];
}


