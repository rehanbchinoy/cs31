============================================================================================================================
MONDAY
============================================================================================================================
string s = "Hello";
for (int k = 0; k!= s.size(); k++)
	cout << s[k] << endl;

============================================================================================================================

cout << "Enter some text: ";
string t;
getline(cin, t);

int numberOfEs = 0;
for (int k = 0; k!= t.size(); k++)
{
	if (t[k] == 'E' || t[k] == 'e')
		numberOfEs++;
}
cout << "The number of E's (upper and lower case) is " << numberOfEs << endl;

============================================================================================================================

string s = "Hello"; //s is a string; "Hello" is a string literal
char ch = s[1]; //ch is a char (initialized to a lower case e)
// 'E' is a character constant

char c = 'x'; //OK
char c = "x"; //Compile error
string s = "x"; //OK
string s ='x'; //compile error

============================================================================================================================

#include <iostream>
#include <string>
using namespace std;

cout << "Enter a phone number: ";
string num;
getline (cin, num);

int numberOfDigits = 0;
for (int k = 0; k!= num.size(); k++)
{
	if (isdigit(num[k]))
		numberOfDigits++;
}
if (numberOfDigits != 10)
	cout << "A phone number must contain 10 digits." << endl;

============================================================================================================================

isdigit(ch) '0' '1' ... '9' ;
islower(ch) 'a' ...'z' ;
isupper(ch) 'A' ... 'Z' ;
isalpha(ch) 'a' ... 'z'  'A' ... 'Z' ;

if (! isdigit(ch))
	cout << "It's not a digit character" << endl;

if (! (x >= 1 && x <= 10))
	cout << "x is not in the range 1 through 10" << endl;

if (x < 1 || x > 10)
	cout << "x is not in the range 1 through 10" << endl;

string s;
getline(cin, s);
if (s.size() > 0)				s!= ""
	s[0] = toupper(s[0]);

char ch = toupper(s[0]);

if (s[0] == 'E' || s[0] == 'e')
if(toupper(s[0]) == 'E')

Mistake:
string s = "Hello";
.... toupper(s) .... //Compile error

toupper(s[0]); //will compile, but doesn't do anything

============================================================================================================================

int main ()
{
	for (int k = 0; k < 3; k++)
		cout << "Hello" << endl;

	for (int k = 0; k < 3; k++)
		cout << "Hello" << endl;

	for (int k = 0; k < 3; k++)
		cout << "Hello" << endl;
}	

============================================================================================================================

void greet(); //function prototype
int square(int k);

int main ()
{
	greet(3, "Hello");

	int a = 4;
	greet(2*a-1, "Ni hao");

	string s;
	getline(cin, s);
	greet(1, s);

	cout << square(a-1) << endl;

	greet(square(2), "Anyonghaseyo");
}	

void greet(int nTimes, string msg)
{
	for (int k = 0; k < nTimes; k++)
		cout << msg << endl;
}

int square(int k)
{
	return k*k;
}

void blah(int x, int y)
{
	int a;
	string nTimes;
	int k;
}
============================================================================================================================
WEDNESDAY
============================================================================================================================
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

isValidPhoneNumber(string pn);
string digitsOf(string pn);


int main()
{
	cout << "Enter a phone number: ";
	string phone;
	getline(cin, phone);
	if (isValidPhoneNumber(phone))
		cout << "The digits in the number are " << digitsOf(phone) << endl;
	else
		cout << "A phone number must have 10 digits." << endl;
}

bool isValidPhoneNumber (string pn)
{
	int numberOfDigits = 0;
	for (int k = 0; k != pn.size(); k++)
	{
		if (isdigit(pn[k]))
			numberOfDigits++;
	}
	return (numberOfDigits == 10)
	
}

string digitsOf(string pn)
{
	string digitsOnly = "";
	for (int k = 0; k! = pn.size(); k++)
	{
		if (isdigit(pn[k])
			digitsOnly += pn[k];
	}
	return digitsOnly;
}

============================================================================================================================

int n = 17;
if (n = 0)
	cout << "n is zero";
else
	cout << "n is not zero; n is" << n;

n is not zero; n is 0


void greet (int nTimes, string msg)
{
	if(nTimes < 0)
	{
		cout < "I can't greet you a negative number of times!" << endl;
		return;
	}
	for (int k = 0; k < nTimes; k++)
		cout << msg << endl;
}

============================================================================================================================
#include <cmath>
using namespace std;

void polarToCartesian (double rho, double theta, double& x, double& y); 

int main()
{
	double r;
	double angle;
	.... // get values r and angle
	double x;
	doulbe y;
	polarToCartesian(r, angle, x, y);
	....
	double x2;
	polarToCartesian(2*r, angle, x2, y);
	...
}

void polarToCartesian (double rho, double theta, double& xx, double& yy) 
{
	xx = rho * cos(theta);
	yy = rho * sin(theta);
}


/*double& "the reference to a double"
A reference is just another name for an already existing object
 
rho and theta are "passed by value"  ==> copied
xx and yy are "passed by reference"  ==> no copy is made; they are just another name for existing objects*/


string phone;
cout << "Enter a phone number: ";
getline(cin, phone);
while (! isValidPhoneNumber(phone))
{
	cout << "A phone number must have 10 digits; try again." << endl;
	cout << "Enter a phone number: ";
	getline(cin, phone);

}
cout << "The digits in the number are " << digitsOf(phone) << endl;


while(true)
{
	cout << "Enter a phone number: ";
	getline(cin, phone);
	if (isValidPhoneNumber(phone))
		break;
	cout << "A phone number must have 10 digits; try again." << endl;
}
cout << "The digits in the number are " << digitsOf(phone) << endl;

//"n-and-a-half-times loop"
//break; break out of hte nearest enclosing switch or loop







