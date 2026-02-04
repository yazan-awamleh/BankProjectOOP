#pragma once
#include<iostream>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{
private : 
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;

public : 

	clsPerson(string FirstName, string LastName, string Phone, string Email)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	string GetLastName()
	{
		return _LastName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	string GetPhone()
	{
		return _Phone;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string GetEmail()
	{
		return _Email;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SendEmail(string title, string body)
	{
		cout << "Send Email implementation will be here ... \n";
	}
	void SendFax(string title, string body)
	{
		cout << "Send Fax implementation will be here ... \n";
	}
	void SendSMS(string title, string body)
	{
		cout << "Send SMS implementation will be here ... \n";
	}

};

