/*header to control
the admin side
*/
#include <iostream>
using namespace std;
#include <fstream>
#include <bits/stdc++.h> 
#include <vector>
#include "tool.h"
void frontPage();
class adminstration{
class roomstatus{
bool displayRoomStatus(fstream & report, short choice,short Room){
    guestProfile reports;
    bool isfound=false;
    for(int i=0;i<180;i++){
        report.read((char*)&reports,sizeof(reports));
        if(reports.roomid==choice)
        if(Room>0)
        {if(reports.roomNumber==Room){
            if(reports.isreserved)
            display(reports);
            else
            cout<<endl<<"It is not reserved.";
            return true;
        }}
        else{
            if(reports.isreserved)
            {
            display(reports);
            isfound=true;
            }
        }
        }
        return isfound;
}
public :void room_status(){
    short choice;
    cout<<"Which room type do you need to see: ";
    cout << "  Press 1, For Oceanview room" << endl
                 << "\t2, For poolside" << endl
                 << "\t3, For garden room" << endl;
    cin >> choice;
    short static count = 0;
    if(!check(choice) && count++<3)
    room_status();
    if(count > 2)
    {
        count=0;
        cout<<"Invalid Inputs";
        frontPage();
    }
    short Room;
    cout<<" Input specfic room if wanted(0 for all rooms): ";
    cin>>Room;
    fstream report("guest.dat",ios::in|ios::binary);
    if(!displayRoomStatus(report,choice,Room))
    cout<<"No such room(beyond 60) or Unregistered";
    report.close();
}    
}roomstatus1;
class searchByReservation{
bool displayIfMatched(fstream & report, char search[6]){
    guestProfile reports;
    for(int i=0;i<180;i++){
        report.read((char*)&reports,sizeof(reports));
        if(checkMatch(reports.reservation,search))
        {
            display(reports);
            return true;
        }
    }
    return false;
}
public: void searchbyResevation(){
    cout<<"Enter the reservation key"<<endl;
    profile searchProfile;
    char search[8];
    searchProfile.acceptReservationCode(search);   // to accept reservation key
    fstream report("guest.dat",ios::in|ios::binary);
    if(!displayIfMatched(report,search))
    cout<<"No such guest by reservation key";
    report.close();
}
}search1;
class toUnreserve{
bool unreserve_profile(fstream & book,char reservation[8]){
    guestProfile customer;
     guestProfile temp;
     book.seekg(0,ios::beg);
     bool unreserved=false;
         while (book.read((char*)&temp, sizeof(temp))) {
        bool matches = checkMatch(reservation,temp.reservation);
        if (temp.isreserved && matches) {
            customer.roomid = temp.roomid;
            customer.roomNumber = temp.roomNumber;
            customer.isreserved = false;
            book.seekp(-(int)sizeof(customer), ios::cur); // Corrected cast
            if (book.write((char*)&customer, sizeof(customer))) {
                unreserved = true;
                cout << endl << "Successfully unreserved" << endl
                     << "Room-id: " << customer.roomid << endl
                     << "Room-number: " << customer.roomNumber << endl;
            } else {
                cerr << "Error writing to the file" << endl;
            }
            break;
        }
    }
    return unreserved;
}
public: void unresereve_guest(){
    cout<<"Enter the reservation key"<<endl;
    profile searchProfile;
    char search[8];
    searchProfile.acceptReservationCode(search);
    fstream report("guest.dat",ios::in|ios::out|ios::binary);
    if(!unreserve_profile(report,search))
    cout<<"We can't find such a guest.";
}
}unreserve1;
public:void admin_intro(){
    if(!passwordCheck())
    {
        cout<<"sorry You access adminstartion site.";
        return;
    }
    short choice;
    cout << "Press 1, for hotel rooms status" << endl
                 << "Press 2, for searching reservation code" << endl
                 << "Press 3, for unreserve guest by reservation code" << endl
                 << "Press 4, for reset data"<<endl;
            cin >> choice;
            short static count = 0;
    if(!extendedcheck(choice) && count++<3)
    admin_intro();
    if(count > 2)
    {
        count=0;
        cout<<"Invalid Inputs";
        frontPage();
    }
            if(choice==1)
            roomstatus1.room_status();
            if(choice==2)
            search1.searchbyResevation();
            if(choice==3)
            unreserve1.unresereve_guest();
            if(choice==4)
            {
            fstream toformat("guest.dat",ios::out|ios::binary);
            cout<<"Are u sure you want to format all the data(0 for no): ";
            cin>>choice;
            if(choice!=0)
            {fileintialize(toformat);
            cout<<"Succesfully reset";}
            }
}
}admin1;