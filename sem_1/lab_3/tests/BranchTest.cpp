#include <gtest/gtest.h>
#include "../Branch/Branch.h"
#include "../ATM/ATM.h"
#include "../Employee/Employee.h"
#include "../Customer/Customer.h"
#include "../Account/Account.h"
#include "../Loan/Loan.h"

// Тест на добавление и получение сотрудников
TEST(BranchTest, AddAndRetrieveEmployees) {
    Branch branch(1, "Main Street");
    Employee* emp1 = new Employee(1, "Main Street", 1, "Barbara Green", "Manager", 2400.00);
    Employee* emp2 = new Employee(2, "Jane Smith", 2, "Dmitry Green", "Loan Officer", 3400.00);

    branch.addEmployee(emp1);
    branch.addEmployee(emp2);

    auto employees = branch.getEmployees();
    ASSERT_EQ(employees.size(), 2);
    EXPECT_EQ(employees[0]->getEmpID(), 1);
    EXPECT_EQ(employees[1]->getEmpID(), 2);

    delete emp1;
    delete emp2;
}

// Тест на добавление и получение клиентов
TEST(BranchTest, AddAndRetrieveCustomers) {
    Branch branch(1, "Main Street");
    Customer* cust1 = new Customer(1, "Minsk", 1, "John Doe");
    Customer* cust2 = new Customer(2, "London", 2, "Jane Smith");

    branch.addCustomer(cust1);
    branch.addCustomer(cust2);

    auto customers = branch.getCustomers();
    ASSERT_EQ(customers.size(), 2);
    EXPECT_EQ(customers[0]->get_costumer_id(), 1);
    EXPECT_EQ(customers[1]->get_costumer_id(), 2);

    delete cust1;
    delete cust2;
}

// Тест на добавление и получение счетов
TEST(BranchTest, AddAndRetrieveAccounts) {
    Branch branch(1, "Main Street");
    Account* acc1 = new Account(1, "Munich", 321, "John Doe", 1, "Saving", 24.00);
    Account* acc2 = new Account(2, "Berlin", 120, "John Black", 2, "Checking", 239.00);

    branch.addAccount(acc1);
    branch.addAccount(acc2);

    auto accounts = branch.getAccounts();
    ASSERT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0]->accountNumber(), 1);
    EXPECT_EQ(accounts[1]->accountNumber(), 2);

    delete acc1;
    delete acc2;
}

// Тест на добавление и получение займов
TEST(BranchTest, AddAndRetrieveLoans) {
    Branch branch(1, "Main Street");
    Loan* loan1 = new Loan(1, "Dublin", 1, "Michael Green", 1, 123.00, 23.5);
    Loan* loan2 = new Loan(2, "Moscow", 2, "Michael Cole", 2, 153.00, 28.5);

    branch.addLoan(loan1);
    branch.addLoan(loan2);

    auto loans = branch.getLoans();
    ASSERT_EQ(loans.size(), 2);
    EXPECT_EQ(loans[0]->get_loan_id(), 1);
    EXPECT_EQ(loans[1]->get_loan_id(), 2);

    delete loan1;
    delete loan2;
}

// Тест на добавление и получение банкоматов
TEST(BranchTest, AddAndRetrieveATMs) {
    Branch branch(1, "Main Street");
    ATM* atm1 = new ATM(1, "Main ATM", 5000, 10);
    ATM* atm2 = new ATM(2, "Branch ATM", 3000, 8);

    branch.addATM(atm1);
    branch.addATM(atm2);

    auto atms = branch.getATMs();
    ASSERT_EQ(atms.size(), 2);
    EXPECT_EQ(atms[0]->atm_amount(), 5000);
    EXPECT_EQ(atms[1]->atm_amount(), 3000);

    delete atm1;
    delete atm2;
}

// Тест на вычисление общей суммы денежных средств
TEST(BranchTest, CalculateTotalCashOnHand) {
    Branch branch(1, "Main Street");
    branch.calculateTotalCashOnHand();
    EXPECT_EQ(branch.calculateTotalCashOnHand(), 0); // Проверка начального значения
}

// Тест на вывод информации о филиале
TEST(BranchTest, DisplayBranchInfo) {
    Branch branch(1, "Main Street");
    testing::internal::CaptureStdout();
    branch.displayBranchInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Branch ID: 1"), std::string::npos);
    EXPECT_NE(output.find("Location: Main Street"), std::string::npos);
}