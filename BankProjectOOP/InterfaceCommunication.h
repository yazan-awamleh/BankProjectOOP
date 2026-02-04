#pragma once
#include <iostream>
using namespace std;
class InterfaceCommunication
{
public : 
	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string , string ) = 0;
	virtual void SendSMS(string , string ) = 0; // we cam ignore write name of parameter 
};
/*
1. Concepts in General

Interface = a contract that lists what functions must exist, without any implementation.

Abstract class = a base class that can contain some implementation and some abstract methods.

2. In C++

C++ does not have real interfaces.

An “interface” in C++ is just an abstract class with only pure virtual functions.

So the interface is a special case of an abstract class in C++.

3. In Java/C#

Interface and abstract class are two different types with different rules.

Interface = only function signatures.

Abstract class = can contain variables, implemented methods, and constructors.

*/