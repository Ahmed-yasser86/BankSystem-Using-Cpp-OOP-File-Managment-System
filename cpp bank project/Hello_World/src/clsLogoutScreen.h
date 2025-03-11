#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUser.h"
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeletUserScree.h"
#include "UpdateScreen.h"
#include "FindUserScreen.h"
#include "clsMainScreenMenu.h"
#include "clsLoginScreen.h"
include "clsGlobal.h"

class LogOut : protected clsScreen{

  public:
  
  void LogoutScreen(){

        system("cls");

  CurrentUser = clsUser::Find("", "");      
  //clsLogin::Login();
  
  }
  
}
