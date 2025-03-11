#pragma once
#include "clsGlobal.h"
#include "clsUser.h"
class clsScreen{
  
  
  protected:
  static void ShowScreenHeader(string Title, string SubTitle){
    
    cout <<"\n\t\t\t\t\t______________________________________________________________________________________ \n\n";
    
    cout <<"\t\t\t\t\t\t\t\t" <<Title<<endl;
    if(SubTitle!=""){
      cout <<"\t\t\t\t\t\t\t\t" <<SubTitle<<endl;
    }
    cout <<"\t\t\t\t\t______________________________________________________________________________________ \n\n";
    
    cout <<"\n\n"<<endl;
    cout <<"\n\n"<<endl;
    cout <<"\t\t\t\t\t \t\t\t\t\t User Name : "<<CurrentUser.GetUserName()<<endl;
    cout <<"\t\t\t\t\t \t\t\t\t\t Date :"<<clsDate::DateToString(clsDate());
    cout<<"\n";
  }
  
  
  
  enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};

  static bool CheackAccessPermissions(clsUser::enMainMenuePermissions permision){
    if ( CurrentUser.CheckAccessPermission(permision) ){
      return true;
    }else{
      
    cout <<"\n\t\t\t\t\t______________________________________________________________________________________ \n\n";
    cout <<"\t\t\t\t\t\t\t\t" <<"Sorry Acceses Denied You don't have acceses for this "<<endl;
    cout <<"\t\t\t\t\t______________________________________________________________________________________ \n\n";
    return false;
    
  }}
  
  
    
    
    
  
};
