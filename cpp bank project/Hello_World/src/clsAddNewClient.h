#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsAddNewClient : protected clsScreen{
  
 private :
 static void ReadClientInfo(clsBankClient &Client){
  cout<<"Enter Client First Name Please";
  Client.SetFirstName(clsInputValidate::ReadString());
  
  cout<<"Enter Client last Name Please";
  Client.SetLastName(clsInputValidate::ReadString());
  
  cout<<"Enter Client Account Balance Please";
  Client.SetAccountBalance(clsInputValidate::ReadString());
  
  cout<<"Enter Client PinCode Please";
  Client.SetPinCode (clsInputValidate::ReadString());
  
  cout<<"Enter Client Phone Number Please";
  Client.SetPhone(clsInputValidate::ReadString());
  
  cout<<"Enter Client Email Number Please";
  Client.SetEmail (clsInputValidate::ReadString());
  
}

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
static void AddClient() {
    
    clsScreen::ShowScreenHeader("Add New Screen","");
    
    string AccountNumber = "";
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (clsBankClient::IsClientExsit(AccountNumber)) {
        cout << "Enter Different Account Number; This one already exists :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
    
    cout << "\nAdd New Client\n";
    clsBankClient Client = clsBankClient::MakeNewClient();
    ReadClientInfo(Client);
    Client.SetAccountNumber(AccountNumber);
    clsBankClient::enSaveResults SaveFun = Client.Save();
    
    if (SaveFun == clsBankClient::enSaveResults::svFaildAccountNumExsit) {
        cout << "Client already here ";
    } 
    if (SaveFun == clsBankClient::enSaveResults::svFaildEmptyObject) {
        cout << "Client has not been saved because it was empty";
    } else if( SaveFun == clsBankClient::enSaveResults::svAddedSuccesfully) {
        cout << "Client Added successfully";
        
        Print(Client);
    }else{
      cout <<"client has not saved bec it was empty";
    }
} 


  
};
