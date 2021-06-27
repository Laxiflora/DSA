#include <iostream>
#include <cstdlib>
#include "P105SparseMatrix.h"
#define CAPACITY 20
using namespace std;

	//private:
		//int capacity,terms,rows,cols;
		//MatrixTerm* smArray;

		SparseMatrix SparseMatrix::Multiply(SparseMatrix beta){
		}
		SparseMatrix SparseMatrix::Add(SparseMatrix beta){
			int aPos,bPos;
		}
		SparseMatrix::SparseMatrix(){
			capacity=CAPACITY;
			smArray = new MatrixTerm[CAPACITY];
			terms=0;
			rows=0;
			cols=0; 
		}
		void doubleCAP(){
		}
		int showValue(int ro,int co){
			
		}
		void SparseMatrix::StoreSum(int sum,int c,int r){
			if(capacity+1 == CAPACITY) doubleCAP();  //need to be implemented
			smArray[terms].row=r;
			smArray[terms].value=sum;
			smArray[terms++].col=c;           //rows how to increase
											  //cols how to increase
		}

int main(void){
	SparseMatrix a,b;
	a.StoreSum(10,0,2);
	a.StoreSum(12,1,5);
	a.StoreSum(14,1,8);
	a.StoreSum(15,2,0);
	a.StoreSum(17,8,1);
	a.StoreSum(19,4,7);  //a:9x9
	
	b.StoreSum(11,8,8);
	b.StoreSum(12,5,6);
	b.StoreSum(14,6,4);
	b.StoreSum(17,1,3);
	b.StoreSum(12,6,4);
	b.StoreSum(20,2,2); //b:9x9
	
	
	return 0;
}
