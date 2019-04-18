//
//  bill.cpp
//  Project 2: Water Works
//
//  Created by Rehan Chinoy on 4/16/19.
//  Copyright © 2019 Rehan Chinoy. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // customer input, error messages/exit program if input is not satisfactory
    
    cout << "Initial meter reading: ";
    int initialMeter;
    cin >> initialMeter;
    if (initialMeter < 0)
    {
        cout << "---" << endl;
        cout << "The initial meter reading must be nonnegative." << endl;
        return 1;
    }
    
    cout << "Final meter reading: ";
    int finalMeter;
    cin >> finalMeter;
    
    if (finalMeter < initialMeter)
    {
        cout << "---" << endl;
        cout << "The final meter reading must be at least as large as the initial reading." << endl;
        return 1;
    }
    
    
    cin.ignore(10000, '\n'); // characters up to and including the next newline character are consumed and discarded
    cout << "Customer name: ";
    string custName;
    getline(cin, custName);
    
    if (custName == "")
    {   cout << "---" << endl;
        cout << "You must enter a customer name." << endl;
        return 1;
    }
    
    cout << "Month number (1=Jan, 2=Feb, etc.): ";
    int month;
    cin >> month;
    
    if (month < 1 || month > 12)
    {
        cout << "---" << endl;
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }
    
    // bill calculation
    double bill;
    int usage = finalMeter - initialMeter;
    int remainder;
    const double firstTier = 2.71;
    
    if (month >= 4 && month <= 10) // high season
    {
        if (usage <= 43)
            bill = usage * firstTier;
        else
        {
            remainder = usage - 43;
            const double secondTierHigh = 3.39;
            bill = (43 * firstTier) + (static_cast<double>(remainder)  * secondTierHigh); //casts the integer remainder into a double. not strictly necessary, but it ensures an accurate bill caluculation as type double.
        }
    }
    else //low season
    {
        if (usage <= 29)
            bill = usage * firstTier;
        else
        {
            remainder = usage - 29;
            const double secondTierLow = 2.87;
            bill = (29 * firstTier) + (static_cast<double>(remainder) * secondTierLow);
        }
    }
    
    
    //bill output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); //two places after the decimal point because printing a dollar value
    cout << "---" << endl;
    cout << "The bill for " << custName << " is $" << bill << endl;
}
