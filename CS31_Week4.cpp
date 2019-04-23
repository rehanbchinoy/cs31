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

int main ()
{
	greet(3, "Hello");

	int a = 4;
	greet(2*a-1, "Ni hao");

	string s;
	getline(cin, s);
	greet(1, s);
}	

void greet(int nTimes, string msg)
{
	for (int k = 0; k < nTimes; k++)
		cout << msg << endl;
}






