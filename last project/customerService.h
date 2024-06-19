#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Include for sort
#include "fileManage.h"

using namespace std;

void optionals(fstream &base1, vector<short> &choosedOptions, guestProfile &customer);

bool acceptdata(fstream & book, short roomchoice, guestProfile &customer) {
    guestProfile temp;
    book.seekg(0, ios::beg);
    bool reserved = false;
    while (book.read((char*)&temp, sizeof(temp))) {
        if (!temp.isreserved && temp.roomid == roomchoice) {
            customer.roomid = roomchoice;
            customer.roomNumber = temp.roomNumber;
            customer.isreserved = true;
            book.seekp(-(int)sizeof(customer), ios::cur); // Corrected cast
            if (book.write((char*)&customer, sizeof(customer))) {
                reserved = true;
                cout << endl << "Successfully reserved" << endl
                     << "Room-id: " << customer.roomid << endl
                     << "Room-number: " << customer.roomNumber << endl;
            } else {
                cout << "Error writing to the file" << endl;
            }
            break;
        }
    }
    return reserved;
}
int validchoice(short roomChoice, short choices[]) {
    int i = 0;
    for (; i < 3 && roomChoice != choices[0] && roomChoice != choices[1] && roomChoice != choices[2]; i++) {
        cout << "Please enter correct input: ";
        cin >> roomChoice;
    }
    if (i >= 3) {
        return -1;
    }
    if (!(roomChoice != choices[0] && roomChoice != choices[1] && roomChoice != choices[2]))
        return roomChoice;
    return -1; // Add return statement for cases when roomChoice is not valid
}

void reserveroom() {
    guestProfile customer;
    if (!profile1.acceptProfile(customer)) {
        cout << "Sorry you cannot register. Please try to follow the rules." << endl;
        return;
    }
    cout << "\nSuccessfully registered!" << endl
         << "Welcome " << customer.name << endl
         << "Please select the type of room you want to reserve" << endl
         << "  Press 1 for Oceanview room" << endl
         << "\t2 for Poolside" << endl
         << "\t3 for Garden room" << endl;
    short roomChoice;
    cin >> roomChoice;
    short candidates[] = {1, 2, 3};
    if (validchoice(roomChoice, candidates) == -1) return;

    vector<short> choosedOptions;
    choosedOptions.push_back(roomChoice);
    fstream base1("guest.dat", ios::in | ios::out | ios::binary);
    if (!base1) {
        cout << "Error opening the file." << endl;
        return;
    }
    if (!acceptdata(base1, roomChoice, customer))
        optionals(base1, choosedOptions, customer);
}

short missed(vector<short> arry) {
    for (int i = 0; i < arry.size(); i++) {
        if (arry[i] > i + 1)
            return i + 1;
    }
    if (arry.size() < 3)
        return (short)arry.size() + 1;
    return 0;
}

void optionals(fstream &base1, vector<short> &choosedOptions, guestProfile &customer) {
    cout << "Sorry all your requests are reserved. Can we find another for you?" << endl
         << "\t1. You need optionals" << endl
         << "\tPress any other key if you want to resign" << endl;
    short option;
    cin >> option;
    if (option != 1)
        return;
    else {
        bool reserved = false;
         while (choosedOptions.size() < 3 && !reserved) {
            sort(choosedOptions.begin(), choosedOptions.end());
            short newChoice = missed(choosedOptions);
            if (newChoice != 0) {
                choosedOptions.push_back(newChoice);
                base1.clear(); // Clear any error flags before reusing the stream
                base1.seekg(0, ios::beg); // Reset file position to the beginning
                reserved = acceptdata(base1, newChoice, customer);
            } else {
                cout << "Apologies, all rooms are reserved." << endl;
                return;
            }
        }
        if (choosedOptions.size() >= 3)
            cout << "Apologies, all rooms are reserved." << endl;
    }
}
