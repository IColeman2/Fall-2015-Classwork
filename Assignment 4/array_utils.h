//A function to compute the mean of an array of values
double mean(const int *a, int n);

//A function to compute a sliding window mean
double * windowMeans(const int *a, int n, int m);

//A function to compute the mode of an array of values
int mode(const int *a, int n);

//A function to compute all modes of an array
int * getAllModes(const int *a, int n, int *resultSize);

//A function to filter out certain elements from an array
int * filter(const int *a, int n, int threshold, int *resultSize);

//A function to append one array to another
int * append(const int *a, int sizeA, int *b, int sizeB);