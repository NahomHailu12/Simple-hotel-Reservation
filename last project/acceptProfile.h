/*
header to accept data
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "declaration.h"
#include <algorithm>
using namespace std;
class profile{
bool acceptName(char Name[50]){
            for(int i=0;i<50;i++)
            Name[i]='\0';
            string name;
            int c = 1;
            bool invalidname;
            do
            {
                invalidname = false;
                cout << "\tFull name(more than 3 letter and only alphabet): ";
                cin.ignore();
                getline(cin, name);
                for (int j = 0; j < name.size(); j++)
                { // Loop for validating the name
                    if (isalpha(name[j]) == false && name[j] != ' ')
                    {
                        invalidname = true;
                        break;
                    }
                }
                c++;
            } while ((name.size() < 4 || invalidname) && c <= 3);
            if (name.size() < 4 || invalidname) // If the input is still invalid more than 3 times, exit
                return false;
            for(int i=0;i<name.size();i++)
            Name[i]=(char)name[i];
            return true;
}
bool acceptAge(short & age){
    cout << "\tAge: ";
            cin >> age;
            for (int c = 1; c < 3 && (age > 120 || age <= 0); c++)
            { // Loop for validating the age
                cout << "Please enter valid age: ";
                cin >> age;
            }
            if (age > 120 || age <= 0) // If the input is still invalid more than 3 times, exit
                return false;
            return true;
}
bool acceptGender(char & gender){
    cout << "\tGender(m/f): ";
            cin >> gender;
            gender = toupper(gender); // Convert character into it's Uppercase equivalent
            for (int c = 1; c < 3 && (gender != 'M' && gender != 'F'); c++)
            { // Loop for validating the age
                cout << "Please enter a valid gender(m/f): ";
                cin >> gender;
                gender = toupper(gender);
            }
            if (gender != 'M' && gender != 'F') // If the input is still invalid more than 3 times, exit
                return false;
            return true;
}
bool checkuniqueReservation(string reservationCode){
char codes[6];
for(int i=0;i<6;i++)
codes[i]=reservationCode[i];
fstream unique("guest.dat",ios::in|ios::binary);
guestProfile checker;
while(unique.read((char*)&checker,sizeof(checker))){
    if(checker.isreserved && !strcmp(codes,checker.reservation))
    {
    cout<<"please enter unique Reservation id"<<endl;
    unique.close();
    return false;
    }
}
unique.close();
return true;
}
bool acceptReservationCode_norepeation(char code[6],string reservationCode=""){
            for(int i=0;i<8;i++)
            code[i]='\0';
            bool isunique=true;
            int reservationcount(0);
            bool invalidReservationcode = false;
            do
            {
                invalidReservationcode = false;
                isunique=true;
                cout << "\tReservation code((0-9)xxxxxx): ";
                cin >> reservationCode;
                if (reservationCode.size() != 6)
                { // Validating the lenght of the input code
                    invalidReservationcode = true;
                    reservationcount++;
                }
                else
                {
                    for (int i = 0; i < reservationCode.size(); i++)
                    { // Validating if the input if digit or not
                        if (isdigit(reservationCode[i]) == false)
                        {
                            invalidReservationcode = true;
                            reservationcount++;
                            break;
                        }
                    }
                } 
                isunique = checkuniqueReservation(reservationCode); // checking the uniqueness
                if(!isunique)
                reservationcount++;
                if ((invalidReservationcode || !isunique) && reservationcount == 3) // If the input is still invalid more than 3 times, exit
                    return false;
            } while ((invalidReservationcode || !isunique) && reservationcount < 3);
        for(int i=0;i<6;i++)
        code[i]=reservationCode[i];
        return true;
    }
public:
bool acceptReservationCode(char code[6],string reservationCode=""){
            for(int i=0;i<8;i++)
            code[i]='\0';
            bool isunique=true;
            int reservationcount(0);
            bool invalidReservationcode = false;
            do
            {
                invalidReservationcode = false;
                isunique=true;
                cout << "\tReservation code((0-9)xxxxxx): ";
                cin >> reservationCode;
                if (reservationCode.size() != 6)
                { // Validating the lenght of the input code
                    invalidReservationcode = true;
                    reservationcount++;
                }
                else
                {
                    for (int i = 0; i < reservationCode.size(); i++)
                    { // Validating if the input if digit or not
                        if (isdigit(reservationCode[i]) == false)
                        {
                            invalidReservationcode = true;
                            reservationcount++;
                            break;
                        }
                    }
                } 
                if ((invalidReservationcode) && reservationcount == 3) // If the input is still invalid more than 3 times, exit
                    return false;
            } while ((invalidReservationcode ) && reservationcount < 3);
        for(int i=0;i<6;i++)
        code[i]=reservationCode[i];
        return true;
    }
bool acceptProfile(guestProfile & guest){
        if(!acceptName(guest.name)) return false;
        if(!acceptAge(guest.age))return false;
        if(!acceptGender(guest.gender))return false;
        if(!acceptReservationCode_norepeation(guest.reservation))return false;
        return true;
    }
}profile1;
