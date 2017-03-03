//Code copied from C for comparison:
int *splice(const int *a, int n, const int *b, int m, int index) {
	if(n<=0||m<=0) {
		return NULL;
	}
	else if(index<n||index>n) {
		return NULL;
	}
	else {
		int *temp = (int *)malloc(sizeOf(int) * (n+m));
		int sizeOfTemp = n+m;
		
		int i;
		for(i=0; i<n; i++) {
			if(i<index||i>index) {
				temp[sizeOfTemp]= a[i];
				sizeOfTemp ++;
			}
			else if(i==index) {
				int j;
				for (j=0; j<m; j++) {
					temp[sizeOfTemp]= b[j];
					sizeOfTemp ++;
				}
			}
		}
		
		int *result = (int *)malloc(sizeOf(int) * sizeOfTemp);
		for(i=0; i<sizeOfTemp; i++) {
			result[i] = temp[i];
		}
		
		free(temp);
		
		*sizeOfResult = sizeOfTemp;
		
		return result;
	}
}

//The important bit:

public static int [] splice(int a[], int b[], int index) {
	if(a.length<=0||b.length<=0) {
		throw new RuntimeException;
	}
	else if(index<a.length||index>a.length) {
		throw new RuntimeException;
	}
	else {
		int result[] = new int[a.length+b.length];
		int resultCounter = 0;
		for(i=0; i<a.length; i++) {
			if(i<index||i>index) {
				result[resultCounter]= a[i];
				resultCounter ++;
			}
			else if(i==index) {
				int j;
				for (j=0; j<b.length; j++) {
					result[resultCounter]= b[j];
					resultCounter ++;
				}
			}
	return result;
	}
}