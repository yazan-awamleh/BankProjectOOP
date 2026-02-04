#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t Find Client Screen");

        string AccountNumber = "";
        cout << "Please enter an Account Number to Update Information : \n";
        AccountNumber = clsInputValidate::ReadString();

        char answer = 'n';

        if(!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Sorry , Client Not Found !\n";
            return;
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        cout << "\n Client Found :) \n";
       _Print(Client1); 
	}
};

