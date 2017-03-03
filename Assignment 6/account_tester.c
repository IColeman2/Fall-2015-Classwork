#include "account.c"

//array tester

int main(int argc, char **argv){
	//Customer testCustomer;
	//testCustomer.firstName = "Chris";
	//testCustomer.lastName = "Bourke";
	//testCustomer.SSN = "123-45-6789";
	
	//Account testAccount;
	//testAccount.accountNum = "8654-2358";
	//testAccount.APR = 0.05;
	//testAccount.balance = 50000;
	//testAccount.custName = testCustomer;
	
	Customer *testCustomer = createCustomer("Chris", "Bourke", "8654-2358");
	printf("firstName: %s, lastName: %s, SSN: %s\n\n", testCustomer->firstName, testCustomer->lastName, testCustomer->SSN);
	
	Account *testAccount = createAccount("8654-2358", 0.05, 50000, testCustomer);
	printf("Success.\n");
	
	printf("accountNum: %s, APR: %f, balance: %f\n\n", testAccount->accountNum, testAccount->APR, testAccount->balance);
	
	char *testString1 = accountToString(testAccount);
	printf("%s\n", testString1);
	
	Customer *testCustomer2 = createCustomer("Bailey", "Bourke", "1234-5678");
	Account *testAccount2 = createAccount("1234-5678", 0.77, 2, testCustomer2);
	int testint1 = cmpAccountByNumber(testAccount, testAccount2);
	printf("%d\n\n", testint1);
	
	int testint2 = cmpAccountByOwnerName(testAccount, testAccount2);
	printf("%d\n\n", testint2);
	
	int testint3 = cmpAccountByAPR(testAccount, testAccount2);
	printf("%d\n\n", testint3);
	
	int testint4 = cmpAccountByBalance(testAccount, testAccount2);
	printf("%d\n\n", testint4);

	int testint5 = cmpAccountByBalanceDesc(testAccount, testAccount2);
	printf("%d\n\n", testint5);
	
	//getMonthlyInterest is working
	//getAnnualInterest is working
	
	makeDeposit(testAccount2, 1);
	printf("accountNum: %s, APR: %f, balance: %f\n\n", testAccount2->accountNum, testAccount2->APR, testAccount2->balance);
	
	if(filterZeroBalance(testAccount2)){
		printf("True\n\n");
	}
	else{
		printf("False\n\n");
	}
	
	if(filterHighYield(testAccount2)){
		printf("True\n\n");
	}
	else{
		printf("False\n\n");
	}
	Account *testAccounts = 
	
	filter(const Account *accounts, int numElements, int (*filterFunc)(const void *), int *resultSize)
	
	return 0;
}