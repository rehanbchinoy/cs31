Pointers:
another way to implement passing by reference
traverse arrays
manipulate dynamic storage
represent relationships in data structures

int main ()
{
	double r, angle;
	//... get values for r and angle
	double x, y;
	polarToCartesian(r, angle, x, y);

}

void polarTOCartesian(double rho, double theta, double& xx, double& yy) 
{ 
	xx = rho * cos(theta);
	yy = rho * sin(theta);
}

double& means-reference-to-double or another-name-for-some-double
double* means pointer-to-double or address-of-some-double

&x means "generate a pointer to x" or "address of x"
*p means "the object that p points to" or "follow the pointer p"

===================================================================================================================================================
int main ()
{
	double r, angle;
	//... get values for r and angle
	double x, y;
	polarToCartesian(r, angle, &x, &y);

}

void polarTOCartesian(double rho, double theta, double* xx, double* yy) 
{ 
	*xx = rho * cos(theta);
	*yy = rho * sin(theta);
}
===================================================================================================================================================
double a = 3.2;
double b = 5.1;
double* p = &a;

double c = a;
double d = *p; 
double* q = 7.6; //error!!
double d = p; //error!!

p = b; //error!!

*p = b; //assign one double to another
p = &b; // assign one pointer to another







