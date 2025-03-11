#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



class clsUpdateClient : protected clsScreen {
  
  private: 
  
  
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
  static void UpdatClient(){
  
  ShowScreenHeader("Update Client Screen ","");
  
  string AccountNumber ="";
  cout<<" Enter Account Number\n";
  AccountNumber = clsInputValidate::ReadString();
  
  while(!clsBankClient::IsClientExsit(AccountNumber)){
    
      cout<<" Enter Correct Account  Number\n";
    AccountNumber = clsInputValidate::ReadString();
  }
  
  clsBankClient Client = clsBankClient::Find(AccountNumber);
  
  Print(Client);
  
  
  cout<<"\n Update Client \n";
  ReadClientInfo(Client);
  
 clsBankClient::enSaveResults SaveFun= Client.Save();
  
  
  if(SaveFun == clsBankClient::enSaveResults::svFaildEmptyObject){
    
    
    cout <<"client has not saved bec it was empty";
  }
  else if (SaveFun == clsBankClient::enSaveResults::svSucceeded) {
    
    cout<< "client saved succesfully";
    
    
  }
  
}
  
  
  
  
};
