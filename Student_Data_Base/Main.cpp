#include <iostream>
#include"Function.h"

int main()
{

	int amountStudents = 0;
	Student** studentsDataBase = nullptr;
	char choiseLoadDataBase;
	
	cout << "\n\n\tWant to load a database from a file? Yes(y) / No(n):  ";
	
	cin >> choiseLoadDataBase;
	
	if (choiseLoadDataBase=='y')
	{
		const char* fileName = "StudentDataBase.txt";
		OpenDataBaseStudent(studentsDataBase, amountStudents);
	}
	cout << "\n\n\tDatabase was loaded successfully.\n\n\t";
	system("pause");
	system("cls");
	bool a = true;
	while (a) {

		cout << "\n\n\tSelect the operation you want to perform: ";
		cout << "\n\n\t\t1. Add.";
		cout << "\n\t\t2. Delete.";
		cout << "\n\t\t3. Edit.";
		cout << "\n\t\t4. Print.";
		cout << "\n\t\t5. Sort.";
		cout << "\n\t\t6. Search.";
		cout << "\n\t\t7. Save.";
		cout << "\n\t\t8. Exit.";
		cout << "\n\n\t\tOperation: ";

		int chose;
		cin >> chose;

		switch (chose)
		{
		case (1):	AddStudents(studentsDataBase, &amountStudents);
			break;
		case (2):	DeleteStudent(studentsDataBase, &amountStudents);
			break;
		case (3):	Edit(studentsDataBase, amountStudents);
			break;
		case (4):	PrintStudentDataBase(studentsDataBase, amountStudents);
			break;
		case (5):	Sort(studentsDataBase, amountStudents);
			break;
		case (6):	Search(studentsDataBase, amountStudents);
			break;
		case (7): 
		{
			const char* fileName = "StudentDataBase.txt";
			SaveDataToFile(studentsDataBase, amountStudents, fileName); 
		}
			break;
		case (8):	ExitProgramm(studentsDataBase, amountStudents);
			break;
		default:	cout << "\n\n\tError! Wrong operation.\n\n";
			a = false;
			break;
		}
	}
	delete[]studentsDataBase;
	return 0;
}