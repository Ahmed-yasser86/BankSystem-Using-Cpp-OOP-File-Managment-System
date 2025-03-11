#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTotalBalance : protected clsScreen {
  
  
 static void PrintClientBalanceRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(40) << left << Client.GetFirstName();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();
}

public:
  
  static void ShowBalanceScreen()
{
  cout << "\n_______________________________________________________";
    vector <clsBankClient> vClients = clsBankClient::GeClientsList();
   string subt="("+to_string( vClients.size())+")";
    clsScreen::ShowScreenHeader("Client Balance List Screen",subt);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

          PrintClientBalanceRecordLine(Client);
            cout << endl;
        }
       double Amount=clsBankClient::TotalBalances();
     cout<<"Your Total Balance is :"<<  clsUtil::NumberToText(Amount)<<endl;
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
} 

  
  
};



