#include "Bag_T.h"
#ifndef type
	#define typ char
#endif
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(void){
	Bag<typ> alpha;
	//alpha.Push('a');
	//alpha.Push('b');
	typ ans;
	try{
		ans=alpha.Pop();
	}
	catch(char const* str){
		cout<<str<<endl;
	}
	cout<<ans;
	return 0;
}

