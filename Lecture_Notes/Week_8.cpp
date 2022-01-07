struct Employee
{
	string name;
	double salary;
	int age;
}; <======== //DON'T FORGET THE SEMICOLON

int main()
{
	Employee e1;
	Employee e2;

	e1.name = "Fred";
	e1.salary = 50000;
	e1.age = 49;

	e2.name = "Ethel";
	e2.salary = 60000;
	e2.age = 32;

	Employee company[100];
	company[2].name = "Ricky"

	for (int k = 0; k!= company[2].name.size(); k++)
		cout << company[2].name[k] << endl;
}
===============================================================================================================
void printPaycheck(const Employee& e);
void celebrateBirthday(Employee* e);
double totalPayroll (const Employee emps[], int nEmps);

int main()
{
	Employee company[100];
	int nEmployees = 0;
	...put some employee data into the array....

	printPaycheck(company[1]);
	celebrateBirthday(company[0]);
	cout << totalPayroll(company, nEmployees)
}

void printPaycheck(const Employee& e)
{
	cout << "Pay to the order of" << e.name << "the amount $" <<e.salary/12 << endl;
}

void celebrateBirthday(Employee* ep)
{
	ep->age++;
}

double totalPayroll(const Employee emps[], int nEmps)
{
	double total = 0;
	for (int k = 0; k < nEmps; k++)
		total += emps[k].salary;
	return total;
}
===============================================================================================================

struct Target
{
	void init();
	void move(char dir);
	void replayHistory();

	int pos;
	string history;
		//Invariant: 
		// history consists only of Rs and Ls
		// pos == number of Rs in history minus number of Ls in history
};
	
void Target::init()
{
	pos = 0;		// means this-> pos = 0;
	history = "";
}




int main ()
{
	Target t;
	t.init();

	t.move ('R');

	Target t2;
	t2.init();
	t2.move('L');
	t2.move('L');
}











