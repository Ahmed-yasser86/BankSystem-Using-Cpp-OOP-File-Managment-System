#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUser.h"
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeletUserScree.h"
#include "UpdateScreen.h"
#include "FindUserScreen.h"
#include "clsMainScreenMenu.h"
#include "clsGlobal.h"


class clsLoginRegister : protected clsScreen {
 
 private:
static void PrintUserRecordLine(const vector<string>& vUsers) {
    if (vUsers.size() < 4) {
        cout << "Error: User record is incomplete." << endl;
        return;
    }
    cout << "| " << setw(19) << left << vUsers[0];
    cout << "| " << setw(15) << left << vUsers[1];
    cout << "| " << setw(10) << left << vUsers[2];
    cout << "| " << setw(40) << left << vUsers[3];
}


 public:
 
 static void PrintUsersRecord(){
  
  
  
    if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::LoginRegister)){
     return;
   }
  
   vector<vector<string>> vUsers =  clsUser::LoadUsersLoginFromFile();
   
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(19) << "Login Date ";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vUsers.size() == 0)
       cout << "\t\t\t\tNo Users Available In the System!";
    else


        for (vector<string>& Userl : vUsers)
{
    cout << "Processing user..." << endl;  // Debug print
    PrintUserRecordLine(Userl);            // Your function to print user data
    cout << endl;
}

        
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;


  
  
};};
