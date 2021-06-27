#include <iostream>
#include <cstdlib>
#define DEFAULT 3
using namespace std;
class Term;
class Polynomial{
	public:
		Term* terms;
		int termNum;
		int capacity;
		void add(Polynomial);
		Polynomial();
};

class Term{
	friend Polynomial;
	public:
		int coef,exp;
};

	Polynomial::Polynomial(){
	capacity=DEFAULT;
	terms = new Term(capacity+1);
}

void Polynomial::add(Polynomial beta){
	int aPos=0,bPos=0;
	while(){
		
	}	
}


int main(void){
	Polynomial alpha,beta;
	
	alpha.add(beta);
	return 0;
}

