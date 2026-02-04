#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include <iostream>
#include <string>
#include <vector>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculator.h"

using namespace std;
class clsCurrencyExchangeMainMenu : protected clsScreen
{
private : 
	enum enCurrenciesMainMenuOptions {
      enListCurrencies = 1 ,eFindCurrency = 2 , 
	  eUpdateCurrencyRate = 3 , eCurrencyCalculator = 4 , eCurrencyMainMenu = 5
	};

	static short _ReadCurrencyMainMenuOption()
	{
		short option = (short)clsInputValidate::ReadNumberBetween(1, 5, "Enter a Number between 1 and 5 please : \n");
		return option;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "List Currencies will be here ... \n";
		// this call stub function we make a skeleton of system without  make internal implementation 

		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency will be here ... \n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "Update Currency Rate will be here ... \n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << " Currencies Calculator  will be here ... \n";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();

	}

	static void _GoBackToCurrencyMenu()
	{
		cout << "press any key to go back to currency menu : ";
		system("pause>0");
		ShowCurrenciesMainMenu();
	}

	static void _PerformCurrencyMenuOption(enCurrenciesMainMenuOptions Option)
	{
		switch (Option)
		{
		case clsCurrencyExchangeMainMenu::enListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyExchangeMainMenu::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyExchangeMainMenu::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyExchangeMainMenu::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		
		}
	}

public : 

	static void ShowCurrenciesMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t Currencies Main Menu Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenuOption((enCurrenciesMainMenuOptions)_ReadCurrencyMainMenuOption());
	}
	

};

