#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsString.h"
#include "clsListCurrencies.h"
#include "FindCurrency.h"
#include "UpdateRate.h"
class clsShowCurrencyScreen : public clsScreen {
  
  private :
  
  enum  enScreen {enListCurrencies = 1, enFindCurrencies = 2, enCurrenciesCalculator = 3, enUpdateRate = 4};
  
  static void ListCurrencies() {
      // Add logic to list currencies
    //  cout << "Listing all currencies...\n";
    clsListCrunncy::ShowAllClientsScreen();
  }
  
  static void FindCurrencies() {
      // Add logic to find currencies
     // cout << "Finding currency...\n";
     clsFindCurrency::PrintCurrency() ;
  }
  
  static void CurrenciesCalculator() {
      // Add logic to calculate currencies
   //   cout << "Currency calculator...\n";
   
  }
  
  static void UpdateRate() {
      clsUpdateCurrency::PrintUpdateScreen();
      
  }
  
  static int ReadManageUsersMenuOption() {
      int option;
      cout << "Enter your choice: ";
      cin >> option;
      return option;
  }
  
  static void PerformShowCurrencyScreensMenuOption(enScreen option) {
      switch(option) {
          case enListCurrencies:
              ListCurrencies();
              break;
          case enFindCurrencies:
              FindCurrencies();
              break;
          case enCurrenciesCalculator:
              CurrenciesCalculator();
              break;
          case enUpdateRate:
              UpdateRate();
              system("puase");
              break;
          default:
              cout << "Invalid option. Please try again.\n";
      }
  }

  public:
  
  static void ShowCurrencyMenu() {
      system("cls");
      cout << "===========================================\n";
      cout << "\tShow Currencies Menu Screen\n";
      cout << "===========================================\n";
      cout << "\t[1] List Currencies.\n";
      cout << "\t[2] Find Currencies.\n";
      cout << "\t[3] Currencies Calculator.\n";
      cout << "\t[4] Update Rate.\n";
      int choice = ReadManageUsersMenuOption();
      PerformShowCurrencyScreensMenuOption(static_cast<enScreen>(choice));
  }
  
};
