#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsAddNewClientScreen : protected clsScreen
{
private : 

    static void _ReadClientInfo(clsBankClient& C1)
    {
        cout << "Enter First Name : \n";
        C1.FirstName = clsInputValidate::ReadString();

        cout << "Enter Last Name : \n";
        C1.LastName = clsInputValidate::ReadString();

        cout << "Enter Phone : \n";
        C1.Phone = clsInputValidate::ReadString();

        cout << "Enter Email : \n";
        C1.Email = clsInputValidate::ReadString();

        cout << "Enter PIN Code : \n";
        C1.PinCode = clsInputValidate::ReadString();

        cout << "Enter Account Balance : \n";
        C1.AccountBalance = clsInputValidate::ReadNumber<float>();
    }

   static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

public : 
   static void ShowAddNewClientScreen()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
       {
           return;// this will exit the function and it will not continue
       }
       _DrawScreenHeader("\t Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _Print(NewClient);
            break;
        }
        case clsBankClient::enSaveResult::svFaildEmptyObejct:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResult::svFaildAccountExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};

