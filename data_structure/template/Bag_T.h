template <class T>
class Bag{
	public:
		Bag(int bagCapacity = 10){
			capacity=bagCapacity;
			top=-1;
			array = new T[bagCapacity];
			};
			
		~Bag(){
			delete[] array;
		};
		//int Size() const;
		//bool isEmpty() const;
		T& Element() const;
		
		void Push(T alpha){
			array[++top]=alpha;
		};
		T Pop(){
			if(top==-1){
				throw "Bag is empty.";
			}
			else{
				return array[top--];
			}
		}
		
		private:
			T* array;
			int capacity;
			int top;
};

