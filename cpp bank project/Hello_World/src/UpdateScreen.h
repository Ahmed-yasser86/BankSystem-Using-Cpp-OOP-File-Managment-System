#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "AddNewUserScreen.h"


class clsUpdateUser : protected clsScreen {
  
  private: 
  
  
  static void ReadClientInfo(clsUser &Client, string UserName){
  cout<<"Enter User First Name Please";
  Client.SetUserName(UserName);
  
  cout<<"Enter User last Name Please";
  Client.SetPassword(clsInputValidate::ReadString());
  
  cout<<"Enter User First Name Please";
  Client.SetFirstName(clsInputValidate::ReadString());
  
  cout<<"Enter User last Name Please";
  Client.SetLastName(clsInputValidate::ReadString());
  
  //cout<<"Enter Client Account Balance Please";
 // Client.SetAccountBalance(clsInputValidate::ReadString());
  
 // cout<<"Enter Client PinCode Please";
//  Client.SetPinCode (clsInputValidate::ReadString());
  
  cout<<"Enter User Phone Number Please";
  Client.SetPhone(clsInputValidate::ReadString());
  
  cout<<"Enter User Email Number Please";
  Client.SetEmail (clsInputValidate::ReadString());
  
  cout<<"Enter User Email Number Please";
  Client.SetPermissions(clsAddNewUser::GetPermisions());
}


  static void Print(clsUser Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nUserName   : " << Client.GetUserName();
        cout << "\nPassword    : " << Client.GetPassword();
        cout << "\nPermissions       : " << Client.GetPermissions();
        cout << "\n___________________\n";
    }
  
  
  
  public : 
  static void UpdatClient(){
  
  
   /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};*/
 
   if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::pUpdateClients)){
     return;
   }
  
  ShowScreenHeader("Update Client Screen ","");
  
  string AccountNumber ="";
  cout<<" Enter username Number\n";
  AccountNumber = clsInputValidate::ReadString();
  
  while(!clsUser::IsUserExist(AccountNumber)){
    
      cout<<" Enter Correct Account  Number\n";
    AccountNumber = clsInputValidate::ReadString();
  }
  
  clsUser Client = clsUser::Find(AccountNumber);
  
  Print(Client);
  
  
  cout<<"\n Update Client \n";
  ReadClientInfo(Client, AccountNumber);
  
clsUser::enSaveResults SaveFun = Client.Save();
  
  
  if (SaveFun == clsUser::enSaveResults::svFaildEmptyObject) {
        cout << "User has not been saved because it was empty";
    } else if( SaveFun == clsUser::enSaveResults::svSucceeded) {
        cout << "User updated successfully";
    
  }
  
}
  
  
  
  
};
