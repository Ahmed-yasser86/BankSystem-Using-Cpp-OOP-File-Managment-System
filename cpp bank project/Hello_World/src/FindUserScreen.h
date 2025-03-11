#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


class clsFindUser : protected clsScreen{
  private :
  
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
  
static  void FindUser(){
  
   /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};*/
 
   if(!CheackAccessPermissions(clsUser::enMainMenuePermissions::pFindClient)){
     return;
   }
  
    ShowScreenHeader("Find Client Screen","");
    string AccountNumber = "";
    cout << "Enter UserName\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (!clsUser::IsUserExist(AccountNumber)) {
        cout << "Enter Different Account Number ; This does Not Exist :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
    
    
     clsUser Client = clsUser::Find(AccountNumber);
    
    if(!Client.IsEmpty()){
      cout<<"client exsit \n";
      Print(Client);
      
    }else{
      
      cout<<"client was not exsit \n";
    }
    
  }
  
  
  
  
  
  
};
