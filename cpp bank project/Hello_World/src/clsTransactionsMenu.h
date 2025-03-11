#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreenMenu.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalance.h"
#include "Transformcreditscreen.h"
#include "ShowTransformScreen.h"
class clsTransactionsMenu : public clsScreen {
  
  private :
  enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowTransformCreditScreen=4  , eTransformCreditScreen=5 , eShowMainMenue = 6  };
  
  static void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();

}

static short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = clsInputValidate::ReadIntNumberBetween(1,6);
    return Choice;

}



  public :
  
  static void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        system("pause>0");            
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowTransformCreditScreen:
    {
        system("cls");
        ShowTransformCrediScreen();
        system("pause>0");            
        GoBackToTransactionsMenue();
        break;
    }

   case enTransactionsMenueOptions::eTransformCreditScreen:
    {
        system("cls");
        TransformCreditScreen();
        system("pause>0");            
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowMainMenue:
    {

    cout<<"presss any tab ....";

    }
    }

}
  
       
 static void ShowDepositScreen(){
   
  // cout<<"it will be implemented soon";
   clsDepositScreen::ShowDepositScreen();
   
 }
  
  
static  void TransformCreditScreen(){
    
    
    clsTransformScreen::PrintUsersRecord();
  }
  
 static  void ShowTotalBalancesScreen(){
   
  // cout<<"it will be implemented soon";
   
   clsTotalBalance::ShowBalanceScreen();
 }
  
  
  static  void ShowWithDrawScreen(){
   
   //cout<<"it will be implemented soon";
   clsWithdraw::ShowWithdrawlScreen();
   
 }
 
 
 static  void ShowTransformCrediScreen(){
   
   //cout<<"it will be implemented soon";
   clsTransformCredit::ShowTransformCreditScreen();
   
 }
  
  static void ShowTransactionsMenue()
{
   /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
    
    *
ShowTransformCreditScreen()

class clsTransformCredit: protected clsScreen
};*/
 
   if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::pTranactions)){
     return;
   }
  
    clsScreen::ShowScreenHeader("Transaction Menue Screen ", " ");
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] ShowTransformCreditScreen.\n";
    cout << "\t[5] TransformCreditScreen.\n";  
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}
  
};
