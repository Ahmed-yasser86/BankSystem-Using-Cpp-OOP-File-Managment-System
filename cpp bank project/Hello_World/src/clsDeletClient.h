#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeletClient : protected clsScreen {
  
  private:
  
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
  
  
  public:
  
  static  void DelClient(){
    string AccountNumber = "";
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (!clsBankClient::IsClientExsit(AccountNumber)) {
        cout << "Enter Different Account Number ; This does Not Exist :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
   
     cout<<"\nDelet Client\n";
     clsBankClient DeletClient = clsBankClient::Find(AccountNumber);
    
     Print(DeletClient);
     
     
    
    if(DeletClient.DeletClient()){
      
      cout<< "Client deleted succesfully \n";
      Print(DeletClient);
    }else{
      cout<< "Client has not deleted succesfully \n";
      
    }
}
  
  
  
};
