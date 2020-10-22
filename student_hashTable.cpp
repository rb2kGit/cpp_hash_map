#include"student_hashTable.h"
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

void Student::defaultSetter()
{
	studentNum = 000000;
	name = "none";
	mark = 0.0;
}

void Student::setInfo(int snum, float smark, string sname)
{
	studentNum = snum;
	name = sname;
	mark = smark;
}

int Student::studentNum_getter()
{
	return studentNum;
}

string Student::name_getter()
{
	return name;
}

float Student::mark_getter()
{
	return mark;
}

int Hash::hashFunction(int key)
{
	int hash = key;
	int index = hash % tableSize;

	return index;
}

int Hash::addStudent(Hash &obj)
{
	int num;
	int probeCount = 1;
	float mark;
	string name;
	
	cout << "Ok. Please enter the name of the student (First, Last)." << endl;
	cout << "->";
	cin.ignore();
	getline(cin, name);
	cout << endl;
	cout << "Great now please enter their student number" << endl;
	cout << "->";
	cin >> num;
	cout << endl;
	cout << "Finally please enter their current mark." << endl;
	cin >> mark;
	cout << endl;
	cout << "Processing..." << endl;

	int index = hashFunction(num);

	if (hashTable[index]->studentNum_getter() == 000000)
	{
		hashTable[index]->setInfo(num, mark, name);
	}
	else
	{
		//linear probing
		while (hashTable[index]->studentNum_getter() != 000000)
		{
			cout << "Probing... " << probeCount << endl;
			index++;
			probeCount++;
		}
		
		if (hashTable[index]->studentNum_getter() == 000000)
		{
			hashTable[index]->setInfo(num, mark, name);
		}
		else
		{
			cout << "Sorry but the table is full!" << endl << endl;
		}
	}

	return 0;
}

void Hash::printTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		cout << "---[Student Index " << i << "]---" << endl;
		cout << "Name: " << hashTable[i]->name_getter() <<endl;
		cout << "Student Number: " << hashTable[i]->studentNum_getter() << endl;
		cout << "Current Mark: " << hashTable[i]->mark_getter() << endl;
		cout << "------------------------" << endl << endl;
	}
}

int Hash::searchStudent()
{
	int choice = 0;
	int num;
	int index = 0;
	string name;

	cout << "How would you like to search for a student?" << endl;
	cout << "1 = By student number and hash function." << endl;
	cout << "2 = By name." << endl;
	cout << "->";
	cin >> choice;
	cout << endl << endl;

	if (choice == 1)
	{
		cout << "Please enter the student number of the student you're trying to find: " << endl;
		cin >> num;
		cout << endl << endl;

		index = hashFunction(num);

		if (hashTable[index]->studentNum_getter() == num)
		{
			cout << "---[Student Index " << index << "]---" << endl;
			cout << "Name: " << hashTable[index]->name_getter() << endl;
			cout << "Student Number: " << hashTable[index]->studentNum_getter() << endl;
			cout << "Current Mark: " << hashTable[index]->mark_getter() << endl;
			cout << "------------------------" << endl << endl;

			return hashTable[index]->studentNum_getter();
		}
		
		else
		{
			cout << "Sorry but that student is not in the table." << endl << endl;
		}
	}
	
	else if (choice == 2)
	{
		cout << "Ok. Please enter the name of the student (First, Last)." << endl;
		cout << "->";
		cin.ignore();
		getline(cin, name);
		cout << endl << endl;

		while (index < tableSize - 1 && hashTable[index]->name_getter() != name)
		{
			index++;
		}

		if (hashTable[index]->name_getter() == name)
		{
			cout << "---[Student Index " << index << "]---" << endl;
			cout << "Name: " << hashTable[index]->name_getter() << endl;
			cout << "Student Number: " << hashTable[index]->studentNum_getter() << endl;
			cout << "Current Mark: " << hashTable[index]->mark_getter() << endl;
			cout << "------------------------" << endl << endl;

			return hashTable[index]->studentNum_getter();
		}
		
		else
		{

			cout << "Sorry but that name is not in the table." << endl << endl;
		}
	}
	
	else
	{
		cout << "Sorry but that is not a vaild input, please try again." << endl << endl;
	}
}

void Hash::deleteStudent()
{
	int num = searchStudent();
	cout << "Deleting student..." << endl;
	int index = hashFunction(num);

	if (hashTable[index]->studentNum_getter() != num)
	{
		while (hashTable[index]->studentNum_getter() != num && index < tableSize-1)
		{
			index++;
		}
		if (hashTable[index]->studentNum_getter() != 000000)
		{
			hashTable[index]->defaultSetter();

			cout << "Name successfully deleted." << endl;
		}
		else
		{
			cout << "Sorry but that name was not found in the list." << endl << endl;
		}
	}
	else
	{
		hashTable[index]->defaultSetter();

		cout << "Name sucessfully deleted." << endl;
	}
}