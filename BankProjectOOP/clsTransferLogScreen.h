#pragma once
#include "clsScreen.h"
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private : 

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << TransferLog.DateAndTime;
        cout << "| " << setw(8) << left << TransferLog.SrcAccount;
        cout << "| " << setw(8) << left << TransferLog.DestAccount;
        cout << "| " << setw(10) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.SrcAccountBalance;
        cout << "| " << setw(10) << left << TransferLog.DestAccountBalance;
        cout << "| " << setw(10) << left << TransferLog.UserName;
    }

public : 

	static void ShowTransferLogScreen()
	{
		_DrawScreenHeader("\t Transfer Log Screen");

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecords.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(8) << "SrcA";
        cout << "| " << left << setw(8) << "DestA";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "SrcA.B";
        cout << "| " << left << setw(10) << "DestA.B";
        cout << "| " << left << setw(10) << "User Name";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vTransferLogRecords.size() == 0)
            cout << "\t\t\t\tNo Transfer Log Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecords)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

	}

   

};

