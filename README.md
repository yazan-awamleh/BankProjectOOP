# BankProjectOOP

**A Console-Based Banking System Implemented in C++ Using Full Object-Oriented Programming (OOP)**

## Overview

**BankProjectOOP** is a fully-featured banking system developed entirely in **C++** using **object-oriented programming principles**. The project is structured with clean architecture, dividing functionalities into **classes and header files**, ensuring modularity, maintainability, and readability. Data is stored in **text files**, providing a simple yet effective persistence solution without external databases.

The system allows multiple users with **permission-based access**. Administrators have full control, while regular users have restricted permissions. User credentials are validated at login with **three attempts**, ensuring security.

All screens display the **current username, date, and time**, enhancing user experience and traceability.

## Key Features

* **Client Management:** Show client list, add, delete, update, and find clients.
* **Transactions:** Deposit, withdraw, transfer funds, view total balances, and transaction logs.
* **User Management:** List users, add, delete, update, and find users with permission control.
* **Login & Registration:** Secure authentication with role-based access.
* **Currency Exchange:** List currencies, find currency, update rates, and calculate conversions.
* **Interactive Menus:** Multiple menus with input validation to prevent errors.
* **Permission System:** Implemented using **binary bitwise AND**, defining user roles and accessible features.
* **Clean Architecture:** Functionalities divided into separate classes and header files for modularity.
* **OOP Concepts:** Inheritance, encapsulation, abstraction, and modular class design.
* **Console UI Enhancements:** Current username, date, and time displayed on all screens.


## Menus Overview

### Main Menu Options

1. Show Client List
2. Add New Client
3. Delete Client
4. Update Client Info
5. Find Client
6. Transactions
7. Manage Users
8. Login/Register
9. Currency Exchange
10. Logout

### Transactions Menu

1. Deposit
2. Withdraw
3. Total Balances
4. Transfer
5. Transfer Log
6. Main Menu

### Manage Users Menu

1. List Users
2. Add New User
3. Delete User
4. Update User
5. Find User
6. Main Menu

### Currency Exchange Menu

1. List Currencies
2. Find Currency
3. Update Rate
4. Currency Calculator
5. Main Menu

## Technologies & Concepts Used

* **C++** programming language
* **Object-Oriented Programming (OOP):**

  * Classes & Objects
  * Inheritance & Abstraction
  * Encapsulation
  * Modular design (Clean Architecture)
* **File Management:** Data persistence in **TXT files**
* **Permission System:** Binary Bitwise AND for user roles
* **Input Validation:** Ensures safe and correct operations
* **Console UI Features:** Dynamic display of username, date, and time
