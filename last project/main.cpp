/*
main file of the project
*/
#include <iostream>
using namespace std;
#include "admin.h"
void frontPage(){
    char choice = intro();
    if(choice == '1')
    reserveroom();
    if(choice == '2')
    admin1.admin_intro();
}
int main(){ 
fileSetup();                       // to setup file for first use
short tocontinue;
do{
    frontPage();
    cout<<endl<<"Do you want to continue(1 to continue): ";   
    cin>>tocontinue;
}while(tocontinue==1);              //looping if the user want to continue
}
