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
			int getSize(){                  //�ʸ�-���o�Q���t�j�p 
				return size;
			}
			void print(){                   //�L�X�x�ëY�� 
				for(int i=0;i<terms;i++){
					cout<<"COEF: "<<TermArray[i].coef<<endl;
					cout<<"EXP: "<<TermArray[i].exp<<endl;
				}
			}
			int getTerms(){                 //�ʸ�-���o�x�ö��� 
				return terms;
			}
			Polynomial(int i){              //�غc�� 
				TermArray = new Term[i];
				size=i;
				terms=0;
			}
			void exceed(){                  //�x�s�Ŷ��X�R 
				Term* temp;
				size*=2;
				temp = new Term[size];          //�w�]�[�� 
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
