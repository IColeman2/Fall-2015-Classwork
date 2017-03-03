/**
*I Coleman and Sarah Kenny
*icoleman@huskers.unl.edu / skenny@huskers.unl.edu
*12/8/2015
*Assignment 6: Problem 2
*A Java class for a bank account with several useful methods
*/

package unl.cse;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Account {
	
	private String accountNumber;
	private double apr;
	private double balance;
	private Customer owner;
	
	//Comparators
	public static final Comparator<Account> byNumber = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			return a.accountNumber.compareTo(b.getAccountNumber());
		}
	};

    public static final Comparator<Account> byOwnerName = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			Customer aCustomer = a.getOwner();
			Customer bCustomer = b.getOwner();
			
			if(aCustomer.getFirstName()!=bCustomer.getLastName()) {
				return aCustomer.getLastName().compareTo(bCustomer.getLastName());
			}
			else {
				return aCustomer.getFirstName().compareTo(bCustomer.getFirstName());
			}
			
		}
	};
	
    public static final Comparator<Account> byOwnerSSN = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			Customer aCustomer = a.getOwner();
			Customer bCustomer = b.getOwner();
			return aCustomer.getSSN().compareTo(bCustomer.getSSN());
		}		
	};
	
    public static final Comparator<Account> byAPR = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			if(a.getAPR() < b.getAPR()){
				return(-1);
			}
			else if(a.getAPR() > b.getAPR()){
				return(1);
			}
			else{
				return(0);
			}
		}		
	};
	
    public static final Comparator<Account> byBalance = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			if(a.getBalance() < b.getBalance()){
				return(-1);
			}
			else if(a.getBalance() > b.getBalance()){
				return(1);
			}
			else{
				return(0);
			}
		}		
	};
	
    public static final Comparator<Account> byBalanceDesc = new Comparator<Account>() {
		@Override
		public int compare(Account a, Account b) {
			return -byBalance.compare(a, b);
		}		
	};

    
    public static final Filter<Account> filterBalance = new Filter<Account>() {
	@Override
		public boolean filter(Account item) {
			if(item.getBalance() <= 250000) {
			return true;
			} else {
			return false;
			}
		}		
    };

    public static final Filter<Account> filterZeroBalance = new Filter<Account>() {
		public boolean filter(Account item) {
			if(item.getBalance() == 0) {
			return true;
			} else {
			return false;
			}
		}
	};
	
    public static final Filter<Account> filterHighYield = new Filter<Account>() {
		public boolean filter(Account item) {
			if(item.getAPR() >= 0.05) {
			return true;
			} else {
			return false;
			}
		}
	};
	
	public String toString(){
		return new StringBuilder(accountNumber)
			.append("\n")
			.append(owner.toString())
			.append("\n")
			.append(balance)
			.append("\n")
			.append(apr)
			.append("\n")
			.toString();
	}
	
    public Account(String accountNumber, double apr, double balance, Customer owner) {
		super();
		this.accountNumber = accountNumber;
		this.apr = apr;
		this.balance = balance;
		this.owner = owner;
    }
	
	//Getters:
	public String getAccountNumber() {
		return accountNumber;
	}
	
	public double getAPR() {
		return apr;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public Customer getOwner() {
		return owner;
	}
	
	//Computes the monthly interest for the given account
    public double getMonthlyInterest() {
		double monthlyInterest = balance*(apr/12.0);
		monthlyInterest = Math.floor(monthlyInterest*100.0+.5);
		monthlyInterest/=100.0;
		return(monthlyInterest);
    }

	//Computes the annual interest for the given account
    public double getAnnualInterest() {
		double apy = Math.pow(Math.E, apr) - 1;
		double interest = (balance)*(apy);
		interest = Math.floor(interest*100.0+.5);
		interest /= 100.0;
		return(interest);
    }

	//Makes a deposit to the account by adding the given amount to the account's balance.
    public void makeDeposit(double amount) {
		balance+=amount;
    }

    public static void sortAccounts(List<Account> accounts, Order order) {
		if(order == Order.ACCT_NUMBER){
			Collections.sort(accounts, byNumber);
		}
		else if(order == Order.OWNER){
			Collections.sort(accounts, byOwnerName);
		}
		else if(order == Order.OWNER_SSN){
			Collections.sort(accounts, byOwnerSSN);
		}
		else if(order == Order.APR){
			Collections.sort(accounts, byAPR);
		}
		else if(order == Order.BALANCE){
			Collections.sort(accounts, byBalance);
		}
		else if(order == Order.BALANCE_DESC){
			Collections.sort(accounts, byBalanceDesc);
		}
		else{
			System.out.printf("invalid input");
		}
    }
	
	//Filters the given list of Accounts and returns a new list containing elements in the list that meet the criteria defined by the filter function.
    public static List<Account> filter(List<Account> accounts, Filter<Account> f) {
		List<Account> filteredList = new ArrayList<Account>();
		
		for(int i = 0; i<accounts.size(); i++) {
			if(f.filter(accounts.get(i))){
				filteredList.add(accounts.get(i));
			}
		}
		return filteredList;
    }

	//Returns the maximum element in the list "items" according to the passed comparator function.
    public static <T> T getMax(List<T> items, Comparator<T> comp) {
		Collections.sort(items, comp);
		return(items.get(items.size()-1));
    }
}
