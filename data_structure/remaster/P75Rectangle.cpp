#include <cstdlib>
#include <iostream>
#include "P75Rectangle.h"
using namespace std;

	ostream& operator<<(ostream& os,const Rectangle& r){
		cout<<"special out: "<<r.GetHeight()<<endl;
		return os;
	}

Rectangle::GetHeight(int* a) {
	cout<<"called, a="<<*a<<" "<<a;
	*a+=50;
	cout<<" a= "<<*a<<" "<<a<<endl;
	return this->height;
}

Rectangle::GetHeight() const{
	return this->height;
}

Rectangle::GetWide() const{
	return this->wide;
}

Rectangle::Rectangle(int _xLow,int _yLow,int _height,int _width){
	xLow=_xLow;
	yLow=_yLow;
	height=_height;
	wide=_width; 
}
Rectangle::~Rectangle(){
}

void Rectangle::operator+(const Rectangle& beta){
	this->wide+=beta.GetWide();
	this->height+=beta.GetHeight();
}

int main(void){
	int* int_c = new int;
	*int_c=0; 
	Rectangle a(0,0,20,20);
	Rectangle b(10,10,25,25);
	a+b;
	cout<<a<<"   "<<*int_c<<" "<<int_c<<endl;
	
}
