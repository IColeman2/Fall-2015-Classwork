typedef enum{
	PASCAL, 
	PSI, 
	ATM, 
	TORR} Scale;
	
typedef enum{
	NO_ERROR,
	NEGATIVE_PRESSURE_VALUE,
	NULL_POINTER, 
	INVALID_SCALE} Error;
	
int convertPressure(double *pa, double *psi, double *atm, double *torr, Scale scale);
