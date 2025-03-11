#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsDeletUser : protected clsScreen {
  
  private:
  
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
  
  
  public:
  
  static  void DelUser(){
    
         /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};*/
 
   if(!CheackAccessPermissions( clsUser::enMainMenuePermissions::pDeleteClient)){
     return;
   }
    
    
    string AccountNumber = "";
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (!clsUser::IsUserExist(AccountNumber)) {
        cout << "Enter Different Account Number ; This does Not Exist :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
   
     cout<<"\nDelet Client\n";
     clsUser DeletClient = clsUser::Find(AccountNumber);
    
     Print(DeletClient);
     
     
    
    if(DeletClient.Delete()){
      
      cout<< "Client deleted succesfully \n";
      Print(DeletClient);
    }else{
      cout<< "Client has not deleted succesfully \n";
      
    }
}
  
  
  
};
