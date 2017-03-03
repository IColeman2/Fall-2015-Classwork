/**
*I Coleman
*icoleman@huskers.unl.edu
*9/30/2015
*Assignment 2, Problem 6:
*A program that decrypts  a message
*/

import java.util.Scanner;

public class AffineCipher {
	
	/*The function which takes the ASCII int value of an encrypted character and decrypts it into a character:*/
	public static char decrypt(int inverseAModuloN, int b, int y) {
		/*Change ASCII values into the values used in the Affine Cipher:*/
		if(y==32) {
			y=0;
		}
		else if(y==46) {
			y=27;
		}
		else if(y==33) {
			y=28;
		}
		else {
			y=y-64;
		}
		/*Use the decryption equation to find the int value of the actual character:*/
		int decryptedLetterValue = (inverseAModuloN*(y-b))%29;
		/*Return characters based on this value:*/
		if(decryptedLetterValue<0) {
			decryptedLetterValue+=29;
		}
		if(decryptedLetterValue==0) {
			return(' ');
		}
		else if(decryptedLetterValue==1) {
			return('A');
		}
		else if(decryptedLetterValue==2) {
			return('B');
		}
		else if(decryptedLetterValue==3) {
			return('C');
		}
		else if(decryptedLetterValue==4) {
			return('D');
		}
		else if(decryptedLetterValue==5) {
			return('E');
		}
		else if(decryptedLetterValue==6) {
			return('F');
		}
		else if(decryptedLetterValue==7) {
			return('G');
		}
		else if(decryptedLetterValue==8) {
			return('H');
		}
		else if(decryptedLetterValue==9) {
			return('I');
		}
		else if(decryptedLetterValue==10) {
			return('J');
		}
		else if(decryptedLetterValue==11) {
			return('K');
		}
		else if(decryptedLetterValue==12) {
			return('L');
		}
		else if(decryptedLetterValue==13) {
			return('M');
		}
		else if(decryptedLetterValue==14) {
			return('N');
		}
		else if(decryptedLetterValue==15) {
			return('O');
		}
		else if(decryptedLetterValue==16) {
			return('P');
		}
		else if(decryptedLetterValue==17) {
			return('Q');
		}
		else if(decryptedLetterValue==18) {
			return('R');
		}
		else if(decryptedLetterValue==19) {
			return('S');
		}
		else if(decryptedLetterValue==20) {
			return('T');
		}
		else if(decryptedLetterValue==21) {
			return('U');
		}
		else if(decryptedLetterValue==22) {
			return('V');
		}
		else if(decryptedLetterValue==23) {
			return('W');
		}
		else if(decryptedLetterValue==24) {
			return('X');
		}
		else if(decryptedLetterValue==25) {
			return('Y');
		}
		else if(decryptedLetterValue==26) {
			return('Z');
		}
		else if(decryptedLetterValue==27) {
			return('.');
		}
		else {
			return('!');
		}
	}
	/*A function to find the inverse of a%n:*/
	public static int findInverse(int a) {
		for(int j = 2; j<=29; j++) {
			if((a*j)%29==1) {
				return(j);
			}
		}
		return(0);
	}
	
	public static void main(String [] args) {
		int a=Integer.parseInt(args[0]);
		int b=Integer.parseInt(args[1]);
		System.out.printf("a    = %d\n", a);
		System.out.printf("b    = %d\n", b);
		
		int inverseAModuloN = (AffineCipher.findInverse(a));
		System.out.printf("a^-1 = %d\n", inverseAModuloN);
		
		System.out.printf("Encrypted Message: %s\n", args[2]);
		System.out.printf("Decrypted Message: ");
		
		char[] letters = args[2].toCharArray();
		
		/*A loop which decrypts and prints each letter in the code:*/
		for(int i=0; i<letters.length; i++) {
			int encryptedLetter = (int)(letters[i]);
			char decryptedLetter = AffineCipher.decrypt(inverseAModuloN, b, encryptedLetter);
			System.out.printf("%c", decryptedLetter);
		}
		
		System.out.printf("\n");
	}
}