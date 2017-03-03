#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  double agi;
  char c;
  double tax;
  double childCredit;
  double totalTax;
  int numberOfChildren = 0;

  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);

  printf("Do you have any children? (Y) or (N)? ");
  getchar(); //remove the endline character
  c = getchar();
  if(c=='y' || c=='Y') {
	  printf("How many children do you have?");
	  scanf("%d", &numberOfChildren);
  }

  childCredit=1000*numberOfChildren;
  
  //compute the tax, child credit, and total tax:
  if(agi>0 && agi<17000) {
	  tax = agi*.1;
  }
  else if(agi>=17000 && agi<69000) {
	  tax = 1700+(agi-17000)*.15;
  }
  else if(agi>=69000 && agi<139350) {
	  tax = 9500+(agi-69000)*.25;
  }
  else if(agi>=139350 && agi<212300) {
	  tax = 27087.50+(agi-139350)*.28;
  }
  else if(agi>=212300 && agi<379150) {
	  tax = 47513.5+(agi-212300)*.33;
  }
  else {
	  tax = 102574+(agi-379150)*.35;
  }
 
  totalTax=tax-childCredit;
  
  if(totalTax<0) {
	  totalTax=0;
  }
  
  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("totalTax:     $%10.2f\n", totalTax);

  return 0;
}
