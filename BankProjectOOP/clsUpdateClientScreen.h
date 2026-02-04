#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateClientScreen : protected clsScreen
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
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";
        cout << "Please enter an Account Number to Update Information : \n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n the Account Number you entered not find , please try again : \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
      
        _Print(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObejct:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print(Client1);
            break;
        }
        default:
            break;
        }

    }
};

