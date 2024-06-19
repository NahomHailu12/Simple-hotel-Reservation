/*
header that include 
system supportive
functions
*/
#include <iostream>
using namespace std;
#include <fstream>
#include <bits/stdc++.h> 
#include <vector>
#include "customerService.h"
bool check(short choice){
    if(choice != 1 && choice !=2 && choice != 3)
    return false;
    else
    return true;
}
bool passwordCheck(){
    for(int k=0;k<3;k++)
    {
    cout<<"Enter Admin password: ";
    string trail;
    cin>>trail;
        for(int i=0;i<6;i++){
        if(trail[i]!=password[i])
        continue;
        if(i==5)
        return true;
    }
    if(k==2)
    return false;
    }
}
bool extendedcheck(short choice){
    if(choice != 1 && choice !=2 && choice != 3 && choice != 4)
    return false;
    else
    return true;
}

bool checkMatch(char s1[],char s2[]){
        for(int i=0;i<6;i++){
        if(s1[i]!=s2[i])
        return false;
        if(i==5)
        return true;
    }
    }


void display(guestProfile to_be_display){
cout<<endl<<"Name: "<<to_be_display.name<<endl<<
        "age: "<<to_be_display.age<<endl<<
        "Reservation: "<<to_be_display.reservation<<endl<<
        "Room ID: "<<to_be_display.roomid<<endl<<
        "Room Number: "<<to_be_display.roomNumber;
}