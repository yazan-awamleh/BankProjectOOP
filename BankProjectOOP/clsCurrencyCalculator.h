#pragma once
#include "clsScreen.h"
#include <iostream>
#include "clsCurrency.h"


class clsCurrencyCalculator : protected clsScreen
{
private : 

	static clsCurrency _GetCurrency(string message)
	{
		cout << message;
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Not Found , enter another currency code : \n";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return C1;
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Currency From : ");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " " << "USD.\n";

		if (Currency2.CurrencyCode() == "USD")
			return;

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(Currency2, "Currency To : ");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		
		cout << Amount << " " << Currency1.CurrencyCode() <<
			" = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << "\n";

	}

public : 

	static void ShowCurrencyCalculatorScreen()
	{
		

		char Continue = 'Y';

		while (toupper(Continue) == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Exchange Calculator");

			clsCurrency CurrencyFrom = _GetCurrency("Enter a Currency 1 Code : \n");
			clsCurrency CurrencyTo = _GetCurrency("Enter a Currency 2 Code : \n");
			float Amount =_ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}



	}

};

