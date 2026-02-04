#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsDeleteClientScreen : protected clsScreen
{
private : 
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
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber = "";
        cout << "Please enter an Account Number to Delete : \n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n the Account Number you entered not find , please try again : \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);

        char answer = 'n';
        cout << "Are you sure to delete this client ? \n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "Client Deleted Successfully ! \n";
                _Print(Client1);
            }
            else
            {
                cout << "Client Delete Failed !! \a\n";
            }
        }
    }


};

