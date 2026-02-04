#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");

        string AccountNumber = "";
        cout << "Please enter an Account Number to Deposit to Account Balance : \n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n the Account Number you entered not find , please try again : \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _Print(Client1);

        double AmountToDeposit = 0;

        cout << "Please enter an Amount to deposit to Account ? \n";
        AmountToDeposit = clsInputValidate::ReadNumber<double>();

        char answer = 'y';
        cout << "Are you sure to perform this transaction ? \n";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
           Client1.Deposit(AmountToDeposit);
           cout << " Succeeded :) \n ";
           cout << "New Account Balance =  " << Client1.AccountBalance << "\n";
        }
    }
};

