#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdraw : protected clsScreen
{

private:
    
    static void _PrintClient(clsBankClient Client)
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowWithdrawlScreen()
    {
        ShowScreenHeader ("\t   Deposit Screen","");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExsit(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdrawal amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y'){
        
         if( Client1.Withderaw(Amount)){
            cout << "\nAmount Withdrawed Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();

        }
        else
        {
            cout << "\nOperation Can not be preformed try to enter anthore balance.\n";
        }
        }else {
          cout << "\nOperation Canclled.\n";
          
        }
    }

};
