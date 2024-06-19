/*
header to adimster
and test
binary file*/
#include <iostream>
using namespace std;
#include <fstream>
#include "acceptProfile.h"
#include "inputalign.h"
using namespace std;
guestProfile tempo;
void fileintialize(fstream & openingFile){
/* preparing new file for reserving with its room struture */
guestProfile guest;
guest.isreserved=false;            //unreserving all the class
guest.roomNumber=0;
for(int i=0;i<60;i++){
guest.roomid=1;             // catagorizing rooms
guest.roomNumber++;         // all are consquective
openingFile.write((char*) & guest,sizeof(guest));
}
guest.roomNumber=0;
for(int i=0;i<60;i++){
// repeat the same for both
guest.roomid=2;        
guest.roomNumber++;
openingFile.write((char*) & guest,sizeof(guest));
}
guest.roomNumber=0;
for(int i=0;i<60;i++){
guest.roomid=3;
guest.isreserved=false;
guest.roomNumber++;
openingFile.write((char*) & guest,sizeof(guest));
}
}
void displayall(){
    guestProfile temp;
    fstream display("guest.dat",ios::in|ios::binary);
    display.seekg(0);
    for(int i=0;i<180;i++){
        display.read((char*) & temp,sizeof(temp));
        cout<<temp.roomid<<" "<<temp.roomNumber<<" "<<temp.isreserved<<" "<<temp.age<<endl;
    }
    display.close();
}
void fileSetup(){
fstream toprocess("guest.dat",ios::in|ios::out|ios::binary);
if(!toprocess.is_open()) // if not created 
{
    toprocess.close();
    toprocess.open("guest.dat",ios::out|ios::binary); // create a new file
    fileintialize(toprocess);
    toprocess.close();
}
}