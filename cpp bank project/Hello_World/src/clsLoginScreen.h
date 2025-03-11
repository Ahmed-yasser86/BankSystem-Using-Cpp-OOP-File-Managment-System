#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUser.h"
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeletUserScree.h"
#include "UpdateScreen.h"
#include "FindUserScreen.h"
#include "clsMainScreenMenu.h"
#include "clsGlobal.h"

class clsLogin : protected clsScreen{
  private:
static  bool Login()
{
    int counter=0;
    bool LoginFaild = false;

    string Username, Password;
    do
    {
        system("cls");

        

        if (LoginFaild)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

       CurrentUser = clsUser::Find(Username, Password);  
       
        LoginFaild = CurrentUser.IsEmpty();

       if (LoginFaild){
          counter++;
          cout <<" \t\t\t\t login Faild "<< counter << endl;
       }
     if (counter==3){
     cout<<" sorry you can't login "<<endl;
       return false;
     }
     
    
    } while (LoginFaild);

 /*string UserData= ConverUserDataObjectToLine();*/
   /*_AddDataLineToFile( UserData );*/
   CurrentUser.AddLoginDataLineToFile();
   clsMainScreenMenu::ShowMainMenue();
   
  return true ;  

}

static string GetTimeString(){
  
  time_t t = time(0);
  tm* now = localtime(&t);
  string Time= to_string(now->tm_hour) + ":";
  Time+= to_string( now->tm_min) + ":";
  Time+=to_string( now->tm_sec)+ ":";
  return Time;
}



 static string ConverUserDataObjectToLine( string Seperator = "#//#")
    {
        string Date =clsDate::DateToString(clsDate());
        string Time = GetTimeString();
        string UserRecord = "";
        UserRecord= Date+"-"+Time;
        UserRecord += CurrentUser.GetUserName() + Seperator;
        UserRecord += CurrentUser.GetPassword() + Seperator;
        UserRecord += to_string(CurrentUser.GetPermissions());

        return UserRecord;

    }






public :



static void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


static bool ShowLoginScreen(){
  
  
  clsScreen::ShowScreenHeader("Login Screen", "welcom to our system :-/)/ ");
  return Login();
}
  
  
  
};

