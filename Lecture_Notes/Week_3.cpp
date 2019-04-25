if (citizenship) == "US" && age >= 18)

if (a/b + c/d > 10)

if (a/b + c/d > 10 && b!= 0 && d!=0) 
	// guaranteed that second condition will not be evaluated if first is false. thus, undefined behavior if b or d is zero

if ( b!= 0 && d!=0 && a/b + c/d > 10)  // this works because the only way to get to the third statement is if b and d != 0 

=======================================================================================================================================

if (citizenship == "US" || citizenship == "Canada") //OK
if (citizenship == "US" || "Canada") //wrong -- will compile. Character string literal "Canada" is treated as true. 

if (age == 18 || age == 19 || age == 20) //OK
if (age ==18 || 19 || 20) // wrong -- will compile. 19 is not zero, therefore true. So conditional proceeds.

int n = 17;
cout << "n is " << n << endl;
if (n =0) //uh-oh. not comparison operator, but assignment. also acts as false, so conditional proceeds to else statement.
	cout << "n is zero" << endl;
else
	cout << "n is not zero: n is " << n << endl;

/* n is 17
n is not zero; n is 0 */

=======================================================================================================================================

if (citizenship !="US" || age < 18) // not easily readable. want the if and else conditionals to be close together.
{


}
else 
	cout << "You can vote in US elections" << endl;


if (citizenship == "US" || age > 18) // when you switch order of conditions, need to make sure operators are exactly opposite.
	cout << "You can vote in US elections" << endl;
else 
{


}

/* De Morgan's Laws: 
	not (A or B) ==> (not A) and (not B)
	not (A and B) ==> (not A) or (not B) */

=======================================================================================================================================
if (income < 30000)
	cout << "Low"
else if (income < 100000)
	cout << "Middle";
else if (income < 500000)
	cout << "High";
else
	cout << "Very high";

// called the if ladder. notice the statements with "if" has a condition statement, whereas the last "else" statement doesn't have an attached conditional.

int main ()
{
	...
	int choice;
	cin >> choice;
	if (choice == 1)
		...
	else if (choice == 2 || choice == 4)
		...
	else if (choice == 3 || choice == 5)
		...
	else
	{
		cout << "You typed an incorrect choice" << endl;
		return 1;
	}
	...
	...
}










	