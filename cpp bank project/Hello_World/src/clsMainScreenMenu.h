#pragma once
//#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <type_traits>
#include <vector>
#include <fstream>
#include "clsScreen.h"
#include <cstdlib>
#include "clsShowClientsList.h"
#include "clsAddNewClient.h"
#include "clsDeletClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactionsMenu.h"
#include "clsDepositScreen.h"
#include "clsManageUsers.h"
#include "LoginRegisterScreen.h"
#include "ShowCurrencyExchange.h"
class clsMainScreenMenu : public clsScreen{

private :

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, Transactions=6 ,ManageUsers=7, ListLoginRegister =8 ,ShowCurrencyExchange , eExit = 10
};

static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
        case enMainMenueOptions::eListClients:
    {
       // system("cls");
       cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
       cout << "Screen cleared!" << endl;
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
        case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
        
        
        case enMainMenueOptions::Transactions:
        system("cls");
        ShowTransactionsScreen();
        GoBackToMainMenue();
        break;
        
        case enMainMenueOptions::ManageUsers:
        system("cls");
        ShowManageUsersScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eExit:
        system("cls");
        LogoutScreen();
        break;
        
        
        case enMainMenueOptions::ListLoginRegister:
        system("cls");
        ListLoginRegisterScreen();
       
        GoBackToMainMenue();
        break;
        
        
        case enMainMenueOptions::ShowCurrencyExchange:
        system("cls");
        ShowCurrencyExchangeMenue();
        GoBackToMainMenue();
        break; 
    }
}
public:

static short _ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = clsInputValidate::ReadIntNumberBetween(1,10);
    return Choice;
}


static void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause");
    ShowMainMenue();

}


static void ListLoginRegisterScreen(){
  
  clsLoginRegister::PrintUsersRecord();
  
}

static void ShowAllClientsScreen(){
clsShowClientsList::ShowAllClientsScreen();

};

static void ShowAddNewClientsScreen(){
 // cout<<"it will implemnted soon ";
 clsAddNewClient::AddClient();
 
};

static void ShowDeleteClientScreen(){
  //cout<<"it will implemnted soon ";
  clsDeletClient::DelClient();
};

static void ShowUpdateClientScreen(){
  //cout<<"it will implemnted soon ";
  clsUpdateClient::UpdatClient();
};

static void ShowFindClientScreen(){
//  cout<<"it will implemnted soon ";

clsFindClient::FindClient();
};

static void ShowTransactionsScreen(){
 // cout<<"it will implemnted soon ";
 clsTransactionsMenu::ShowTransactionsMenue();
};

static void ShowManageUsersScreen(){
//  cout<<"it will implemnted soon ";

clsMangeUsers::ShowManageUsersMenue();

};


static void ShowCurrencyExchangeMenue(){
  
clsShowCurrencyScreen::ShowCurrencyMenu();
}

static void LogoutScreen(){

        system("cls");

  CurrentUser = clsUser::Find("", "");      
  //clsLogin::Login();
  
  }
;



static void ShowMainMenue()
{
  
  clsScreen::ShowScreenHeader("Main Screen","");
  
   // system("cls");
//    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
 //   cout << "Screen cleared!" << endl;
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions screen.\n";
    cout << "\t[7] Manage Users screen.\n";
    cout << "\t[8] List Login Register.\n";
    cout << "\t[9] Show Currencies .\n";
    cout << "\t[10] Exit.\n";
    cout << "===========================================\n";
    _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
}
};
