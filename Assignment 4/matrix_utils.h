//A function that creates a (square) identity matrix of size nxn
int **getIdentityMatrix(int n);

//A function to determine if a given matrix is a permutation matrix
int isPermutationMatrix(int **m, int n);

//A  function  to  determine  if  a  given  square  matrix  is symmetric
int isSymmetric(int **m, int n);

//A function to compute the trace of a matrix
int trace(int **m, int n);

//A funtion to flip a matrix along the diagonal, or transpose it
void transpose(int **m, int n);

//A function which creates a copy of a matrix, used in transposeCopy and matrixCopy
int ** mcopy(int**m, int n);

//A function to transpose a matrix and create a new matrix representing the transpose
int ** transposeCopy(int **m, int n);

//A function to resize a matrix
int ** matrixCopy(int **A, int n, int m, int p, int q);