// Chad Huntebrinker
// crh92d@umsystem.edu
// 11/12/20
// CS201L Lab 12

#include <string>
#include "Employee.h"
using namespace std;


Employee::Employee(int id, string myName){
	employeeID = id;
	name = myName;
	payRate = 10.00;
	balance = 0;
	employed = true;
}

// Getter to return the employee ID
int Employee::getEmployeeID() { return employeeID; }

// Getter to return the current pay rate
double Employee::getPayRate() { return payRate; }

// Getter to return the current amount of pay earned
double Employee::getBalance() { return balance; }

// Getter to get Employee's name
string Employee::getName() { return name; }

// Function to give the raise. Have temp = the integer rate, change the 
// temp value into a deciaml by multiplying it by 0.01.  Then, it will multiply
//the temp value by the pay rate to get the raise and add that to the pay rate.
void Employee::giveRaise(int rate) {
	double temp = rate;
	temp = 0.01 * temp;
	payRate = payRate + (payRate * temp);
}

// Pays the employee by adding the rate to the current balance to
//get the new balance.
void Employee::pay() {
	balance = balance + payRate;
}

// Fires the Employee by changing the employed status to false and making
//the pay rate 0.
void Employee::fire() {
	employed = false;
	payRate = 0;
}

// Returns if the Employee is currently employed
bool Employee::isEmployed() { return employed; }