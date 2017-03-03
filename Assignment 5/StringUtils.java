/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/19/2015
*Assignment 5, Problem 4:
*A java version of string_utils.c
*/

import java.util.Scanner;
import java.io.File;

public class StringUtils {

	//A function that replaces special characters in a string with their HTML entities
    public static String scrubHTML(String s) {
	
		int i;
		String result = "";
		for(i = 0; i<s.length(); i++) {
			if(s.charAt(i)=='&') {
				result += "&amp;";
			}
			else if(s.charAt(i)=='<') {
				result+="&lt;";
			}
			else if(s.charAt(i)=='>') {
				result+="&gt;";
			}
			else if(s.charAt(i)=='"') {
				result+="&quot;";
			}
			else {
				result+=s.charAt(i);
			}
		}
		
		return result;
    }

	//A version that escapes special characters UNLESS they are already escaped
    public static String smartScrubHTML(String s) {
	
		int i;
		String result = "";
		for(i = 0; i<s.length(); i++) {
			if(s.charAt(i)=='&') {
				if (isAlreadyEscaped(s, i)==true) {
					result+=s.charAt(i);
				}
				else {
					result += "&amp;";
				}
			}
			else if(s.charAt(i)=='<') {
				result+="&lt;";
			}
			else if(s.charAt(i)=='>') {
				result+="&gt;";
			}
			else if(s.charAt(i)=='"') {
				result+="&quot;";
			}
			else {
				result+=s.charAt(i);
			}
		}
		
		return result;
    }
	
	//A function (not required by the assignment) that checks if a special character is already escaped for use in smartScrubHTML
	public static boolean isAlreadyEscaped(String s, int i) {
		if(s.charAt(i+1)=='a'
		   &&s.charAt(i+2)=='m'
		   &&s.charAt(i+3)=='p'
		   &&s.charAt(i+4)==';') {
			   return true;
		}
		if(s.charAt(i+1)=='l'
		   &&s.charAt(i+2)=='t'
		   &&s.charAt(i+3)==';') {
			   return true;
		}
		if(s.charAt(i+1)=='g'
		   &&s.charAt(i+2)=='t'
		   &&s.charAt(i+3)==';') {
			   return true;
		}
		if(s.charAt(i+1)=='q'
		   &&s.charAt(i+2)=='u'
		   &&s.charAt(i+3)=='o'
		   &&s.charAt(i+4)=='t'
		   &&s.charAt(i+5)==';') {
			   return true;
		}
		return false;
	}
	
	//A method which removes leading and trailing whitespace from a string
	public static String trim(String s) {
		
		int i = 0;
		while(Character.isWhitespace(s.charAt(i))) {
			i++;
		}

		int j = s.length()-1;
		while(Character.isWhitespace(s.charAt(j))) {
			j--;
		}
		
		String result = "";
		
		int k;
		for(k=i; k<j+1; k++) {
			result+=s.charAt(k);
		}
		
		return result;
    }
	
	//A method which reformats a string representing a telephone number
    public static String formatPhoneNumber(String phone) {
		String result = "(";
		
		int i;
		int resultCounter = 1;

		//dealing with the special case where a phone number has 11 digits (1-###-###-####)
		//The following works because area codes in the North American Numbering Plan cannot begin with 0 or 1
		//Therefore, if a US phone number starts with 1, it is the special case
		if(phone.charAt(0)=='1'){
			//simply start finding digits after the 1
			for(i=1; i<phone.length(); i++) {
				
				if(Character.isDigit((int)phone.charAt(i))==true) {
					result+=phone.charAt(i);
					resultCounter++; 

					if(resultCounter==4) {
						result+= ')';
						result+= ' ';
						resultCounter+=2; 
					}
					if(resultCounter==9) {
						result+= '-';
						resultCounter++;   					
					}
				}
			}
			
			return result;
		}
		
		else {
			for(i=0; i<phone.length(); i++) {
				
				if(Character.isDigit((int)phone.charAt(i))==true) {
					result+=phone.charAt(i);
					resultCounter++; 

					if(resultCounter==4) {
						result+= ')';
						result+= ' ';
						resultCounter+=2; 
					}
					if(resultCounter==9) {
						result+= '-';
						resultCounter++;   					
					}
				}
			}
			
			return result;
		}
    }
	
	//A method which computes the size of a file in bytes:
    public static int getFileSize(String fileName) {
		File file = new File(fileName);
		int fileSize = 0;
		int numberOfLines = 0;
		try (Scanner s = new Scanner(file)) {
			String line;
			while(s.hasNextLine()) {
				line = s.nextLine();
				fileSize+=line.length();
				numberOfLines++;
			}
			fileSize+=numberOfLines;
		} catch (Exception e) {
		}
		
		return fileSize;
    }
	//A method which retrieves the contents of a file given the file name as a string
    public static String getFileContents(String fileName) {
		File file = new File(fileName);
		String result = "";
		
		try (Scanner s = new Scanner(file)) {
			String line;
			while(s.hasNextLine()) {
				line = s.nextLine();
				result+=line;
				result+="\n";
			}
		} catch (Exception e) {
		}
		
		return result;
	}
}



