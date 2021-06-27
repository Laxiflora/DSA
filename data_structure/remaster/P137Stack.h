template <class T>
class Stack{
	public:
		Stack(int stackCapacity=10);
		bool IsEmpty() const;
		T Top() const;
		void Push(const T item);
		void Pop();
	private:
		T* itemList;
		int capacity;
		int top;
};
