#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#ifndef def
	#define def 20
#endif
#ifndef chardef
	#define chardef 1000
#endif
using namespace std;
class SparceMatrix;

class MatrixTerm{
	friend SparceMatrix; 
	private:
	public:
		int nucol,value;  //unused
		int* nurow;
};

class SparseMatrix{
	public:
		int rows,cols,terms,capacity;
		MatrixTerm* smArray;
		SparseMatrix(int size){
			smArray = new MatrixTerm[size];
			nurow = new int[size]; 
			capacity = size;
			terms=0;
		}
/*		SparseMatrix multi(SparseMatrix beta){     
			SparseMatrix out(def);
			for(int i=0;i<terms;i++){           //row為單位
				while(this->smArray[i].row==this->smArray[i+1].row){
					while(beta.smArray[])
				}
			}
			return out;
		}*/
		SparseMatrix transpose(){
			SparseMatrix temp(def);
			for(int i=0;i<terms;i++){
				temp.newTerm(smArray[i].row,smArray[i].col,smArray[i].value);
			}
			return temp;
		}
		 
		void print(){
			for(int i=0;i<terms;i++){
				cout<<"rows: "<<smArray[i].row<<endl;
				cout<<"cols: "<<smArray[i].col<<endl;
				cout<<"values: "<<smArray[i].value<<endl;
				
			}
		}
		void newTerm(int col, int row, int value){
			if(terms>=capacity) this->exceed();
			smArray[terms].col=col;
			smArray[terms].row=row;
			smArray[terms].value=value;
			//nurow[terms++] = row; 
		}
		
		void exceed(){
			int* tempInt;
			MatrixTerm* temp;
			temp = new MatrixTerm[(this->capacity)*2];
			tempInt = new int[(this->capacity)*2];
			copy(nurow,nurow+capacity,tempInt);
			copy(smArray,smArray+capacity,temp);
			delete []smArray;
			delete []tempInt;
			this->capacity*=2;
			nurow = tempInt;
			smArray = temp;
		}
};


void input(SparseMatrix& matrix,ifstream& fin){            //自己設定輸入方法 
	//cout<<"READED\n";
	int col=0,row=0;
	while(fin.peek()!='+'&&fin.peek()!='-'&&fin.peek()!='*'&&fin.peek()!='/'&&fin){
		string str="";
		getline(fin,str);
		//cout<<"str.length()= "<<str.length()<<endl;
		//cout<<"In to the loop\n"<<str<<endl<<str.length()<<endl<<str[2]<<endl;
		for(int i=0;i<str.length();i++){
			//cout<<"looping\n";
			if(str[i]=='0'){
				//cout<<"zero \n";
				col++;
				continue;
			}
			if(str[i]==' '){
				//cout<<"space \n";
				continue;
			}
			else{                                   //待改：負數處理 
				int number;
				if(str[i]=='-'){
					number=(int)str[++i]-'0';
					number*=-1;
					for(int zz=0;str[zz]!=' ';zz++){
						if(zz==0) continue;
						else{
							number*=10;
							number=number-(int)str[i]-'0';
						}
					}
				}
				else{
					//cout<<"in to the else\n";
					number = (int)str[i]-'0';                   //若為非0矩陣，判斷是否是多位數
					//cout<<"str[i]= "<<(int)str[i]-'0';
					//cout<<"int finished.\n"; 
					for(int zz=0;str[zz]!=' ';zz++){
						if(zz==0) continue;
						else{
							number*=10;
							number=number+(int)str[i]-'0';
						}
						}
				}
				//cout<<"number: "<<number<<endl;
				matrix.newTerm(col,row,number);
				col++;
			}
		}
		row++;
		col=0;
	}
}


int main(void){                       //目前輸入方法:一次讀入兩個矩陣相乘 
	ifstream fin;
	fin.open("./t1.txt",ios::in);
	SparseMatrix alpha(def);
	SparseMatrix beta(def);
	input(alpha,fin);
	string operat;
	getline(fin,operat);
	//fin>>operat;
	//cout<<"OPERAT:"<<operat<<"\nnext:"<<fin.peek()<<endl;
	input(beta,fin);
	beta=beta.transpose();
	//alpha=alpha.multi(beta);
	alpha.print();
	cout<<"BETA:"<<endl;
	beta.print();
	return 0;
}
