#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:

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

public:
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Withdraw Screen");

        string AccountNumber = "";
        cout << "Please enter an Account Number to Withdraw from Account Balance : \n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n the Account Number you entered not find , please try again : \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _Print(Client1);

        double AmountToWithdraw = 0;

        cout << "Please enter an Amount to withdraw from Account ? \n";
        AmountToWithdraw = clsInputValidate::ReadNumber<double>();

        while (AmountToWithdraw > Client1.AccountBalance)
        {
            cout << "Your balance not enough  , try again : \n";
            AmountToWithdraw = clsInputValidate::ReadNumber<double>();
        }
         
        char answer = 'y';
        cout << "Are you sure to perform this transaction ? \n";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            
            if (Client1.Withdraw(AmountToWithdraw))
            {
                cout << " Succeeded :) \n ";
                cout << "New Account Balance =  " << Client1.AccountBalance << "\n";
            }
            else
            {
                cout << "Operation Failed Balance Not enought !\n";
                cout << "Account Balance = " << Client1.AccountBalance << "\n";
                cout << "Amount = " << AmountToWithdraw << "\n";
            }
        }
    }
};

