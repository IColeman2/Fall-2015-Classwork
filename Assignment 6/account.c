/**
*I Coleman and Sarah Kenny
*icoleman@huskers.unl.edu / skenny@huskers.unl.edu
*12/2/2015
*Assignment 6: Problem 1
*Definitions of the functions defined in accounts.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "account.h"

//A "builder" function to construct a Customer instance
Customer * createCustomer(const char *firstName, const char *lastName, const char *ssn){

    Customer *newCustomer = (Customer *) malloc(sizeof(Customer));
    int firstNameLen = strlen(firstName)+1;
    int lastNameLen = strlen(lastName)+1;

    newCustomer->firstName = (char *) malloc(sizeof(char) * (firstNameLen));
    strcpy(newCustomer->firstName, firstName);

    newCustomer->lastName = (char *) malloc(sizeof(char) * (lastNameLen));
    strcpy(newCustomer->lastName, lastName);

    newCustomer->SSN = (char *) malloc(sizeof(char) * 12);
    strcpy(newCustomer->SSN, ssn);

    return newCustomer;
}

//A "builder" function to construct an Account instance
Account *createAccount(const char *acctNumber, double apr, double balance, const Customer *owner) {
    
    Account *result = NULL;
    result = (Account *) malloc(sizeof(Account));
    
    int lengthOfAcctNum = strlen(acctNumber)+1;
    result->accountNum = (char *)malloc(sizeof(char) * (lengthOfAcctNum));
    strcpy(result->accountNum, acctNumber);
    
    result->APR = apr;
    result->balance = balance;
    result->custName = owner;
    
    return result;
}

//A function, NOT REQUIRED BY THE ASSIGNMENT, which creates a string representation of a customer
char *customerToString(const Customer *c) {
    char *firstNameString = (char *)malloc(sizeof(char) * (strlen(c->firstName)+1));
    sprintf(firstNameString, "%s", c->firstName);
    
    char *lastNameString = (char *)malloc(sizeof(char) * (strlen(c->lastName)+1));
    sprintf(lastNameString, "%s", c->lastName);
    
    char *ssnString = (char *)malloc(sizeof(char) * (strlen(c->SSN)+1));
    sprintf(ssnString, "%s", c->SSN);
    
    int resultLength = strlen(firstNameString) + strlen(lastNameString) + strlen(ssnString) + 4;
    char *result = (char *)malloc(sizeof(char) * (resultLength));
    sprintf(result, "%s\n%s\n%s\n", firstNameString, lastNameString, ssnString);
	result[resultLength-1]='\0';
	
	free(firstNameString);
	free(ssnString);
	free(lastNameString);
    return result;
}

//A function that creates a human-readable string representation of the account
char *accountToString(const Account *a){
	/*char* h = malloc(6 * sizeof(char));
	strcpy(h, "hello");
	h[5] = '\0';
	return h;
	*/
	char *acctNumberString = (char *)malloc(sizeof(char) * (strlen(a->accountNum)+1));
	sprintf(acctNumberString, "%s", a->accountNum);
	
	char *aprString = (char *)malloc(sizeof(char) * (5));
	sprintf(aprString, "%.2f", a->APR);
	
	//initializing string to 4 accounts for decimal, numbers after decimal, and null terminating character
	int balanceStringSize = 4;
	int i;
	for(i = 1; i < a->balance; i*=10){
		balanceStringSize++;
	}
	
	char *balanceString = (char *)malloc(sizeof(char) * (balanceStringSize));
	sprintf(balanceString, "%.2f", a->balance);	
	
	const char *customer = customerToString(a->custName);
	char *customerString = (char *)malloc((strlen(customer)+1)*sizeof(char));
	strcpy(customerString, customer);
	
	int resultLength = strlen(acctNumberString) + strlen(aprString) + strlen(balanceString) + strlen(customerString) + 5;
	char *result = (char *)malloc(sizeof(char) * resultLength);
	
	sprintf(result, "%s\n%s\n%s\n%s\n", acctNumberString, aprString, balanceString, customerString);
	result[resultLength-1]='\0';
	
	free(acctNumberString);
	free(aprString);
	free(balanceString);
	free(customer);
	free(customerString);
	
	return result;
}

//A comparator function that orders accounts by their account number
int cmpAccountByNumber(const void*s1, const void*s2) {
    const Account *a1 = s1;
    const Account *a2 = s2;
    return strcmp(a1->accountNum, a2->accountNum);
    //Removing the hyphens from the first account number
    char *a1AcctNumTemp = (char *) malloc(sizeof(char) * strlen(a1->accountNum)+1);
    
    int i;
    int resultCounter = 0;
    
    for(i=0; i<strlen(a1->accountNum); i++) {
        
        if(isdigit(a1->accountNum[i])) {
            a1AcctNumTemp[resultCounter]=a1->accountNum[i];
            resultCounter++;
        }
    }
    a1AcctNumTemp[resultCounter] = '\0';
    
    char *a1AcctNumString = (char *) malloc(sizeof(char) * resultCounter);
    strcpy(a1AcctNumString, a1AcctNumTemp);
    
    free(a1AcctNumTemp);
    
    //Removing the hyphens from the second account number
    
    char *a2AcctNumTemp = (char *) malloc(sizeof(char) * strlen(a2->accountNum)+1);
    resultCounter = 0;
    
    for(i=0; i<strlen(a2->accountNum); i++) {
        
        if(isdigit(a2->accountNum[i])) {
            a2AcctNumTemp[resultCounter]=a2->accountNum[i];
            resultCounter++;
        }
    }
    a2AcctNumTemp[resultCounter] = '\0';
    
    char *a2AcctNumString = (char *) malloc(sizeof(char) * resultCounter);
    strcpy(a2AcctNumString, a2AcctNumTemp);
    
    free(a2AcctNumTemp);
    
    //Changing these hyphen-less strings into ints and comparing
    int a1AcctNum = atoi(a1AcctNumString);
    int a2AcctNum = atoi(a2AcctNumString);
    if(a1AcctNum<a2AcctNum) {
        return (0-1);
    }
    else if(a1AcctNum>a2AcctNum) {
        return (1);
    }
    else {
        return 0;
    }
}

//A comparator function that orders Accounts by their owner's name

int cmpAccountByOwnerName(const void*s1, const void*s2){ //TODO: Endline characters
	const Account *a1 = s1;
    const Account *a2 = s2;
	
	const Customer *a1Customer = a1->custName;
	char *custLastName1 = a1Customer->lastName;
	char *custFirstName1 = a1Customer->firstName;
	
	const Customer *a2Customer = a2->custName;
	char *custLastName2 = a2Customer->lastName;
	char *custFirstName2 = a2Customer->firstName;
	
	if(strcmp(custLastName1, custLastName2)!=0){
		return(strcmp(custLastName1, custLastName2));
	}
	else{
		return(strcmp(custFirstName1, custFirstName2));
	}
}

//A comparator function that orders Accounts by their owner's Social Security Number
int cmpAccountByOwnerSSN(const void*s1, const void*s2){
	const Account *a1 = s1;
    const Account *a2 = s2;
    
    //Removing the hyphens from the first account number
    char *a1ssnTemp = (char *) malloc(sizeof(char) * strlen(a1->custName->SSN)+1);
    
    int i;
    int resultCounter = 0;
    
    for(i=0; i<strlen(a1->custName->SSN); i++) {
        
        if(isdigit(a1->custName->SSN[i])) {
            a1ssnTemp[resultCounter]=a1->custName->SSN[i];
            resultCounter++;
        }
    }
    a1ssnTemp[resultCounter] = '\0';
    
    char *a1ssnString = (char *) malloc(sizeof(char) * resultCounter);
	a1ssnString[0] = '\0';
    strcpy(a1ssnString, a1ssnTemp);
    
    free(a1ssnTemp);
    
    //Removing the hyphens from the second account number
    
    char *a2ssnTemp = (char *) malloc(sizeof(char) * strlen(a2->custName->SSN)+1);
    resultCounter = 0;
    
    for(i=0; i<strlen(a2->custName->SSN); i++) {
        
        if(isdigit(a2->custName->SSN[i])) {
            a2ssnTemp[resultCounter]=a2->custName->SSN[i];
            resultCounter++;
        }
    }
    a2ssnTemp[resultCounter] = '\0';
    
    char *a2ssnString = (char *) malloc(sizeof(char) * resultCounter);
	a2ssnString[0] = '\0';
    strcpy(a2ssnString, a2ssnTemp);
	
    free(a2ssnTemp);
    
    //Changing these hyphen-less strings into ints and comparing
    int a1ssn = atoi(a1ssnString);
    int a2ssn = atoi(a2ssnString);
    if(a1ssn<a2ssn) {
        return (0-1);
    }
    else if(a1ssn>a2ssn) {
        return (1);
    }
    else {
        return 0;
    }    
}

//A comparator function that orders Accounts by their APR
int cmpAccountByAPR(const void*s1, const void*s2){
	const Account *a1 = s1;
    const Account *a2 = s2;
	
	double a1apr = a1->APR;
	double a2apr = a2->APR;
	
	if(a1apr < a2apr){
		return(0-1);
	}
	else if(a1apr > a2apr){
		return(1);
	}
	else{
		return(0);
	}
}

//A comparator function that orders accounts by their balance in ascending order
int cmpAccountByBalance(const void*s1, const void*s2){
	const Account *a1 = s1;
    const Account *a2 = s2;
	
	double a1balance = a1->balance;
	double a2balance = a2->balance;
	
	if(a1balance < a2balance){
		return(0-1);
	}
	else if(a1balance > a2balance){
		return(1);
	}
	else{
		return(0);
	}
}

//A comparator function that orders accounts by their balance in descending order
int cmpAccountByBalanceDesc(const void*s1, const void*s2){
	const Account *a1 = s1;
    const Account *a2 = s2;
	
	double a1balance = a1->balance;
	double a2balance = a2->balance;
	
	if(a1balance < a2balance){
		return(1);
	}
	else if(a1balance > a2balance){
		return(0-1);
	}
	else{
		return(0);
	}
}

//TODO: A function that sorts the given array of Accounts (containing n elements) according to the specified Order
void sortAccounts(Account *accounts, int n, Order order){
	if(order == ACCT_NUMBER){
		qsort(accounts, n, sizeof(Account),cmpAccountByNumber);
	}
	else if(order == OWNER){
		qsort(accounts, n, sizeof(Account),cmpAccountByOwnerName);
	}
	else if(order == OWNER_SSN){
		qsort(accounts, n, sizeof(Account),cmpAccountByOwnerSSN);
	}
	else if(order == APR){
		qsort(accounts, n, sizeof(Account),cmpAccountByAPR);
	}
	else if(order == BALANCE){
		qsort(accounts, n, sizeof(Account),cmpAccountByBalance);
	}
	else if(order == BALANCE_DESC){
		qsort(accounts, n, sizeof(Account),cmpAccountByBalanceDesc);
	}
	else{
		printf("invalid input");
	}
}

//Computes the monthly interest for the given account
double getMonthlyInterest(const Account *a){
	double monthlyInterest = a->balance*(a->APR/12.0);
	monthlyInterest = floor(monthlyInterest*100.0+.5);
	monthlyInterest/=100.0;
	return(monthlyInterest);
}

//Computes the annual interest for the given account
double getAnnualInterest(const Account *a){
	double apy = pow(M_E, (a->APR)) - 1;
	double interest = (a->balance)*(apy);
	interest = floor(interest*100.0+.5);
	interest /= 100.0;
	return(interest);
}

//Makes a deposit to the account by adding the given amount to the account's balance.
void makeDeposit(Account *a, double amount) {
	a->balance+=amount;
}

//filters Accounts based on their balance.  If the balance exceeds $250,000 it returns false (it is not FDIC insured), else, true
int filterBalance(const void *a) {
	const Account *account = a;
	
	if(account->balance > 250000.0){
		return(0);
	}
	else{
		return(1);
	}
}

//This function is used to filter Accounts with a zero balance (in which case it returns true)
int filterZeroBalance(const void *a) {
	const Account *account = a;
	
	if(account->balance == 0){
		return(1);
	}
	else{
		return(0);
	}
}

//This function is used to filter Accounts with a high yield APR.  If the APR is 5% or greater, this function returns true.
int filterHighYield(const void *a) {
	const Account *account = a;
	
	if(account->APR < 0.05){
		return(0);
	}
	else{
		return(1);
	}
}

//Filters the given array of Accounts and returns a new array containing elements in the array that meet the criteria defined by the filter function.  
Account * filter(const Account *accounts, int numElements, int (*filterFunc)(const void *), int *resultSize){
	
	*resultSize = 0;
	int index = 0;
	int i;
	
	for(i = 0; i < numElements; i++){
		if(filterFunc(&accounts[i])){
			(*resultSize)++;
		}	
	}
	
	Account *filteredArray = (Account *) malloc(sizeof(Account) * (*resultSize));
	for(i = 0; i < numElements; i++){
		if(filterFunc(&accounts[i])){
			filteredArray[index] = accounts[i];
			index++;	
		}	
	}
	return(filteredArray);
}

//Returns the maximum element in the array base according to the passed comparator function.
void * getMax(void *base, size_t numElements, size_t size, int (*compar)(const void *, const void *)){
	qsort(base, numElements, size, compar);
	return(&base[size * (numElements-1)]);
}


