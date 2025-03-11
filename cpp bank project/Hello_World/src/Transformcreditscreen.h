#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

/*
ShowTransformCreditScreen()
*/
class clsTransformCredit: protected clsScreen{
  
  private :
  
  
  static void Print(clsBankClient& Client)
  {
      cout << "\nClient Card:";
      cout << "\n___________________";
      cout << "\nFirstName   : " << Client.GetFirstName();
      cout << "\nLastName    : " << Client.GetLastName();
      cout << "\nAcc. Number : " << Client.GetAccountNumber();
      cout << "\nBalance     : " << Client.GetAccountBalance();
      cout << "\n___________________\n";
  }
  
  public :
  
  static void ShowTransformCreditScreen(){
    cout <<" enter Acc num from"<<endl;
    string AccNum1 = clsInputValidate::ReadString();
    
    while(!clsBankClient::IsClientExsit(AccNum1)){
      cout << "Invalid account number"<<endl;
      AccNum1 = clsInputValidate::ReadString();
    }
    clsBankClient Client1 = clsBankClient::Find(AccNum1);
    Print(Client1);
    cout <<" enter Acc num to"<<endl;
    string AccNum2 = clsInputValidate::ReadString();
    while(!clsBankClient::IsClientExsit(AccNum2)){
      cout << "Invalid account number"<<endl;
      AccNum2 = clsInputValidate::ReadString();
    }
    clsBankClient Client2 = clsBankClient::Find(AccNum2);
    Print(Client2);
    
    cout << "How much do you want to transfer: " << endl;
    double TransferredCredit = clsInputValidate::ReadDblNumber();
    char Ask = 'n';
    
    cout << "Are you sure you want to do the transfer Y/N: " << endl;
    cin >> Ask;
    
    if(Ask == 'y' || Ask == 'Y'){
      if(!clsBankClient::TransformCredit(Client1, Client2, TransferredCredit)){
        cout << "Your balance is not enough, please enter another amount: " << endl;
        TransferredCredit = clsInputValidate::ReadDblNumber();
      } else {
        cout << "The process has completed" << endl;
        Print(Client1);
        Print(Client2);
      }
    } else {
      cout << "The process has been canceled" << endl;
    }
  }
};
