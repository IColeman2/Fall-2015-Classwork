/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/23/2015
*Assignment 5, Problem 3:
*A program that will parse and process a data file containing Comma Separated Values and produce an equivalent JavaScript Object Notation output file
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

public class CSVtoJSON {
	public static void main(String[] args){
		String InputName = args[0];
		String OutputName = args[1];
		File Input = new File(InputName);
		File Output = new File(OutputName);
		ArrayList<String> categories = new ArrayList<String>();
		String[][] data = new String[10000][10000];
		int i = 0;
		int j = 0;
		Scanner scan = null;
		try {
			scan = new Scanner(Input);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			throw new RuntimeException (e1);
		}
		
		//Gets the categories from the first line
		while(scan.hasNext()){
			String line = scan.nextLine();
			Scanner read = new Scanner(line);
			read.useDelimiter(",");
			if(i==0){
				while(read.hasNext()){
					categories.add(read.next());
				}
			}else{
				j=0;
				while(read.hasNext()){
					data[i-1][j] = read.next();
					j++;
				}
			}
			i++;
		}
		
		PrintWriter write = null;
		try {
			write = new PrintWriter(Output);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		int fileSize = i;
		write.println("[");
		for(i=0; i<fileSize-1; i++){
			write.println("\t{");
			for(j=0; j<categories.size(); j++){
				if(j == categories.size()-1){
					write.println("\t\t\"" +categories.get(j) +  "\": \""+ data[i][j] +"\"");
				}else{
					write.println("\t\t\"" +categories.get(j) +  "\": \""+ data[i][j] +"\",");
				}
			}
			if(i != fileSize-2){
				write.println("\t},");
			}else{
				write.println("\t}");
			}
		}
		write.println("]");
		write.close();
		scan.close();
	}
}
