/**
*I Coleman and Sarah Kenny
*icoleman@huskers.unl.edu / skenny@huskers.unl.edu
*12/8/2015
*Assignment 6: Problem 2
*A Java class for a bank customer
*/

package unl.cse;

public class Customer {
	
	private String firstName;
	private String lastName;
	private String ssn;

	public Customer(String firstName, String lastName, String ssn) {
		super();
		this.firstName = firstName;
		this.lastName = lastName;
		this.ssn = ssn;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public String getSSN() {
		return ssn;
	}
	
}
