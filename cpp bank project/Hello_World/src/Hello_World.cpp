#include <iostream>
#include <vector>
using namespace std;
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsMainScreenMenu.h"
#include "clsScreen.h"
#include "clsTransactionsMenu.h"
#include "clsLoginScreen.h"



int main() {
  
//  AddClient();
  //DelClient();
  
  //ListTotalBalance();
//clsMainScreenMenu::ShowMainMenue();
while(true){
if(!clsLogin::ShowLoginScreen()){
  
  break;
};
  
  }
  return 0;
}
