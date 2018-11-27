#include<iostream>
#include<string>
using namespace std;

class savingsAcct
{
	friend istream& operator>>(istream&, savingsAcct&);
	friend ostream& operator<<(ostream&, const savingsAcct&);
public:
	savingsAcct();
	savingsAcct(string acctNum, double amt);
	// Postcondition: balance is set to the value passed to parameter amt
	static double * getAddressOfVar_annualRate();
	// Postcondition: return the address of static variable annualRate (should the same for all objects!)
	static double getAnnualRate();
	// Postcondition: returns annual interest rate
	static void setAnnualRate(double rate);	// change the annual interest rate
	// Postcondition: annualRate has been changed to the value passed to parameter rate
	void computeIntrest();
	// Interest is computed at the end of each month using monthly interest rate (i.e.,annualRate/12)
	// Postcondition: interest is computed at the end of the month using the current balance
private:
	string acctNo;		// e.g., A1234
	double balance;
	static double annualRate;	// classwide; store in a memory location shared by all objects
	double interest;		// monthly interest
};

double savingsAcct::annualRate = 0;

savingsAcct::savingsAcct()
{
    acctNo = "N/A";
    balance = 0;
}

savingsAcct::savingsAcct(string acctNum, double amt)
{
    acctNo = acctNum;
    balance = amt;
}

double * savingsAcct::getAddressOfVar_annualRate()
{
    return &annualRate;
}

double savingsAcct::getAnnualRate()
{
    return annualRate;
}

void savingsAcct::setAnnualRate(double rate)
{
    annualRate = rate;
}

void savingsAcct::computeIntrest()
{
    interest = balance * (annualRate / 12);
}

istream& operator>>(istream& in, savingsAcct& acct)
{
    return in;
}

ostream& operator<<(ostream& out, const savingsAcct& acct)
{
    cout << "\nAccount No:\t" << acct.acctNo;
    cout << "\nBalance:\t" << acct.balance;
    cout << "\nInterest:\t" << acct.interest;

    return out;
}


int main()
{
	cout << "As of now, no object has been declared.\n";
	cout << "However, static data members exist before any object is declared:" << endl;
	cout << "   The address of its storage location: " 
			<< savingsAcct::getAddressOfVar_annualRate() << endl;
	cout << "                  Annual interest rate: " << savingsAcct::getAnnualRate() * 100 
			<< "%" << endl << endl;

	cout << "Still no object has declared, we now set the interest rate to 1.5%." << endl;
	savingsAcct::setAnnualRate(0.015);
	cout << "    Now, the annual interest rate is: " << savingsAcct::getAnnualRate() * 100 
			<< "%" << endl << endl;

	cout << "We now declare and initialize 2 savingAcct objects." << endl;
	cout << "We also compute interest at the end of 1st month and display their cnotents:\n\n";	
	
	savingsAcct s1("A1234", 5000), s2("A9876", 8000);
	
	s1.computeIntrest();
	s2.computeIntrest();
	cout << s1 << endl << endl;
	cout << s2 << endl << endl;

	cout << "We now display the address of static variable annualRate" << endl;
	cout << "   by calling \"getAddressOfVar_annualRate()\" member function" << endl << endl;

	cout << "Via s1: the address of \"annualRate\" is  " << s1.getAddressOfVar_annualRate() 
			<< endl;
	cout << "Via s2: the address of \"annualRate\" is  " << s2.getAddressOfVar_annualRate() 
			<< endl;
	cout << "Via s1: the address of \"annualRate\" is  " 
			<< savingsAcct::getAddressOfVar_annualRate() << endl;
	cout << "\nIt should be quite clear that static members are indeed \"class-wide!!!\"" << endl;
	cout << "Note: calling a static member function, \"this\" pointer is not involved!!!\n\n";
	return 0;
}