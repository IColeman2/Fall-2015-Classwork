#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv) {

  double a, b, c;
  int choice;

  printf("Enter operand a>");
  scanf("%lf", &a);

  printf("Enter operand b>");
  scanf("%lf", &b);

  printf("Enter operation:\n");
  printf("(1) Addition\n");
  printf("(2) Subtraction\n");
  printf("(3) Multiplication\n");
  printf("(4) Division\n");
  printf("(5) Minimum\n");
  printf("(6) Power\n");
  printf("(7) log_a(b)\n");
  scanf("%d", &choice);

  //TODO: process the results here
  if(choice==1) {
	  c=a+b;
  }
  else if(choice==2) {
	  c=a-b;
  }
  else if(choice==3) {
	  c=a*b;
  }
  else if(choice==4) {
	  if(b==0) {
		  printf("You cannot divide by zero!\n");
		  return 0;
	  }
	  else {
		  c=a/b;
	  }
  }
  else if(choice==5) {
	  if(a>b) {
		  c=b;
	  }
	  else {
		  c=a;
	  }
  }
  else if(choice==6) {
	  c=pow(a,b);
  }
  else {
	  if(a>0 && b>0) {
		  c=log(b)/log(a);
	  }
	  else {
		  printf("You cannot perform a logarithmic function with a negative operand!\n");
		  return 0;
	  }
	  
  }
  

  printf("Result: %lf\n", c);
  
  return 0;
}
