class MatrixTerm{
	friend class SparseMatrix;
	int row,col,value;
};

class SparseMatrix{
	private:
		int capacity,terms,rows,cols;
		MatrixTerm* smArray;
	public:
		SparseMatrix Multiply(SparseMatrix beta);
		SparseMatrix Add(SparseMatrix beta);
		SparseMatrix();
		void StoreSum(int,int,int);
		//void StoreSum(MatrixTerm);
};
