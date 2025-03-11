#pragma once
//#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsUser.h"
#include "clsGlobal.h"
string FileName="User.txt"; 



class clsListUsers : protected clsScreen{
  


private:

static void PrintUserRecordLine(clsUser User)
{

    cout << "| " << setw(15) << left << User.GetUserName();
    cout << "| " << setw(10) << left << User.GetPassword();
    cout << "| " << setw(40) << left << User.GetPermissions();
}



 
 
  
  public:
  /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};*/
 static void PrintUsersRecord(){
   if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::pListClients)){
     return;
   }
   vector <clsUser> vUsers =  clsUser::LoadUsers();
   
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vUsers.size() == 0)
        cout << "\t\t\t\tNo Users Available In the System!";
    else

        for (clsUser User : vUsers)
        {

            PrintUserRecordLine(User);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

  
  
};
