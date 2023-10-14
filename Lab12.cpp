// Chad Huntebrinker
// crh92d@umsystem.edu
// 11/12/20
// CS201L Lab 12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

int main() {
	vector<Employee> employeeVector;
	ifstream fin;
	ofstream fout;
	string commandWord, name;
	int ID, raise;

	fin.open("input.txt");
	fout.open("output.txt");

	//This while loop executes so long as there is a command word (NEW, RAISE,
	//PAY, & FIRE) read from the file.  Then, an if statement will execute depending on the
	//command word.
	while (fin >> commandWord) {

		//This if statement is for the command word NEW.  It will get the ID number and the
		//name of the person, store it in a temp Employee class, and put it in the vector.
		if (commandWord == "NEW") {
			fin >> ID;
			getline(fin, name);
			Employee temp{ ID, name };
			employeeVector.push_back(temp);
		}
		//This if statment executes when the command word is RAISE. It will then read in the ID
		//number and compare that with all the employees in the vector.  Once the right one is found, it
		//will then execute the giveRaise function to that correct employee and exit out of the loop.
		else if (commandWord == "RAISE") {
			fin >> ID;
			for (int i = 0; employeeVector.size(); ++i) {
				if (employeeVector.at(i).getEmployeeID() == ID) {
					fin >> raise;
					employeeVector.at(i).giveRaise(raise);
					break;
				}
			}
		}
		//This if statment executes when the command word is PAY. It will then go through all
		//the employees in the vector and execute the pay() function to all employees.
		else if (commandWord == "PAY") {
			for (int i = 0; i < employeeVector.size(); ++i) {
				employeeVector.at(i).pay();
			}
		}

		//This if statment executes when the command word is FIRE. It will then read in the ID
		//number and compare that with all the employees in the vector.  Once one is found, it
		//will then execute the fire() function to that single employee and exit the loop.
		else if (commandWord == "FIRE") {
			fin >> ID;
			for (int i = 0; i < employeeVector.size(); ++i) {
				if (employeeVector.at(i).getEmployeeID() == ID) {
					employeeVector.at(i).fire();
					break;
				}
			}
		}
	}

	//This loop sorts the employees by their ID number. It sorts them lowest at the top
	//and highest at the bottom.
	for (int i = 1; i < employeeVector.size(); ++i) {
		int j;
		for (j = 1; j < i; ++j) {
			while (j > 0 && employeeVector.at(j - 1).getEmployeeID() > employeeVector.at(j).getEmployeeID()) {
				Employee temp = employeeVector.at(j);
				employeeVector.at(j) = employeeVector.at(j - 1);
				employeeVector.at(j - 1) = temp;
			}
		}
	}



	//This loop outputs all the information out to the file.
	for (int i = 0; i < employeeVector.size(); ++i) {
		Employee temp = employeeVector.at(i);
		

		fout << temp.getName() << ", ID Number " << temp.getEmployeeID() << ":" << endl;
		
		if (temp.isEmployed()) {
			fout << "Current pay rate: $" << temp.getPayRate() << endl;
		}
		else {
			fout << "Not employed with the company." << endl;
		}

		fout << "Pay earned to date: $" << temp.getBalance() << endl << endl;
	}
	//Exact same as the above outputter, only it will output the same information
	//on the screen. That way, you don't have to look at the file all the time.
	for (int i = 0; i < employeeVector.size(); ++i) {
		Employee temp = employeeVector.at(i);
		
		
		cout << temp.getName() << ", ID Number " << temp.getEmployeeID() << ":" << endl;
		
		if (temp.isEmployed()) {
			cout << "Current pay rate: $" << temp.getPayRate() << endl;
		}
		else {
			cout << "Not employed with the company." << endl;
		}

		cout << "Pay earned to date: $" << temp.getBalance() << endl << endl;
	}

	return 0;
}