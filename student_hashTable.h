#ifndef HASH_T
#define HASH_T

#include<cstdlib>
#include<iostream>

using namespace std;

class Student
{
private:
	int studentNum;
	string name;
	float mark;
public:
	void defaultSetter();
	void setInfo(int, float, string);
	int studentNum_getter();
	string name_getter();
	float mark_getter();
};

class Hash
{
public:
	static const int tableSize = 25;
	int hashFunction(int key);
	Student* hashTable[tableSize];

	Hash()
	{
		for (int i = 0; i < tableSize; i++)
		{
			hashTable[i] = new Student;
			hashTable[i]->defaultSetter();
		}
	}
	~Hash()
	{}

	int addStudent(Hash &obj);
	void printTable();
	int searchStudent();
	void deleteStudent();

};

#endif
