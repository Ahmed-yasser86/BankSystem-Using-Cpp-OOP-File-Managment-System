#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsGlobal.h"
using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;


    bool _MarkedForDelete = false;



 string GetlTimeString(){
  
  time_t t = time(0);
  tm* now = localtime(&t);
  string Time= to_string(now->tm_hour) + ":";
  Time+= to_string( now->tm_min) + ":";
  Time+=to_string( now->tm_sec)+ ":";
  return Time;
}



static string IncryptPassWord(string Password, int EnKey) {
    for (int i = 0; i < Password.length(); i++) {
        int x = static_cast<int>(Password[i]) + EnKey; // Convert char to int and add EnKey
        Password[i] = static_cast<char>(x); // Convert the result back to char
    }
    return Password;
}


static string DecryptPassWord(string Password, int EnKey) {
    for (int i = 0; i < Password.length(); i++) {
        int x = static_cast<int>(Password[i]) - EnKey; // Convert char to int and add EnKey
        Password[i] = static_cast<char>(x); // Convert the result back to char
    }
    return Password;
}


  string ConverUserLoginDataObjectToLine( string Seperator = "#//#")
    {
        string Date =clsDate::DateToString(clsDate());
        string Time = GetlTimeString();
        string UserRecord = "";
        UserRecord += Date+"-"+Time+ Seperator;
        UserRecord += this->GetUserName() + Seperator;
        UserRecord += this->GetPassword() + Seperator;
        UserRecord += to_string(this->GetPermissions());

        return UserRecord;    }


public :



 void AddLoginDataLineToFile()
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);
        string  stDataLine= ConverUserLoginDataObjectToLine();
        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }






    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], DecryptPassWord(vUserData[5],5), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        string Password =IncryptPassWord( User.GetPassword(), 5);
        UserRecord += User.GetFirstName() + Seperator;
        UserRecord += User.GetLastName() + Seperator;
        UserRecord += User.GetEmail() + Seperator;
        UserRecord += User.GetPhone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
      
        UserRecord += Password + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

   static vector<clsUser> LoadUsers() {
        return _LoadUsersDataFromFile();
    }

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    //__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
  //  __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

   int GetPermissions()
    {
        return _Permissions;
    }
  //  __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

   enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 , LoginRegister  = 128
};



 bool CheckAccessPermission(enMainMenuePermissions Permission)
{
    if (this->GetPermissions() == enMainMenuePermissions::eAll)
        return true;

    if ((Permission & this->GetPermissions() ) == Permission)
        return true;
    else
        return false;}


static  vector<vector<string>> LoadUsersLoginFromFile()
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

    }

 
 
 



};
