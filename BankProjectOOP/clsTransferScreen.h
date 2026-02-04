#pragma once
#include "clsScreen.h"
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n-------------------------------\n";
		cout << "Account Number : " << Client.AccountNumber() << "\n";
		cout << "Full Name : " << Client.FullName() << "\n";
		cout << "Account Balance : " << Client.AccountBalance << "\n";
		cout << "-------------------------------\n";
	}


public:

	/*static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		string AccountFrom, AccountTo;

		cout << "Enter an Account Number to transfer from : \n";
		AccountFrom = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountFrom))
		{
			cout << "Account Not Found , try again : \n";
			AccountFrom = clsInputValidate::ReadString();
		}
		clsBankClient ClientFrom = clsBankClient::Find(AccountFrom);
		_PrintClientRecordLine(ClientFrom);


		cout << "Enter an Account Number to transfer to : \n";
		AccountTo = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountTo))
		{
			cout << "Account Not Found , try again : \n";
			AccountTo = clsInputValidate::ReadString();
		}
		clsBankClient ClientTo = clsBankClient::Find(AccountTo);
		_PrintClientRecordLine(ClientTo);

		double Amount = 0;
		cout << "Enter an Amount to transfer it : \n";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount > ClientFrom.AccountBalance)
		{
			cout << "Amount exceeds a balance , try again : \n";
			Amount = clsInputValidate::ReadDblNumber();
		}

		char answer = 'n';
		cout << "Are you sure to perform this transfer [Y|N] ? \n";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			ClientFrom.AccountBalance -= Amount;
			ClientTo.AccountBalance += Amount;
			if (ClientFrom.Save() && ClientTo.Save())
			{
				cout << "\n Transfer Done Successfully :) \n";
				cout << "New Data : \n";
				_PrintClientRecordLine(ClientFrom);
				_PrintClientRecordLine(ClientTo);
			}
		}
	}*/

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		string AccountFrom, AccountTo;

		cout << "Enter an Account Number to transfer from : \n";
		AccountFrom = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountFrom))
		{
			cout << "Account Not Found , try again : \n";
			AccountFrom = clsInputValidate::ReadString();
		}
		clsBankClient ClientFrom = clsBankClient::Find(AccountFrom);
		_PrintClientCard(ClientFrom);


		cout << "Enter an Account Number to transfer to : \n";
		AccountTo = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountTo) || AccountTo == AccountFrom)
		{
			cout << "Invalid Account Number , try again : \n";
			AccountTo = clsInputValidate::ReadString();
		}
		
		
		clsBankClient ClientTo = clsBankClient::Find(AccountTo);
		_PrintClientCard(ClientTo);

		double Amount = 0;
		cout << "Enter an Amount to transfer it : \n";
		Amount = clsInputValidate::ReadNumber<double>();
		while (Amount > ClientFrom.AccountBalance)
		{
			cout << "Amount exceeds a balance , try again : \n";
			Amount = clsInputValidate::ReadNumber<double>();
		}

		char answer = 'n';
		cout << "Are you sure to perform this transfer [Y|N] ? \n";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			if (ClientFrom.Transfer(Amount, ClientTo))
			{
				cout << "\nTransfer Done Successfully :) \n";
				cout << "New Data : \n";
				_PrintClientCard(ClientFrom);
				_PrintClientCard(ClientTo);
				ClientFrom.TransferLog(Amount, ClientTo);
			}
			else
				cout << "\nTransfer Failed ! :( \n";
		}
	}
};

