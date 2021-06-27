#include <iostream>
//#include <algorithm>
#include <numeric>
using namespace std;
int main(void){
	int init=1;
	int array[5]={2,4,8,5,3};
	int n=4;
	cout<<(accumulate(array,array+n,1));
}
