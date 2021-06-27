#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>
#include "P93_Appendix.h"
#ifndef def
	#define def 50
#endif
using namespace std;
	
	void getnum(string str,int& coef, int& exp,bool& finished){             //從文本萃取資料 
		int i=0;
		regex reg("[0-9]");
		string coe="",pow="";
		if(str.length()==1 && !(regex_match(str, reg))){
			finished=true;
			return;
		}
		//取得係數 
		if(str.at(0) == '+'){i=1;}
		if(str.find('*')!= string::npos){           //是否係數為1 
			while(str.at(i)!= '*'){
			coe+=str[i];
			i++;
			}
		}
			else if(str.find('x')== string::npos&&str.find('^')==string::npos){      //常數
			 coe = str.substr(i);
			 exp = 0;
			}
			else{                                      //若係數為1，是正是負 
				if(str.at(0)=='-')
				coef=-1;
				else if(str.find('x')== string::npos)
				coe=str.substr(1);
				else
				coef=1;
			}
		//取得係數 coe字串 
			if(str.find('^')!= string::npos)
			pow = str.substr((str.find('^')+1));
			
			else if(str.find('x')!=string::npos) exp=1;
			else exp=0;
		//取得次方 pow字串 
		if(coe!="")
			coef= stoi(coe);
		if(pow!="")
			exp= stoi(pow);
	}
		
	string assign(Polynomial& pol,istream& fin,int& extra_coef,int& extra_exp){   //灌入資料 
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
			if(finished){                        //這是運算符號 
				//fin>>str1;
				return str1;
			}
			pol.newTerm(coef,exp);
		    fin>>str1;
		}
	}	
	

int main(void){
	ifstream fin;
	string str1="";
	fin.open("./t2.txt", ios::in);
	Polynomial alpha(def); 
    	int extra_coef=0,extra_exp=0;
    	str1=assign(alpha,fin,extra_coef,extra_exp);
		while(!fin.eof()){
			Polynomial beta(def);
			if(extra_coef!=0){
				beta.TermArray[beta.terms].coef=extra_coef;
				beta.TermArray[beta.terms].exp=extra_exp;
				beta.terms+=1;
				extra_coef=0; extra_exp=0;
			}
			str1=assign(beta,fin,extra_coef,extra_exp);
			//cout<<"STR: "<<str1<<endl;
			switch(str1.at(0)){
				case '+':
					//cout<<"add called"<<endl;
					alpha=alpha.add(beta);
					break;
				case '-':
					//cout<<"Minus called"<<endl;
					alpha=alpha.minus(beta);
					break;
				case '*':
					//cout<<"cross called"<<endl;
					alpha=alpha.multi(beta);
					break;
				case '/':
					//cout<<"dash called"<<endl;
					alpha=alpha.dash(beta);
					break;		
			}
		}
	fin.close();       //關閉檔案
	alpha.output();
	return 0;
}
