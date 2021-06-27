class Rectangle{
	public:
		Rectangle(int,int,int,int);
		~Rectangle();
		int GetHeight(int*) ;
		int GetHeight() const;
		int GetWide() const;
		void operator+(const Rectangle&);
	private:
		int xLow,yLow,height,wide;
};
