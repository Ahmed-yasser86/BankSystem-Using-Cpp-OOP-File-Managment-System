#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsString.h"
#include <type_traits>


class clsCurrency {
  
  
  private : 
  enum enMode { EmptyMode = 0, UpdateMode = 1};
  enMode  _Mode;
  string  _CountryName;
  string  _CountryCode;
  string  _CountryCurrency;
  double _ExchangRate;
  
  
  
  static clsCurrency GetEmptyClientObject(){
  
  return clsCurrency(enMode::EmptyMode,"","","",0);
  }
  
  
  
  
 
  
  static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.GetCountryName() + Seperator;
        stCurrencyRecord += Currency.GetCountryCode() + Seperator;
        stCurrencyRecord += Currency.GetCountryCurrency() + Seperator;
        stCurrencyRecord += to_string(Currency.GateExchangRate());
       
        return stCurrencyRecord;

    }
  
  
  
  static void SaveCleintsDataToFile(vector <clsCurrency> vCurrencys)
    {

        fstream MyFile;
        MyFile.open("currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                 DataLine = _ConverCurrencyObjectToLine(C);
                    MyFile << DataLine << endl;

                

            }

            MyFile.close();

        }

    }
  
  
  
  static  vector <clsCurrency> _LoadUsersDataFromFile()
    {

        vector <clsCurrency> vUsers;

        fstream MyFile;
        MyFile.open("currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsCurrency User = ConvertLinetoCurrencyObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }
  
  
  
  void _Update(string CountryName)
    {
      
      
      vector<clsCurrency> vClients = _LoadUsersDataFromFile();
        for (clsCurrency& C : vClients)
        {
            if (C.GetCountryName() == CountryName)
            {
                C = *this;
                break;
            }
        }

        SaveCleintsDataToFile(vClients); // Added filename argument for consistency
    }
  
  static clsCurrency ConvertLinetoCurrencyObject(string Line ){
    /*
    Azerbaijan#//#AZN#//#Azerbaijan Manat#//#1.694000
    */
    vector <string> vCurrency = clsString::Split(Line,"#//#");
    return clsCurrency( enMode::UpdateMode ,vCurrency[0],vCurrency[1],  vCurrency[2], stod(vCurrency[3]));
  }
  
 
  
  public :
  
   clsCurrency(enMode Mode ,string CName, string CCode, string CCurrency, double ExRate ){
   _Mode=Mode;
   _CountryName=CName;
   _CountryCode=CCode;
   _CountryCurrency=CCurrency;
   _ExchangRate=ExRate;
  }
  
  
  
  /*
  _Mode= enMode::UpdateMode;
  */
  
  enMode GetMode(){
    
    return _Mode;
  }
  
  string GetCountryCode(){
    
    return _CountryCode;
  }
  
  string GetCountryCurrency(){
    
    return _CountryCurrency;
  }
  
  string GetCountryName(){
    
    return _CountryName;
  }
  
  void UpdateExchangRate (double s1){
    
    _ExchangRate=s1;
    _Update(this->GetCountryName());
  }
  
  double GateExchangRate(){
    
   return _ExchangRate;
  }
  
 
  
  
  
  static clsCurrency Find(string CountryName, string FileName = "currencies.txt")
    {
           CountryName=clsString::UpperAllString(CountryName);
      
        vector<clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open(FileName, ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = ConvertLinetoCurrencyObject(Line);
                if ( clsString::UpperAllString( Currency._CountryName )== CountryName)
                {
                    MyFile.close();
                    return Currency;
                }
                vCurrencies.push_back(Currency);
            }

            MyFile.close();
        }
        return GetEmptyClientObject();
    }
  
  
  static clsCurrency FindC(string CountryCode, string FileName = "currencies.txt")
    {
      CountryCode= clsString::UpperAllString(CountryCode);
        vector<clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open(FileName, ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = ConvertLinetoCurrencyObject(Line);
                if (clsString::UpperAllString(Currency._CountryCode) == CountryCode)
                {
                    MyFile.close();
                    return Currency;
                }
                vCurrencies.push_back(Currency);
            }

            MyFile.close();
        }
        return GetEmptyClientObject();
    }
  
  
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    
   static  bool IsClientExist(string CountryName){
      clsCurrency Currency = clsCurrency::Find(CountryName);
        return (!Currency.IsEmpty());
    }
    
    
    
    static vector <clsCurrency> ListCurrencies(){
      
      vector <clsCurrency> Vcurrency = _LoadUsersDataFromFile();
      return Vcurrency;
    }
  
  
  
  static double ChangeFromXToDollers(string CS2, double Amount){
    
//  clsCurrency C1 = clsCurrency::FindC("USD");
  clsCurrency C2 = clsCurrency::FindC(CS2);
  
  return (Amount/ C2.GateExchangRate());
    
  }
  
static   double ChangeFromDollarsToY(string CS2 , string CS3 , double Amount){
    
     clsCurrency C2 = clsCurrency::FindC(CS3);
     if( C2.GetCountryCode()=="USD"){
       return ChangeFromXToDollers(CS2, Amount);
     }
     return C2.GateExchangRate() * ChangeFromXToDollers(CS2, Amount);
  }
  
  
 static double GetExRateFromXtoY(string CS2 , string CS3 , double Amount){
    
    
    return ChangeFromXToDollers( CS2, Amount)/ChangeFromDollarsToY( CS2 ,  CS3 , Amount);
  }
  
    /*bool IsClientExist(string Cod ){
      clsCurrency Currency = clsCurrency::LFind(Cod);
        return (!Client1.IsEmpty());
    }*/
    
    
    
    /*enum enSaveMode {enSavedSuccesfully =0, enFaildToSave=1};
    
    enSaveMode Save(){
      
      switch(_Mode){
      case enMode::EmptyMode:{
      return enSaveMode::enFaildToSave;}
      
        case enMode::UpdateMode:{
          UpdateExchangRate();
        return enSaveMode::enSavedSuccesfully;}
      }
    }
  */
};
