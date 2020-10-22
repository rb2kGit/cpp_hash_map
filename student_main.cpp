#include"student_hashTable.h"
#include<cstdlib>
#include<iostream>

using namespace std;

void main()
{
	int choice;
	int num = 123456;
	int age = 25;
	string name = "Jesus";
	Hash obj;
	
	cout << "Hello and welcome to the student has table program!" << endl << endl;
	
	while (1)
	{
		cout << "Please enter an option below to execute: " << endl;
		cout << "----------" << endl;
		cout << "1 = Insert a student into the table." << endl;
		cout << "2 = Display the contents of the hash table." << endl;
		cout << "3 = Search for and display the information of a student." << endl;
		cout << "4 = Delete a student from the table." << endl;
		cout << "5 = Exit." << endl;
		cout << "----------" << endl;
		cout << "->";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			obj.addStudent(obj);
			cout << "Student added successfully." << endl << endl;

			break;

		case 2:
			cout << "Here is the contents of the table." << endl << endl;
			obj.printTable();

			break;

		case 3:
			obj.searchStudent();

			break;

		case 4:
			cout << "Please choose how you would like to search for and delete a student :" << endl;
			obj.deleteStudent();

			break;

		case 5:
			exit(0);

		default:
			cout << "Sorry but that is not a valid input. Please try again." << endl << endl;

			break;

		}
	}
}