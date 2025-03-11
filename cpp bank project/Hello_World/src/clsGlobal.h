#pragma once
#include "clsUser.h"
#include "clsDate.h"
#include "ctime"
clsUser CurrentUser=clsUser::Find("","");

/*

string GetTimeString(){
  
  time_t t = time(0);
  tm* now = localtime(&t);
  string Time= to_string(now->tm_hour);
  Time+= to_string( now->tm_min);
  Time+=to_string( now->tm_sec);
  return Time;
}



 string ConverUserDataObjectToLine( string Seperator = "#//#")
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

string UserData= ConverUserDataObjectToLine();*/
