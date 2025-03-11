#pragma once
//#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsUser.h"
#include"clsScreen.h"

string FileNam = "User.txt"; 



  
  
  
  
class clsAddNewUser : protected clsScreen{
  
 private :
 
 static string ReadUserName(){
   string UserName="";
   cout<<" Read User Name :"<<endl;
   getline(cin>> ws, UserName);
   return UserName ;
 }
 
 static void ReadClientInfo(clsUser &Client, string UserName){
  
  Client.SetUserName(UserName);
  
  cout<<"Enter password Please";
  Client.SetPassword(clsInputValidate::ReadString());
  
  cout<<"Enter User First Name Please";
  Client.SetFirstName(clsInputValidate::ReadString());
  
  cout<<"Enter User last Name Please";
  Client.SetLastName(clsInputValidate::ReadString());
  
  //cout<<"Enter Client Account Balance Please";
 // Client.SetAccountBalance(clsInputValidate::ReadString());
  
 // cout<<"Enter Client PinCode Please";
//  Client.SetPinCode (clsInputValidate::ReadString());
  
  cout<<"Enter user Phone Number Please";
  Client.SetPhone(clsInputValidate::ReadString());
  
  cout<<"Enter user Email Number Please";
  Client.SetEmail (clsInputValidate::ReadString());
  
  cout<<"Enter user permission Number Please";
  Client.SetPermissions(ReadPermissionsToSet());
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
       // cout << "\nAcc. Number : " << Client.GetAccountNumber();
      //  cout << "\nPassword    : " << Client.GetPinCode();
       // cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\nUserName   : " << Client.GetUserName();
        cout << "\nPassword    : " << Client.GetPassword();
       cout << "\nPermissions       : " << Client.GetPermissions();
        cout << "\n___________________\n";
    }

static int ReadPermissionsToSet()
{
  

    int Permissions = 0;
    char Answer = 'n';


    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        

        Permissions += clsUser::enMainMenuePermissions::pListClients;
    }


    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::pManageUsers;
    }
    
    cout << "\nShow LoginRegister? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enMainMenuePermissions::LoginRegister;
    }
    
/* LoginRegister */

    return  Permissions;

}

 
 
 
 public :
 
 
 static int GetPermisions(){
   
   return ReadPermissionsToSet();
   
 }
static void AddClient() {
    
    
    
      /*enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};*/
 
  if(!CheackAccessPermissions( clsUser::enMainMenuePermissions::pAddNewClient)){
    return;
   }
    
    clsScreen::ShowScreenHeader("Add New Screen","");
    
    string AccountNumber = "";
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while (clsUser::IsUserExist(AccountNumber)) {
        cout << "Enter Different Account Number; This one already exists :-)\n";
        AccountNumber = clsInputValidate::ReadString();
    }
   
  string  UserName=ReadUserName();
    clsUser Client = clsUser::GetAddNewUserObject(UserName);
    //enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
    ReadClientInfo(Client,UserName);
  //  Client.SetAccountNumber(AccountNumber);
    clsUser::enSaveResults SaveFun = Client.Save();
    
    if (SaveFun == clsUser::enSaveResults::svFaildUserExists) {
        cout << "User already here ";
    } 
    if (SaveFun == clsUser::enSaveResults::svFaildEmptyObject) {
        cout << "User has not been saved because it was empty";
    } else if( SaveFun == clsUser::enSaveResults::svSucceeded) {
        cout << "User Added successfully";
        
        Print(Client);
    }else{
      cout <<"User has not saved bec it was empty";
    }
} 


  


  
  
  
};
