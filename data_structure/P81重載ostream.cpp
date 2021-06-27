#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class student{
	private:
		int score;
		string name;
		char sex;
	public:
		string getName(){
			return name;
		}
		int getScore(){
			return score;
		}
		student(){
		cin>>score;
		cin>>name;
		cin>>sex;
	}
		student(int a){
			score=a;
			name="const";
			sex='n';
		}
 	friend ostream& operator<<(ostream& os,student& a){
		cout<<"score: "<<a.score;
		cout<<"\nname: "<<a.name;
		cout<<"\nsex: "<<a.sex;
		return os;
	}
	friend const student operator+=(student& a,student& b){
	a.score=a.getScore()+b.getScore();
	return a;
	}
	friend const student operator+(student& a,student& b){
		a.score=a.getScore()+b.getScore();
		return a;
	}
	
//	friend student operator++();   overload ++x
//  friend student operator++(int); overload x++ no need to give a parameter name. 
};


int main(void){
	student a,b;
	a+=b;
	a=a+b;
	cout<<a;
	return 0;
}
