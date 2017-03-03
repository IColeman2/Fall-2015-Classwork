/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/15/2015
*Assignment 3, Problem 4:
*Pressure conversion method in Java:
*/

package unl.cse;

public class PressureUtils {
	public static Double convertPressure(Double v, Scale inputScale, Scale outputScale){
		
		if(v == null){
			throw new NullPointerException("Null pressure value");
		}
		
		if(inputScale == null || outputScale == null){
			throw new NullPointerException("Null scale value");
		}
		
		if(v < 0){
			throw new NullPointerException("Input values must be positive");
		}
		
		if(inputScale == Scale.PASCAL){
			if(outputScale == Scale.PSI){
				return v/6894.75729;
			}else if(outputScale == Scale.ATM){
				return v/101325.0;
			}else if(outputScale == Scale.TORR){
				return v*(760.0/101325.0);
			}else if(outputScale == Scale.PASCAL){
				return v;
			}else{
				throw new InvalidPressureException("Invalid output scale");
			}
			
		}else if(inputScale == Scale.PSI){
			if(outputScale == Scale.PASCAL){
				return v*6894.75729;
			}else if(outputScale == Scale.ATM){
				return v * 0.0680459639;
			}else if(outputScale == Scale.TORR){
				return v*760.0*0.06804596387861;
			}else if(outputScale == Scale.PSI){
				return v;
			}else{
				throw new InvalidPressureException("Invalid output scale");
			}
			
		}else if(inputScale == Scale.ATM){
			if(outputScale == Scale.PSI){
				return v/0.06804596387861;
			}else if(outputScale == Scale.PASCAL){
				return v*101325.0;
			}else if(outputScale == Scale.TORR){
				return v*760.0;
			}else if(outputScale == Scale.ATM){
				return v;
			}else{
				throw new InvalidPressureException("Invalid output scale");
			}
			
		}else if(inputScale == Scale.TORR){
			if(outputScale == Scale.PSI){
				return v/(760.0*0.0680459639);
			}else if(outputScale == Scale.ATM){
				return v / 760.0;
			}else if(outputScale == Scale.PASCAL){
				return v * 101325/760;
			}else if(outputScale == Scale.TORR){
				return v;
			}else{
				throw new InvalidPressureException("Invalid output scale");
			}
			
		}else{
			throw new InvalidPressureException("Invalid input scale");
		}
	}
}
