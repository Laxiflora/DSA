#include <iostream>
#include <fstream>
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
			int getSize(){                  //杆-眔砆だ皌 
				return size;
			}
			void output(){
				ofstream fout("output.txt",ios::app);
				fout<<"="; 
				for(int k=0;k<terms;k++){
					if(TermArray[k].coef==0) continue;                       //0
					fout<<" ";
					if(TermArray[k].coef>0&&k!=0) fout<<"+";                 //琌材兜 
					if(TermArray[k].exp==0){fout<<TermArray[k].coef; continue;}   //琌盽计 
					if(TermArray[k].coef==1){                                     //琌玒计琌1 
						if(TermArray[k].exp!=1){
							fout<<"x^";
							fout<<TermArray[k].exp;                           //璝玒计琌1琌Ω计琌1 
							continue;
						}                  
						else{fout<<"x"; continue;}	
					}
					else if(TermArray[k].coef==(-1)){
						fout<<"-";
						if(TermArray[k].exp!=1){
							fout<<"x^";
							fout<<TermArray[k].exp;                           //璝玒计琌-1琌Ω计琌1 
							continue;
						}                  
						else{fout<<"x"; continue;}
					} 
				 	else{
						if(TermArray[k].exp!=1){
							fout<<TermArray[k].coef<<"*x^";
							fout<<TermArray[k].exp;                           //璝玒计琌-1琌Ω计琌1 
							continue;
						}                  
						else{fout<<TermArray[k].coef<<"*x"; continue;}
					}
				}
					fout<<"\n";
					fout.close();
			}
			
			void print(){                   //纗旅玒计 
				for(int i=0;i<terms;i++){
					cout<<"COEF: "<<TermArray[i].coef<<endl;
					cout<<"EXP: "<<TermArray[i].exp<<endl;
				}
			}
			int getTerms(){                 //杆-眔纗旅兜计 
				return terms;
			}
			Polynomial adjust(){              //睲埃玒计0 
				Polynomial out(def);
				for(int i=0;i<terms;i++){
					if(TermArray[i].coef==0){
						continue;
					}			
					else{
						out.newTerm(TermArray[i].coef,TermArray[i].exp);
					}	
				}
				if(out.TermArray[0].coef==0){
					out.newTerm(0,0); 
					out.terms=-1; 
				//	cout<<"Done."<<endl;
				}
				return out;
			}
			Polynomial(int i){              //篶じ 
				TermArray = new Term[i];
				size=i;
				terms=0;
			}
			void exceed(){                  //纗丁耎 
				Term* temp;
				size*=2;
				temp = new Term[size];          //箇砞 
				copy(TermArray,TermArray+size,temp);
				delete []TermArray;
				TermArray=temp;
			}
			
			void newTerm(int coef,int exp){
				if(this->getTerms()>=this->getSize()){
		   			this->exceed();
			    }
				TermArray[terms].coef=coef;
			    TermArray[terms].exp=exp;
			    terms+=1;
			}
			
			Polynomial add(Polynomial beta){
				Polynomial temp(def);
				int aPos=0,bPos=0;
				while(aPos<terms && bPos<beta.terms){
					if(TermArray[aPos].exp==beta.TermArray[bPos].exp){
						int c=TermArray[aPos].coef+beta.TermArray[bPos].coef;
						temp.newTerm(c,TermArray[aPos].exp);	
						bPos++; aPos++;
					}
					else if(TermArray[aPos].exp>beta.TermArray[bPos].exp){
						temp.newTerm(TermArray[aPos].coef,TermArray[aPos].exp);
						aPos++;	
					}
					else{
						temp.newTerm(beta.TermArray[bPos].coef,beta.TermArray[bPos].exp);
						bPos++;	
					}
				}
				for(;aPos<terms;aPos++){
					temp.newTerm(TermArray[aPos].coef,TermArray[aPos].exp);
				}
				for(;bPos<beta.getTerms();bPos++){
					temp.newTerm(beta.TermArray[bPos].coef,beta.TermArray[bPos].exp);
				}
				temp=temp.adjust();
				return temp;
			}
			Polynomial minus(Polynomial beta){
				for(int i=0;i<beta.getTerms();i++){
					beta.TermArray[i].coef*=-1;
				}
				return this->add(beta);
			}
			
			Polynomial multi(Polynomial beta){
				Polynomial out(def);
				for(int i=0;i<beta.terms;i++){
					Polynomial temp(def);
					for(int j=0;j<this->terms;j++){
						temp.newTerm(TermArray[j].coef*beta.TermArray[i].coef,TermArray[j].exp+beta.TermArray[i].exp);
					}
					out=out.add(temp);
				}
				return out;
			}
			Polynomial dash(Polynomial beta){
				Polynomial out(def);
				while(TermArray[0].exp>=beta.TermArray[0].exp||this->terms!=-1){
					Term tuple;
					tuple.coef=TermArray[0].coef/beta.TermArray[0].coef;
					tuple.exp=TermArray[0].exp-beta.TermArray[0].exp;
					out.newTerm(tuple.coef,tuple.exp);
					Polynomial temper(def);
					temper.cop(beta);
					for(int i=0;i<temper.terms;i++){
						temper.TermArray[i].coef*=tuple.coef;
						temper.TermArray[i].exp+=tuple.exp;
					}
					*this=this->minus(temper);
				}
				
				return out;
			}
			
			void cop(Polynomial beta){
				for(int i=0;i<beta.terms;i++){
			    	this->newTerm(beta.TermArray[i].coef,beta.TermArray[i].exp);
				}
			}
		
	}; 
