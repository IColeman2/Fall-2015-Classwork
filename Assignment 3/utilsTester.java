/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/14/2015
*Assignment 3, Problem 3:
*A test driver program that demonstrates 3 test calls to each of the methods created in unl.cse.Utils
*/

package unl.cse;

public class utilsTester extends Utils{
	public static void main(String args[]){
		
		try{
			System.out.println("Degrees to radians trial 1: \nInput : 1180, \nOutPut: " + Utils.degreesToRadians(1180.00));
		} catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("Degrees to radians trial 2: \nInput : -360, \nOutPut: " + Utils.degreesToRadians(-360.00));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("Degrees to radians trial 3: \nInput : 180 \nOutPut: " + Utils.degreesToRadians(180.0));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("AnnualPercentageYield trail 1: \nInput : 1\nOutput: " + Utils.annualPercentageYield(2.00));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("AnnualPercentageYield trail 2: \nInput : .5\nOutput: " + Utils.annualPercentageYield(-0.50));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("AnnualPercentageYield trail 3: \nInput : 0\nOutput: " + Utils.annualPercentageYield(0.50));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("getAirDistance trial 1: \nInput:  75 , 100, 76, 101 \nOutput: " + Utils.getAirDistance(75.0 , 100.0, 76.0, 101.0));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("getAirDistance trial 2: \nInput:  0 , 0, 0, 0 \nOutput: " + Utils.getAirDistance(10.0, -10.0, 10.0, 10.0));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}try{
			System.out.println("getAirDistance trial 3: \nInput:  175 , 10, 6, 100 \nOutput: " + Utils.getAirDistance(1750.0 , 1000.0, 6.0, 100.0));
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		RGB rgb = new RGB(-1, 245, 245);
		CMYK cmyk = null;
		
		try{
			cmyk = Utils.rgbToCMYK(rgb);
			System.out.println("rgbToCMYK trial 1: \nInput:  -1, 245, 245\nOutput: " + cmyk.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}	
		
		rgb = new RGB(1, 1, 300);
		
		try{
			cmyk = Utils.rgbToCMYK(rgb);
			System.out.println("rgbToCMYK trial 2: \nInput:  1, 1, 300\nOutput: " + cmyk.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		rgb = new RGB(200, 98345, 55);
		
		try{
			cmyk = Utils.rgbToCMYK(rgb);
			System.out.println("rgbToCMYK trial 3: \nInput:  200, 98345, 55\nOutput: " + cmyk.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		cmyk = new CMYK(-1, 1, 1, 1);
		
		try{
			rgb = Utils.cmykToRGB(cmyk);
			System.out.println("cmykToRGB trial 1: \nInput:  -1, 1, 1, 1\nOutput: " + rgb.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}	
		
		cmyk = new CMYK(0, 5, 1, 0);
		
		try{
			rgb = Utils.cmykToRGB(cmyk);
			System.out.println("cmykToRGB trial 2: \nInput:  0, 5, 1, 0\nOutput: " + rgb.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}	
		
		cmyk = new CMYK(.125, .25, .95, .5);
		
		try{
			rgb = Utils.cmykToRGB(cmyk);
			System.out.println("toRGB trial 3: \nInput:  .125, .25, .95, .5\nOutput: " + rgb.toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}	
		
		rgb = new RGB(256, 255, 255);
		
		try{
			System.out.println("toGrayScale trial 1: \nInput: 256, 255, 255, LIGHTNESS\nOutput: " + Utils.toGrayScale(rgb, Mode.LIGHTNESS).toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		rgb = new RGB(-10, 1, 120);
		
		try{
			System.out.println("toGrayScale trial 2: \nInput: -10, 1, 120, LUMINOSITY\nOutput: " + Utils.toGrayScale(rgb, Mode.LUMINOSITY).toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		rgb = new RGB(5, 25, 200);
		
		try{
			System.out.println("toGrayScale trial 3: \nInput: 5, 25, 200, AVERAGE\nOutput: " + Utils.toGrayScale(rgb, Mode.AVERAGE).toString());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}