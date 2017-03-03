//A challenge to write code to print 10, 9, 8,...1 without using any loop control structure or any hard-coding
void countDown(int n) {
	printf("%d\n", n);
	
	//This basically uses the stack as a counter variable
	//This is known as recursion
	if(n>0) {
		countDown(n-1);
	}
	return;
}

countDown(10);