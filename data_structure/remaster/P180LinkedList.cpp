/*
    A link-list that can apply to any classes which some requirements is needed to the class:
        ostream operator<< and >> overloaded.
        if you want to use = operator to another class, an overload of operation= is required.

    note:The [] operator returns your object's reference
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "P180LinkedList.h"
#include "P180LinkedList_appendixA.h"
using namespace std;


//------------------------------------------------------------

int main(void){                  //needed:operator<<and>>overload,
	Chain<Student> link;
	Student std1(1,'M',50);
	Student std2(2,'F',40);
	Student std3(3,'M',30);
	Student std4(4,'F',20);
	Student std5(5,'M',10);
	link.Insert(std1,0);          //std2->std3->std4->std1->std5
	link.Insert(std2,0);
	link.Insert(std3,1);
	link.Insert(std4,2);
	link.Insert(std5,4);
	//debug loop
	for(int i=0;i<5;i++){
        string loop="in Loop: ";
        Student alpha;
        alpha=link[2];
		cout<<loop<<endl<<alpha<<endl<<link[i]<<endl;
		link[0]=alpha;
		cout<<link[0]<<endl;
	}
	//debug loop
	return 0;
}
