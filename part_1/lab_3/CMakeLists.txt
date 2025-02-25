cmake_minimum_required(VERSION 3.29)
project(BankingSys)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(BankingSys main.cpp
        Bank/Bank.cpp
        Bank/Bank.h
        Branch/Branch.cpp
        Branch/Branch.h
        Employee/Employee.cpp
        Employee/Employee.h
        LoanOfficer/LoanOfficer.cpp
        LoanOfficer/LoanOfficer.h
        Manager/Manager.cpp
        Manager/Manager.h
        Customer/Customer.cpp
        Customer/Customer.h
        Account/Account.cpp
        Account/Account.h
        SavingAccount/SavingAccount.cpp
        SavingAccount/SavingAccount.h
        CheckingAccount/CheckingAccount.cpp
        CheckingAccount/CheckingAccount.h
        Loan/Loan.cpp
        Loan/Loan.h
        MortgageLoan/MortgageLoan.cpp
        MortgageLoan/MortgageLoan.h
        PersonalLoan/PersonalLoan.cpp
        PersonalLoan/PersonalLoan.h
        Investment/Investment.cpp
        Investment/Investment.h
        ATM/ATM.cpp
        ATM/ATM.h
        DepositInvestment/DepositInvestment.cpp
        DepositInvestment/DepositInvestment.h
        StockInvestment/StockInvestment.cpp
        StockInvestment/StockInvestment.h)

add_executable(BankingSysTest
        Account/Account.cpp
        Account/Account.h
        tests/AccountTest.cpp
        ATM/ATM.cpp
        ATM/ATM.h
        tests/ATMTest.cpp
        Bank/Bank.cpp
        Bank/Bank.h
        tests/BankTest.cpp
        Branch/Branch.cpp
        Branch/Branch.h
        tests/BranchTest.cpp
        CheckingAccount/CheckingAccount.cpp
        CheckingAccount/CheckingAccount.h
        tests/CheckingAccount.cpp
        Customer/Customer.cpp
        Customer/Customer.h
        tests/CustomerTest.cpp
        DepositInvestment/DepositInvestment.cpp
        DepositInvestment/DepositInvestment.h
        tests/DepositInvestment.cpp
        Employee/Employee.cpp
        Employee/Employee.h
        tests/EmployeeTest.cpp
        Investment/Investment.cpp
        Investment/Investment.h
        tests/InvestmentTest.cpp
        Loan/Loan.cpp
        Loan/Loan.h
        tests/LoanTest.cpp
        LoanOfficer/LoanOfficer.cpp
        LoanOfficer/LoanOfficer.h
        tests/LoanOfficerTest.cpp
        Manager/Manager.cpp
        Manager/Manager.h
        tests/ManagerTest.cpp
        MortgageLoan/MortgageLoan.cpp
        MortgageLoan/MortgageLoan.h
        tests/MortgageLoanTest.cpp
        PersonalLoan/PersonalLoan.cpp
        PersonalLoan/PersonalLoan.h
        tests/PersonalLoanTest.cpp
        SavingAccount/SavingAccount.cpp
        SavingAccount/SavingAccount.h
        tests/SavingAccount.cpp
        StockInvestment/StockInvestment.cpp
        StockInvestment/StockInvestment.h
        tests/StockInvestmentTest.cpp)

target_link_libraries(BankingSysTest gtest gtest_main)

enable_testing()

add_test(NAME BankingSysTest COMMAND BankingSysTest)