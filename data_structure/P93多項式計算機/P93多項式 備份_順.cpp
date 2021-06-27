#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>
#ifndef def
	#define def 10
#endif
using namespace std;
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
		
	}; 
	
	void getnum(string str,int& coef, int& exp,bool& finished){             //�q�奻�Ѩ���� 
		int i=0;
		regex reg("[0-9]");
		string coe="",pow="";
		if(str.length()==1 && !(regex_match(str, reg))){
			finished=true;
			return;
		}
		//���o�Y�� 
		if(str.at(0) == '+'){i=1;}
		if(str.find('*')!= string::npos){           //�O�_�Y�Ƭ�1 
			while(str.at(i)!= '*'){
			coe+=str[i];
			i++;
			}
		}
			else if(str.find('x')== string::npos&&str.find('^')==string::npos){      //�`��
			 coe = str.substr(i);
			 exp = 0;
			}
			else{                                      //�Y�Y�Ƭ�1�A�O���O�t 
				if(str.at(0)=='-')
				//ccoe[zhu][j]=-1;
				coef=-1;
				else if(str.find('x')== string::npos)
				coe=str.substr(1);
				else
				coef=1;
			}
		//���o�Y�� coe�r�� 
			if(str.find('^')!= string::npos)
			pow = str.substr((str.find('^')+1));
			
			else if(str.find('x')!=string::npos) exp=1;
			else exp=0;
		//���o���� pow�r�� 
		if(coe!="")
			coef= stoi(coe);
		if(pow!="")
			exp= stoi(pow);
	}
		
		
	string assign(Polynomial& pol,istream& fin,int& extra_coef,int& extra_exp){   //��J��� 
		string str1;
		fin>>str1;
		int last_exp=INT_MAX;
		bool zzz=true;
    	bool finished=false;
    	while(zzz){
	    	int coef=0,exp=0;
		    getnum(str1,coef,exp,finished);
		    if(last_exp<exp){
		    	zzz=false;
		    	extra_coef=coef;
		    	extra_exp=exp;
		    	return "";
			}
			else last_exp=exp;
			if(finished){                        //�o�O�B��Ÿ� 
				return str1;
			}
		   if(pol.getTerms()>=pol.getSize()){
		   		pol.exceed();
		   }
			pol.TermArray[pol.terms].coef=coef;
		    pol.TermArray[pol.terms].exp=exp;
		    pol.terms+=1;
		    fin>>str1;
		}
	}	
	

int main(void){
	ifstream fin;
	string str1;
	fin.open("./t2.txt", ios::in);
	Polynomial alpha(def); 
	Polynomial beta(def); 
    	int extra_coef=0,extra_exp=0;
    	str1=assign(alpha,fin,extra_coef,extra_exp);
		cout<<"�q��A"<<endl;
	//	while(fin){
			if(extra_coef!=0){
				beta.TermArray[beta.terms].coef=extra_coef;
				beta.TermArray[beta.terms].exp=extra_exp;
				beta.terms+=1;
				extra_coef=0; extra_exp=0;
			}
			cout<<"�q��B�}�l"<<endl; 
			str1=assign(beta,fin,extra_coef,extra_exp);
			cout<<"Alpha�L�X:"<<endl;
			alpha.print(); 
			cout<<"Beta�L�X:"<<endl;
			beta.print();
			cout<<"STR:"<<str1;
	//}
	fin.close();       //�����ɮ�

	return 0;
}
