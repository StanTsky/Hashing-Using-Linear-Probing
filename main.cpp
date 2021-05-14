// Hashing example; using linear probing
// Stan Turovsky

// Preprocessor directives
#include "Student.h"
#include<iostream>

using namespace std;

void display(Student student)
{
	cout << "Student " << student.getID();
	cout << ": " << student.getFirstName() << " ";
	cout << student.getLastName() << endl;
}

int hashData(string data, int size)
{
	int total = 0;
	for (unsigned int i = 0; i < data.length(); i++)
	{
		total += data[i];
	}

	return total % size;
}

// main function
int main()
{
	const int SIZE = 9; // increase to reduce collisions
	Student *hashTable[SIZE];

	//Test data
	const int TEST_SIZE = 8;
	Student *testData[] =
	{
		new Student("ajef9832743", "Michael", "Henson"),
		new Student("befiu932832", "Nikola", "Tesla"),
		new Student("diebr937216", "Marie", "Curie"),
		new Student("heiuy338276", "Alan", "Turing"),
		new Student("sndhw938572", "Albert", "Einstein"),
		new Student("eksfb383843", "Isaac", "Newton"),
		new Student("efabs810454", "Ada", "Lovelace"),
		new Student("zpleg392041", "Charles", "Babbage")
	};

	// Initialzie hash table
	for (int i = 0; i < SIZE; i++)
		hashTable[i] = nullptr;

	// Feed test data into hash table
	for (int i = 0; i < TEST_SIZE; i++)
	{
		int hashCode = hashData(testData[i]->getID(), SIZE);
		cout << testData[i]->getFirstName() << " hashed to " << hashCode << endl;
		
		// Linear collsion resolution
		while (hashTable[hashCode] != nullptr)
			hashCode = (hashCode + 1) % SIZE;	// linear probing
		hashTable[hashCode] = testData[i];
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << i << ". ";
		if (hashTable[i] != nullptr)
			display(*hashTable[i]);
		else
			cout << endl;
	}

	// Retrieve data
	string key;
	cout << "Enter student ID to retrieve: ";
	cin >> key;

	int location = hashData(key, SIZE);
	while (hashTable[location] != nullptr &&
		hashTable[location]->getID() != key)
	{
		location = (location + 1) % SIZE;
	}

	if (hashTable[location] != nullptr)
	{
		cout << "Student Found" << endl;
		display(*hashTable[location]);
	}
	else
		cout << "Student " << key << " not found." << endl;

	//Student testStudent("TestID", "Testy", "Student");
	//display(testStudent);
	//int hashCode = hashData(testStudent.getID(), SIZE);
	//cout << "Hash code: " << hashCode << endl;

	// Leave this stuff at the end.
	cout << endl;
	system("pause");
	return 0;
}