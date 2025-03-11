#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsString.h"
#include "clsCurrencey.h"

class clsFindCurrency {
  
    enum Type { eCName = 1, eCode = 2 };

    static void PrintClientRecordLine(clsCurrency Client) {
        cout << "| " << "Country: " << Client.GetCountryName()<<endl;
        cout << "| " << "PIN: " << Client.GetCountryCode()<<endl;
        cout << "| " << "Currency: " << Client.GetCountryCurrency()<<endl;
        cout << "| " << "Rate: " << Client.GateExchangRate()<<endl;
    }

    static void PrintCurrencyDetails(clsCurrency Currency) {
        if (!Currency.IsEmpty()) { // Assuming IsEmpty checks if a valid currency was found
            PrintClientRecordLine(Currency);
        } else {
            cout << "Currency not found!" << endl;
        }
    }

public:

    static void PrintCurrency() {
        int choice = 0;
        cout << "Please choose an option to find the currency: " << endl;
        cout << "1. Find by Country Name" << endl;
        cout << "2. Find by Country Code" << endl;
        choice = clsInputValidate::ReadIntNumber();

        switch (choice) {
            case eCName: {
                string CountryName;
                cout << "Enter Country Name: ";
                CountryName = clsInputValidate::ReadString();
                clsCurrency Currency = clsCurrency::Find(CountryName); // Assuming FindByName method exists
                PrintCurrencyDetails(Currency);
                break;
            }
            case eCode: {
                string CountryCode;
                cout << "Enter Country Code: ";
                CountryCode = clsInputValidate::ReadString();
                clsCurrency Currency = clsCurrency::FindC(CountryCode); // Assuming FindByCode method exists
                PrintCurrencyDetails(Currency);
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                return;
        }
    }
};
