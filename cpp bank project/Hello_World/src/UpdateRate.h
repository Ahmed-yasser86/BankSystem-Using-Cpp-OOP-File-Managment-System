#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsString.h"
#include "clsCurrencey.h"

class clsUpdateCurrency {
  
    enum Type { eCName = 1, eCode = 2 };

    static void PrintCurrencyDetails(clsCurrency Client) {
        cout << "| " << "Country: " << Client.GetCountryName()<<endl;
        cout << "| " << "PIN: " << Client.GetCountryCode()<<endl;
        cout << "| " << "Currency: " << Client.GetCountryCurrency()<<endl;
        cout << "| " << "Rate: " << Client.GateExchangRate()<<endl;
    }
    
 static   void UpdateCurrency(clsCurrency& Client){
      
      
      
      double x=0;
      cout<<" enter the new rate "<<endl;
      cin>>x;
      Client.UpdateExchangRate(x); 
       
    }
    
    public:
 static   void PrintUpdateScreen(){
      
      
       cout<<" are you sure of that Y/N : "<<endl;
       char y='n';
       cin>>y;
      if (y=='y'||y=='Y'){
    string CountryCode;
    cout << "Enter Country Code: ";
    CountryCode = clsInputValidate::ReadString();
    clsCurrency Currency = clsCurrency::FindC(CountryCode); // Assuming FindByCode method exists
    PrintCurrencyDetails(Currency);
        
        if(!Currency.IsEmpty()){
          UpdateCurrency( Currency);
          PrintCurrencyDetails(Currency) ;
          cout<<"it has updated succesfully "<<endl;
        }
        else{
          cout <<"sorry for that its not exist"<<endl;
        }
      }
      
    }
    
    
   } ;