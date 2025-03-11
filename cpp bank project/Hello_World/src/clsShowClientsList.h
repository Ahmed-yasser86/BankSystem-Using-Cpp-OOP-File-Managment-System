#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsShowClientsList : protected clsScreen {
  
  private :
  static void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(10) << left << Client.GetPinCode();
    cout << "| " << setw(40) << left << Client.GetFirstName();
    cout << "| " << setw(40) << left << Client.GetLastName();
    cout << "| " << setw(40) << left << Client.GetEmail();
    cout << "| " << setw(12) << left << Client.GetPhone();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();
}
  
  public :
  
 static void ShowAllClientsScreen()
{
    vector <clsBankClient> vClients = clsBankClient::GeClientsList();
    string subt="("+to_string( vClients.size())+")";
    clsScreen::ShowScreenHeader("Client List Screen",subt);
    
 //   cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

  
};
