#pragma once
//#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsGlobal.h"
#include "clsDate.h"
//#include"Transformcreditscreen.h"

//using namespace Library;

class clsBankClient : public clsPerson {

private: 
     
    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode =2 };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    string _AccountBalance;
    bool   _MarkForDelete =false;
    
    static string GetTimeString(){
  
  time_t t = time(0);
  tm* now = localtime(&t);
  string Time= to_string(now->tm_hour) + ":";
  Time+= to_string( now->tm_min) + ":";
  Time+=to_string( now->tm_sec)+ ":";
  return Time;
}
    
      static string ConverClientObjectToLine(clsBankClient Client1, clsBankClient Client2, double TranferedCredit, string Seperator="#//#")
    {
        string stClientRecord = "";
        stClientRecord += GetTimeString() +"-"+ clsDate::DateToString(clsDate()) + Seperator ;
        stClientRecord += Client1.GetAccountNumber() +Seperator;
        stClientRecord += Client2.GetAccountNumber() +Seperator ;
        stClientRecord += to_string(TranferedCredit ) +Seperator;
        stClientRecord += Client2.GetAccountBalance()+ Seperator;
        stClientRecord += Client1.GetAccountBalance()+ Seperator;
        stClientRecord += CurrentUser.GetUserName();
        return stClientRecord;
    }

    
      static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Client.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    
    void AddNew(){
      
      
      
              AddDataLineToFile("Client.txt",ConverClientObjectToLine(*this,"#//#") );
    }
   static void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}



    
    void Update(string AccountNumber)
    {
      
      
      vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : vClients)
        {
            if (C.GetAccountNumber() == AccountNumber)
            {
                C = *this;
                break;
            }
        }

        SaveCleintsDataToFile("Client.txt",vClients); // Added filename argument for consistency
    }

    
    
    static vector<clsBankClient> SaveCleintsDataToFile(string FileName, vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out); //overwrite

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
              
              if(C._MarkForDelete==false){
                //we only write records that are not marked for delete.  
                string DataLine = ConverClientObjectToLine(C,"#//#");
                MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }

        return vClients;
    }

/*void AddDataLineToFile(clsBankClient Client1, clsBankClient Client2, string FileNam , string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}*/

                
                



   /* static string ConverClientObjectToLine(clsBankClient Client, string Seperator)
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
       stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.GetAccountBalance();
        return stClientRecord;
    }*/

    static clsBankClient ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], vClientData[6]);
    }

    static clsBankClient GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", "0");
    }

   


public:



static vector <clsBankClient> GeClientsList(){
  
  
  return _LoadClientsDataFromFile();
}




static string ConverClientObjectToLine(clsBankClient Client, string Seperator )
{
    string stClientRecord = "";
    
    stClientRecord += Client.GetFirstName() + Seperator;
    stClientRecord += Client.GetLastName() + Seperator;
    stClientRecord += Client.GetEmail() + Seperator;
    stClientRecord += Client.GetPinCode() + Seperator;
    stClientRecord += Client.GetAccountNumber() + Seperator;
    stClientRecord += Client.GetPhone() + Seperator;
    stClientRecord += Client.GetAccountBalance();
    return stClientRecord;
}


static clsBankClient MakeNewClient(){
  
  
   return clsBankClient( enMode::AddNewMode , "", "", "", "", "", "", "0" );
  
}

    


    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, string AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    enMode GetMode() {
        return _Mode;
    }

    void SetAccountNumber(string AccountNumber) {
        _AccountNumber = AccountNumber;
    }

    string GetAccountNumber() {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode) {
        _PinCode = PinCode;
    }

    string GetPinCode() {
        return _PinCode;
    }

    void SetAccountBalance(string AccountBalance) {
        _AccountBalance = AccountBalance;
    }

  string GetAccountBalance() {
        return _AccountBalance;
    }

    static clsBankClient Find(string AccountNumber, string FileName = "Client.txt")
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open(FileName, ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = ConvertLinetoClientObject(Line);
                if (Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }

            MyFile.close();
        }
        return GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode, string FileName = "Client.txt")
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open(FileName, ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = ConvertLinetoClientObject(Line);
                if ((Client.GetAccountNumber() == AccountNumber) && (Client.GetPinCode() == PinCode))
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }

            MyFile.close();
        }
        return GetEmptyClientObject();
    }

  /*  bool IsEmpty(clsBankClient Client) {
        return (Client.GetMode() == enMode::EmptyMode);
    }

   /* bool IsClientExsit(string AccountNumber) {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!IsEmpty(Client));
    }*/

    
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svAddedSuccesfully =2 , svFaildAccountNumExsit =3 };

     

bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

static bool IsClientExsit(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }




    enSaveResults Save()
    {
        switch (_Mode) {
        case enMode::EmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enMode::UpdateMode:
            Update(_AccountNumber); // Passing appropriate arguments
            return enSaveResults::svSucceeded;
            
        
        case enMode::AddNewMode:{
          
          if (IsClientExsit(_AccountNumber)){
      
      return enSaveResults::svFaildAccountNumExsit;
    }
          
           AddNew();
          _Mode = enMode::UpdateMode;
          return enSaveResults::svAddedSuccesfully;
        }

        
       /*  
        case enMode::ClientDeletMode :{
        DeletClient();
        
              *this =GetEmptyClientObject();
        return enSaveResults::svScssefullyDelet;
       }*/
    
    
    
    }
    
    }
    
    
    bool DeletClient(){
      
      vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : vClients)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        SaveCleintsDataToFile("Client.txt",vClients); // Added filename argument for consistency
        *this = GetEmptyClientObject();
        return true;
    }
      
      
/*  static  void ListAllClients(string FileName= "Client.txt"){
      
      vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : vClients)
        {
            
            
                
            
        }
      
      
    }*/
    
    
    
   static double TotalBalances() {
     double Balances =0;
       vector<clsBankClient> vClients = _LoadClientsDataFromFile();
       for (clsBankClient& C :vClients ){
         
         Balances =Balances + stod(C.GetAccountBalance());
         
       }
     
     return Balances;
     
   }
    
    
    void Deposit(double Balance){
      _AccountBalance =to_string (stod(GetAccountBalance()) +Balance);
      
      Save();
      
    }
    
    bool Withderaw(double Balance){
      if(stod(_AccountBalance)<Balance){
        return false;
      }
      
      _AccountBalance =to_string (stod(GetAccountBalance()) - Balance);
      
      Save();
      return true;
    }
    
    
    
    
    static bool TransformCredit(clsBankClient &Client1 , clsBankClient &Client2, double TranferedCredit){
   
   if (!(stod(Client1.GetAccountBalance())>TranferedCredit)){
     return false;
   }
     Client1.Withderaw(TranferedCredit);
     Client2.Deposit(TranferedCredit);
     string DataLine = ConverClientObjectToLine(Client1, Client2,TranferedCredit );
    AddDataLineToFile( "TransformCredit.txt" , DataLine);
     return true;
   
   
   
 }






/*static  vector<vector<string>> LoadUsersLoginFromFile()
    {

        vector<vector<string>> vUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                vector <string> vUser =clsString::Split(Line, "#//#");

                vUsers.push_back(vUser);
            }

            MyFile.close();

        }

        return vUsers;

    }*/

 
static  vector<vector<string>> LoadUsersLoginFromFile()
    {

        vector<vector<string>> vUsers;

        fstream MyFile;
        MyFile.open("TransformCredit.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                vector <string> vUser =clsString::Split(Line, "#//#");

                vUsers.push_back(vUser);
            }

            MyFile.close();

        }

        return vUsers;

    }

 

    
};
