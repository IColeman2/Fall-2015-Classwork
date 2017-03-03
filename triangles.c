#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {

  if(argc != 4) {
    fprintf(stderr, "Usage: %s a b c (three lengths of a triangle)\n", argv[0]);
    exit(1);
  }

  double a, b, c;
  a = atof(argv[1]);
  b = atof(argv[2]);
  c = atof(argv[3]);

  //TODO: complete the program
  
  if(a+b>c && b+c>a && c+a>b) {
	  if(a==b && b==c) {
	  printf("This is a valid equilateral triangle!\n");
  }
      else if(a==b || b==c || a==c) {
	  printf("This is a valid isoceles triangle!\n");
  }   
      else {
	  printf("This is a valid scalene triangle!\n");
  }
  }
  else {
	  printf("The triangle is not valid.\n");
  }
  return 0;
}

