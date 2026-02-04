#pragma once
#include "clsPerson.h"
#include <iostream>
#include <vector>
#include <string>
#include "clsString.h"
#include <fstream>
#include "clsDate.h"
using namespace std;

class clsBankClient : public clsPerson
{
private : 
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkedForDeleted = false;
	enum enMode { EmptyMode  = 0 , UpdateMode = 1 , AddNew = 2 };
	enMode _Mode;

	

	string _PrepareTransferLogRecord(double Amount , clsBankClient &ClientTo , string Sep = "#//#")
	{
		string TransferLogLine = "";
		TransferLogLine += clsDate::GetSystemDateTimeString() + Sep;
		TransferLogLine += AccountNumber() + Sep;
		TransferLogLine += ClientTo.AccountNumber() + Sep;
		TransferLogLine += to_string(Amount) + Sep;
		TransferLogLine += to_string(AccountBalance) + Sep;
		TransferLogLine += to_string(ClientTo.AccountBalance) + Sep;
		TransferLogLine += CurrentUser.UserName;

		return TransferLogLine;

	}

	static clsBankClient _GetEmptyUserObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToClientObject(string Line , string Sep = "#//#")
	{
		vector <string> vClients = clsString::Split(Line, Sep);

		if (vClients.size() < 7) // to hudled a expetion if a record not correct 
		return _GetEmptyUserObject();

		return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1], vClients[2], vClients[3], 
			vClients[4], vClients[5], stod(vClients[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient &C1, string Sep = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += C1.FirstName + Sep;
		ClientRecord += C1.LastName + Sep;
		ClientRecord += C1.Phone + Sep;
		ClientRecord += C1.Email + Sep;
		ClientRecord += C1.AccountNumber() + Sep;
		ClientRecord += C1.PinCode + Sep;
		ClientRecord += to_string(C1.AccountBalance);

		return ClientRecord;
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // In Read Mode To Load Data 

		vector <clsBankClient> vClients;

		if (MyFile.is_open())
		{
			string DataLine = "";
			
			while (getline(MyFile , DataLine))
			{
				clsBankClient Client = _ConvertLineToClientObject(DataLine);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
      
		return vClients;
	}

	static void _SaveClientDataToFile(vector<clsBankClient> &vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // In Overwrite Mode

		if (MyFile.is_open())
		{
			string DataLine = "";

			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDeleted == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << "\n";
				}
			}
			MyFile.close();
		}		
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertLinetoTransferLogRecord(string Line, string Seperator = "#//#")
	{
		vector<string> vTransferLog;
		vTransferLog = clsString::Split(Line, Seperator);

		stTransferLogRecord TransferLogRecord;
		TransferLogRecord.DateAndTime = vTransferLog[0];
		TransferLogRecord.SrcAccount = vTransferLog[1];
		TransferLogRecord.DestAccount = vTransferLog[2];
		TransferLogRecord.Amount = stod(vTransferLog[3]);
		TransferLogRecord.SrcAccountBalance= stod(vTransferLog[4]);
		TransferLogRecord.DestAccountBalance = stod(vTransferLog[5]);
		TransferLogRecord.UserName = vTransferLog[6];
		

		return TransferLogRecord;
	}

	static  vector < stTransferLogRecord> _LoadTransferLogDataFromFile()
	{

		vector <stTransferLogRecord> vTransferLogTRecords;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				stTransferLogRecord TransferLogRecord = _ConvertLinetoTransferLogRecord(Line);

				vTransferLogTRecords.push_back(TransferLogRecord);
			}

			MyFile.close();

		}

		return vTransferLogTRecords;

	}

public : 
	clsBankClient(enMode Mode, string FirstName, string LastName, string Phone, string Email, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Phone, Email)
	{
		_Mode = Mode; 
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}

	struct stTransferLogRecord
	{
		string DateAndTime;
		string SrcAccount;
		string DestAccount;
		double Amount;
		double SrcAccountBalance;
		double DestAccountBalance;
		string UserName;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() //Read Only Property
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	// No Any UI  Code inside an Object !!! 
	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}*/


	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	enum enSaveResult { svFaildEmptyObejct = 0, svSucceeded = 1 , svFaildAccountExists = 2};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
		{
			return enSaveResult::svFaildEmptyObejct;
			break;
		}
		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case clsBankClient::AddNew:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		default:
			break;
		}
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.MarkedForDeleted = true;
				break;
			}
		}

		_SaveClientDataToFile(vClients); // to delete data drom file 
		*this = _GetEmptyUserObject(); // to delete data drom object
		return true;
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}
	
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient& ClientTo)
	{
		if (Amount > AccountBalance)
			return false;

		Withdraw(Amount);
		ClientTo.Deposit(Amount);
		return true;
	}

	void TransferLog(double Amount, clsBankClient& ClientTo)
	{
		string LoginRecord = _PrepareTransferLogRecord(Amount , ClientTo);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << LoginRecord << "\n";

			MyFile.close();
		}

	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		return _LoadTransferLogDataFromFile();
	}

};

