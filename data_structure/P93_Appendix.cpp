class Polynomial;
	class Term{
		friend Polynomial;
		public:
			float coef;
			int exp;
	};
	class Polynomial{
		private:
			//Term* TermArray;
			int size;
		public:
			Term* TermArray;
			int terms;
			int getSize(){                  //封裝-取得被分配大小 
				return size;
			}
			void print(){                   //印出儲藏係數 
				for(int i=0;i<terms;i++){
					cout<<"COEF: "<<TermArray[i].coef<<endl;
					cout<<"EXP: "<<TermArray[i].exp<<endl;
				}
			}
			int getTerms(){                 //封裝-取得儲藏項數 
				return terms;
			}
			Polynomial(int i){              //建構元 
				TermArray = new Term[i];
				size=i;
				terms=0;
			}
			void exceed(){                  //儲存空間擴充 
				Term* temp;
				size*=2;
				temp = new Term[size];          //預設加倍 
				copy(TermArray,TermArray+size,temp);
				delete []TermArray;
				TermArray=temp;
			}
			void add(Polynomial beta){
			}
			void minus(Polynomial beta){
			}
			void multi(Polynomial beta){
			}
			void dash(Polynomial beta){
			}
		
	}; 
