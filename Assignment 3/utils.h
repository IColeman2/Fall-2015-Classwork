//specifies the mode to be used by toGrayScale
typedef enum {
	AVERAGE,
	LIGHTNESS,
	LUMINOSITY
} Mode;

//a function to convert degrees to radians
int degreesToRadians(double degree, double *radians);

//a function to compute the annual percentage yield given an annual percentage rate
int annualPercentageYield(double apr, double *apy);

//a function to compute the air distance between two locations given their latitude and longitude
int getAirDistance(double latA, double longA, double latB, double longB, double *distance);

//a function to convert from an RGB color model to a CMYK model
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

//a function to convert from CMYK to RGB
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

//a function that takes an RGB color value and transforms it to a grayscale version
int toGrayScale(int *r, int *g, int *b, Mode m);
