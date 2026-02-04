#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainMenueScreen.h"
#include "clsBankUser.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private : 
	static bool _Login()
	{
		string UserName = "", Password = "";
		bool LoginFailed = false;
		short LoginFailedCounter = 0;
		do
		{
			if (LoginFailed)
			{
				LoginFailedCounter++;
				cout << "\nInvalid Username/Password!\n\n";
				cout << "\n You have " << (3 - LoginFailedCounter) << " Trial(S) to login \n\n";
				
			}
			if (LoginFailedCounter == 3)
			{
				cout << "\nYou are locked after 3 trial \n\n";
				return false;
			}
			cout << "Enter User Name : ";
			cin >> UserName;

			cout << "Enter Password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
	}

public : 

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}

};

