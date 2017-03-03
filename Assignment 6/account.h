/**
*I Coleman and Sarah Kenny
*icoleman@huskers.unl.edu / skenny@huskers.unl.edu
*12/2/2015
*Assignment 6: Problem 1
*Prototyping structures and functions which use those structures
*/

/**
 * A structure to model a Customer
 */
typedef struct {
   char *firstName;
   char *lastName;
   char *SSN;
} Customer;

/**
 * A structure to model an Account
 */
typedef struct {
	char *accountNum; //string b/c of hyphens
	double APR;
	double balance;
	const Customer *custName;
} Account;

/**
 * An enumeration detailing the supported ordering
 * of Accounts
 */
typedef enum {
  ACCT_NUMBER,
  OWNER,
  OWNER_SSN,
  APR,
  BALANCE,
  BALANCE_DESC,  
} Order;

/**
 * A "builder" function to construct a Customer instance
 */
Customer * createCustomer(const char *firstName, const char *lastName, const char *ssn);

/**
 * A "builder" function to construct an Account instance
 */
Account *createAccount(const char *acctNumber, double apr, double balance, const Customer *owner);

/**
 * A function that creates a human-readable string representation of the account
 */
char *accountToString(const Account *a);

/**
 * A comparator function that orders Accounts by their
 * account number
 */
int cmpAccountByNumber(const void*s1, const void*s2);
/**
 * A comparator function that orders Accounts by their
 * owner's name (last/first)
 */
int cmpAccountByOwnerName(const void*s1, const void*s2);
/**
 * A comparator function that orders Accounts by their
 * owner's Social Security Number
 */
int cmpAccountByOwnerSSN(const void*s1, const void*s2);
/**
 * A comparator function that orders Accounts by their
 * Annual Percentage Rate
 */
int cmpAccountByAPR(const void*s1, const void*s2);
/**
 * A comparator function that orders Accounts by their
 * Balance (smallest to largest)
 */
int cmpAccountByBalance(const void*s1, const void*s2);
/**
 * A comparator function that orders Accounts by their
 * Balance (largest to smallest)
 */
int cmpAccountByBalanceDesc(const void*s1, const void*s2);

/**
 * A function that sorts the given array of Accounts (containing
 * n elements) according to the specified Order
 */
void sortAccounts(Account *accounts, int n, Order order);

/**
 * Computes the monthly interest for the given account
 */
double getMonthlyInterest(const Account *a);

/**
 * Computes the annual interest for the given account
 */
double getAnnualInterest(const Account *a);

/**
 * Makes a deposit to the account by adding the given
 * amount to the account's balance.
 */
void makeDeposit(Account *a, double amount);

/**
 * This function is used to filter Accounts based on 
 * their balance.  If the balance exceeds $250,000
 * it returns false (it is not FDIC insured); if the
 * balance is 250,000 or less, it returns true
 */
int filterBalance(const void *a);

/**
 * This function is used to filter Accounts with
 * a zero balance (in which case it returns true); 
 */
int filterZeroBalance(const void *a);

/**
 * This function is used to filter Accounts with
 * a high yield APR.  If the APR is 5% or greater, 
 * this function returns true, otherwise it returns
 * false.
 */
int filterHighYield(const void *a);

/**
 * Filters the given array of Accounts and returns a new
 * array containing elements in the array that meet the criteria
 * defined by the filter function.  The size of the resulting
 * array is communicated using the resultSize variable.
 *
 * The filter function (filterFunc) only takes one element
 * and returns true if the element should be included in the
 * result and false otherwise.  Like a comparator function, 
 * it is generic, taking a void pointer
 */
Account * filter(const Account *accounts, int numElements, int (*filterFunc)(const void *), int *resultSize);

/**
 * Returns the maximum element in the array base
 * (with numElements each being a number of bytes equal to size)
 * according to the passed comparator function.
 */
void * getMax(void *base, size_t numElements, size_t size, int (*compar)(const void *, const void *));

