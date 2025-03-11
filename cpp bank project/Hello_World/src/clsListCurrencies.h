#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsString.h"



class clsListCrunncy : protected clsScreen{
  
  static void PrintClientRecordLine(clsCurrency Client)
{
    cout << "| " << setw(30) << left << Client.GetCountryName();
    cout << "| " << setw(30) << left << Client.GetCountryCode();
    cout << "| " << setw(30) << left << Client.GetCountryCurrency();
    cout << "| " << setw(30) << left << Client.GateExchangRate();
}
  
  public :
  
 static void ShowAllClientsScreen()
{
    vector <clsCurrency> vClients = clsCurrency::ListCurrencies();
    string subt="("+to_string( vClients.size())+")";
    clsScreen::ShowScreenHeader("Client List Screen",subt);
    
 //   cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(30) << " CountryName";
    cout << "| " << left << setw(30) << " CountryCode";
    cout << "| " << left << setw(30) << " Currency";
    cout << "| " << left << setw(30) << " ExchangRate";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsCurrency Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

  
  
  
  
  
};
