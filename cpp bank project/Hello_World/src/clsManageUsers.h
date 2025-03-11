#pragma once

//#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUser.h"
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeletUserScree.h"
#include "UpdateScreen.h"
#include "FindUserScreen.h"
#include "clsGlobal.h"
//using namespace std;

class clsMangeUsers : public clsScreen {
  
  static short ReadManageUsersMenueOption() {
      cout << "Choose what do you want to do? [1 to 6]? ";
      int Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
      return static_cast<short>(Choice);  // Cast to match return type
  }

    enum enManageUsersMenueOptions {
    eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
    eUpdateUser = 4, eFindUser = 5, eMainMenue = 6};
    
  static   void GoBackToManageUsersMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowManageUsersMenue();

};

/*
enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};
*/
static void ShowListUsersScreen() {
    
      clsListUsers::PrintUsersRecord();
      
  }

  static void ShowAddNewUserScreen() {
     clsAddNewUser::AddClient();
  }

  static void ShowDeleteUserScreen() {
   //   cout << "it will be implemented here \n" << endl;
   clsDeletUser::DelUser();
  }

  static void ShowUpdateUserScreen() {
     // cout << "it will be implemented here \n" << endl;
     clsUpdateUser::UpdatClient();
  }

  static void ShowFindUserScreen() {
     // cout << "it will be implemented here \n" << endl;
     clsFindUser::FindUser();
  }

  static void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption) {
      switch (ManageUsersMenueOption) {
      case enManageUsersMenueOptions::eListUsers:
          system("cls");
          ShowListUsersScreen();
          GoBackToManageUsersMenue();
          break;
      case enManageUsersMenueOptions::eAddNewUser:
          system("cls");
          ShowAddNewUserScreen();
          GoBackToManageUsersMenue();
          break;
      case enManageUsersMenueOptions::eDeleteUser:
          system("cls");
          ShowDeleteUserScreen();
          GoBackToManageUsersMenue();
          break;
      case enManageUsersMenueOptions::eUpdateUser:
          system("cls");
          ShowUpdateUserScreen();
          GoBackToManageUsersMenue();
          break;
      case enManageUsersMenueOptions::eFindUser:
          system("cls");
          ShowFindUserScreen();
          GoBackToManageUsersMenue();
          break;
      case enManageUsersMenueOptions::eMainMenue:
          // Handle the Main Menue case if needed
          break;
      }
  }



public:

  static void ShowManageUsersMenue() {

      /*  if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
      {
          ShowAccessDeniedMessage();
          GoBackToMainMenue();
          return;
      }*/
      
   if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::pManageUsers)){
     return;
   }

      system("cls");
      cout << "===========================================\n";
      cout << "\t\tManage Users Menue Screen\n";
      cout << "===========================================\n";
      cout << "\t[1] List Users.\n";
      cout << "\t[2] Add New User.\n";
      cout << "\t[3] Delete User.\n";
      cout << "\t[4] Update User.\n";
      cout << "\t[5] Find User.\n";
      cout << "\t[6] Main Menue.\n";
      cout << "===========================================\n";

      PerfromManageUsersMenueOption(static_cast<enManageUsersMenueOptions>(ReadManageUsersMenueOption()));
  }

  
};
