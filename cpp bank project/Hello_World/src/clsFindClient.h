#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsFindClient : protected clsScreen{
  private :
  static void Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    } 
  
  public : 
  
static  void FindClient(){
    ShowScreenHeader("Find Client Screen","");
    string AccountNumber = "";
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (!clsBankClient::IsClientExsit(AccountNumber)) {
        cout << "Enter Different Account Number ; This does Not Exist :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
    
    
     clsBankClient Client = clsBankClient::Find(AccountNumber);
    
    if(!Client.IsEmpty()){
      cout<<"client exsit \n";
      Print(Client);
      
    }else{
      
      cout<<"client was not exsit \n";
    }
    
  }
  
  
  
  
  
  
};
