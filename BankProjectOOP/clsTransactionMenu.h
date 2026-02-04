#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen :protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4 , eTransferLog = 5, eShowMainMenue = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalances::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
      //  cout << "Transfer Screen Will Be Here ... \n";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        //cout << "Transfer Log Screen Will Be Here ... \n";

        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void GoBackToTransactionsMenue()
    {
        cout << "press any key to go back to transactions menu : ";
        system("pause > 0 ");
        ShowTransactionsMenue();
    }
    
    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions Option)
    {
        switch (Option)
        {
        case clsTransactionsScreen::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            GoBackToTransactionsMenue();
            break;
        }
        case clsTransactionsScreen::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            GoBackToTransactionsMenue();
            break;
        }

        case clsTransactionsScreen::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            GoBackToTransactionsMenue();
            break;
        }
        case clsTransactionsScreen::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            GoBackToTransactionsMenue();
            break;
        }
        case clsTransactionsScreen::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            GoBackToTransactionsMenue();
            break;
        }
        }
    }


public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }

};

