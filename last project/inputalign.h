/*
header to control
first page of the 
program
*/
#include <iostream>
using namespace std;
#include <fstream>
char intro(){
    char choice;
    cout << "\n\t*****\t\t" << endl;
        cout << "Wellcome to Wired Hotel" << endl
             << "-----------------------" << endl;
        cout << "\tPress 1, For user" << endl
             << "\tPress 2, For hotel staff" << endl;
        cin >> choice;
    for (int c = 1; (choice != '2' && choice != '1') && c <= 3; c++)
        { // If the input is neither '1' nor '2', gives trials up to 5 times
            cout << "Wellcome to Wired Hotel" << endl
                 << "Please enter" << endl
                 << "\t1, For user " << endl
                 << "\t2, For hotelstaff" << endl;
            cin >> choice;
        }
    return choice;
}