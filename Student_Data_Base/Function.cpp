#include<iostream>
#include"Function.h"
#include<fstream>
#include<io.h>
#include<stdio.h>

using namespace std;

char* ReadString() {

	char onedimArr[100];

	if (cin.peek() == '\n')
	{
		cin.get();
	}
	gets_s(onedimArr);

	char* readString = new char[strlen(onedimArr) + 1];

	for (int i = 0; i < strlen(onedimArr); i++)
	{
		readString[i] = onedimArr[i];
	}
	readString[strlen(onedimArr)] = '\0';

	return readString;

}

void AddStudents(Student** &studentsDataBase, int* amountStudents) {

	int amoutAddStudent = 0;

	cout << "\n\n\tEnter amount student for add to list: ";
	cin >> amoutAddStudent;

	Student** tmp = new Student * [*amountStudents + amoutAddStudent];

	for (int i = 0; i < *amountStudents + amoutAddStudent; i++)
	{
		tmp[i] = new Student;
	}

	for (int i = 0; i < *amountStudents; i++)
	{
		tmp[i] = studentsDataBase[i];

	}
	for (int i = *amountStudents; i < *amountStudents + amoutAddStudent; i++)
	{
		tmp[i] = new Student;
	}

	int countAddStudent = 1;

	for (int i = *amountStudents; i < *amountStudents + amoutAddStudent; i++)
	{
		cout << "\n\tStudent " << countAddStudent << "\n";

		countAddStudent++;

		cout << "\n\tEnter Last name Student\t\t";
		tmp[i]->lastName = ReadString();

		cout << "\n\tEnter Name Student:\t\t";
		tmp[i]->name = ReadString();

		cout << "\n\tEnter phone number Students:\t";
		tmp[i]->phoneNumber = ReadString();
				
		cout << "\n\tEnter Age Student:\t\t";
		cin >> tmp[i]->age;

		cout << "\n\n\tEnter address";

		cout << "\n\n\tCountry:\t";
		tmp[i]->address.country = ReadString();

		cout << "\tRegion:\t\t";
		tmp[i]->address.regoin = ReadString();

		cout << "\tArea:\t\t";
		tmp[i]->address.area = ReadString();

		cout << "\tCity/Village:\t";
		tmp[i]->address.city = ReadString();

		cout << "\tStreet:\t\t";
		tmp[i]->address.street = ReadString();

		cout << "\tHause:\t\t";
		tmp[i]->address.hause = ReadString();

		cout << "\tFlat:\t\t";
		tmp[i]->address.flat = ReadString();
	}

	delete[]studentsDataBase;

	*amountStudents += amoutAddStudent;

	studentsDataBase = tmp;

}

bool SearchString(char* keySearch, char* fieldSearch, int indexStudent) {

	for (int i = 0; i < strlen(fieldSearch) - strlen(keySearch) + 1; i++)
	{
		if (fieldSearch[i] == keySearch[0])
		{
			for (int j = 0; j < strlen(keySearch); j++)
			{
				if (fieldSearch[i + j] != keySearch[j])
				{
					break;
				}
				if (j == strlen(keySearch) - 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void DeleteStudent(Student** &studentsDataBase, int* amountStudents) {

	int indexDeleteStudent = 0;
	int choseMethotDelete;

	cout << "\n\n\tSelect the student search method for removal.";
	cout << "\n\t\t1. By index";
	cout << "\n\t\t2. By last name";
	cout << "\n\t\t3. By phone number";
	cout << "\n\n\tMethod search for removal:  ";

	cin >> choseMethotDelete;

	switch (choseMethotDelete)
	{
	case(1): 
	{	
		cout << "\n\n\tEnter index Student for Delete: ";		
		cin >> indexDeleteStudent;
		indexDeleteStudent--;
	}
		   break;
	case(2):
	{
		char* lastNameStr;
		cout << "\n\n\tEnter last name:  ";
		
		lastNameStr = ReadString();

		for (int h = 0; h < *amountStudents + 1; h++)
		{
			if (SearchString(lastNameStr, studentsDataBase[h][0].lastName, h))
			{
				indexDeleteStudent = h;	
				break;
			}				
		}
	}
		break;
	case(3):
	{
		char* phoneNumberStr;
		cout << "\n\tEnter phone number: ";

		phoneNumberStr = ReadString();

		for (int h = 0; h < *amountStudents + 1; h++)
		{
			if (SearchString(phoneNumberStr, studentsDataBase[h][0].phoneNumber, h))
			{
				indexDeleteStudent = h;		
				break;
			}
		}
	}
		break;
	default:
		cout << "\n\n\tWrong operation!!!";
		return;
		break;
	}

	if (indexDeleteStudent > 0 && indexDeleteStudent <= *amountStudents)
	{
		*amountStudents -= 1;
		Student** tmp = new Student * [*amountStudents];

		for (int r = 0; r < *amountStudents; r++)
		{
			if (r < indexDeleteStudent)
			{
				tmp[r] = studentsDataBase[r];
			}
			else
			{
				tmp[r] = studentsDataBase[r + 1];
			}
		}

		delete[]studentsDataBase[indexDeleteStudent];

		delete[]studentsDataBase;

		studentsDataBase = tmp;
	}
	else
	{
		cout << "\n\n\tError! Wrong index.";
	}
	
}

void Edit(Student** &studentsDataBase, int amountStudents) {

	int indexEditStudent;
	
	cout << "\n\tEnter index Student for Edit:";
	cin >> indexEditStudent;

	cout << "\n\n\tSelect the position you would like to change";

	cout << "\n\n\t 1. All data";
	cout << "\n\t 2. Last name";
	cout << "\n\t 3. Name";
	cout << "\n\t 4. Age";
	cout << "\n\t 5. Phone number";
	cout << "\n\t 6. Country";
	cout << "\n\t 7. Region";
	cout << "\n\t 8. Area";
	cout << "\n\t 9. City/Village";
	cout << "\n\t10. Street";
	cout << "\n\t11. Hause";
	cout << "\n\t12. Flat";
	cout << "\n\n\tOperation: ";

	int choseEditData;
	cin >> choseEditData;

	switch (choseEditData)
	{
		case (1):
		{
			cout << "\n\tEnter last name student: ";
			studentsDataBase[indexEditStudent - 1][0].lastName = ReadString();


			cout << "\n\tEnter name student: ";
			studentsDataBase[indexEditStudent - 1][0].name = ReadString();

			cout << "\n\tEnter phone number Students: ";	
			studentsDataBase[indexEditStudent - 1]->phoneNumber = ReadString();

			cout << "\n\tEnter age Students: ";
			cin >> studentsDataBase[indexEditStudent - 1]->age;

			cout << "\n\n\tAddress";

			cout << "\n\tCountry: ";
			studentsDataBase[indexEditStudent - 1][0].address.country = ReadString();

			cout << "\n\tRegion: ";
			studentsDataBase[indexEditStudent - 1][0].address.regoin = ReadString();

			cout << "\n\tArea: ";
			studentsDataBase[indexEditStudent - 1][0].address.area = ReadString();

			cout << "\n\tCity/Village: ";
			studentsDataBase[indexEditStudent - 1][0].address.city = ReadString();

			cout << "\n\tStreet: ";
			studentsDataBase[indexEditStudent - 1][0].address.street = ReadString();

			cout << "\n\tHause: ";
			studentsDataBase[indexEditStudent - 1][0].address.hause = ReadString();

			cout << "\n\tFlat: ";
			studentsDataBase[indexEditStudent - 1][0].address.flat = ReadString();
		}
			break;
		case(2):
		{
			cout << "\n\tEnter last name student: ";
			studentsDataBase[indexEditStudent - 1][0].lastName = ReadString();
		}	
			break;
		case(3):
		{	
			cout << "\n\tEnter name student: ";
			studentsDataBase[indexEditStudent - 1][0].name = ReadString();
		}
			break;
		case(4):
		{
			cout << "\n\tEnter age student: ";
			cin >> studentsDataBase[indexEditStudent - 1][0].age; 
		}
			break;
		case(5):
		{
			cout << "\n\tEnter phone number student: ";
			studentsDataBase[indexEditStudent - 1][0].phoneNumber = ReadString(); 
		}
			break;
		case(6): 
		{
			cout << "\n\tEnter country student: ";
			studentsDataBase[indexEditStudent - 1][0].address.country = ReadString();
		}
			break;
		case(7): 
		{
			cout << "\n\tEnter region student: ";
			studentsDataBase[indexEditStudent - 1][0].address.regoin = ReadString();
		}
			break;
		case(8): 
		{
			cout << "\n\tEnter area student: ";
			studentsDataBase[indexEditStudent - 1][0].address.area = ReadString();
		}
			break;
		case(9):
		{
			cout << "\n\tEnter city/village student: ";
			studentsDataBase[indexEditStudent - 1][0].address.city = ReadString();
		}
			break;
		case(10):
		{
			cout << "\n\tEnter street student: ";
			studentsDataBase[indexEditStudent - 1][0].address.street = ReadString();
		}
			break;
		case(11): 
		{
			cout << "\n\tEnter hause student: ";
			studentsDataBase[indexEditStudent - 1][0].address.hause = ReadString(); 
		}
			break;
		case(12):
		{
			cout << "\n\tEnter flat student: ";
			studentsDataBase[indexEditStudent - 1][0].address.flat = ReadString();
		}
			break;	
		default: cout << "\n\tWrong chose!";
			break;
	}
	
}

void PrintStudentDataBase(Student** studentsDataBase, int amountStudents) {

	cout << "\n\n\tChoice print metod";
	cout << "\n\n\t\t1. Display students data by index ";
	cout << "\n\t\t2. Display all student data";
	cout << "\n\n\t\tOperation: ";

	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "\n\n\tEntered index student: ";
		int indexStudent;
		cin >> indexStudent;
		indexStudent--;
		Print(studentsDataBase, indexStudent);
		return;
	}
	if (choice == 2)
	{
		for (int i = 0; i < amountStudents; i++)
		{
			Print(studentsDataBase, i);
		}
		return;
	}
	cout << "\n\n\tError! Wrong operation!";
}

void Print(Student** studentsDataBase, int indexStudent) 
{
		cout << "\n\tStudent \t" << indexStudent + 1;
		cout << "\n\n\tLast name: \t" << studentsDataBase[indexStudent][0].lastName;
		cout << "\n\tName: \t\t" << studentsDataBase[indexStudent][0].name;
		cout << "\n\tAge: \t\t" << studentsDataBase[indexStudent][0].age;
		cout << "\n\tPhone number: \t" << studentsDataBase[indexStudent][0].phoneNumber;
		cout << "\n\n\tAdress";
		cout << "\n\tContry: \t" << studentsDataBase[indexStudent][0].address.country;
		cout << "\n\tRegion: \t" << studentsDataBase[indexStudent][0].address.regoin;
		cout << "\n\tArea \t\t" << studentsDataBase[indexStudent][0].address.area;
		cout << "\n\tCity/Village: \t" << studentsDataBase[indexStudent][0].address.city;
		cout << "\n\tStreet: \t" << studentsDataBase[indexStudent][0].address.street;
		cout << "\n\tHause: \t\t" << studentsDataBase[indexStudent][0].address.hause;
		cout << "\n\tFlat: \t\t" << studentsDataBase[indexStudent][0].address.flat;
		cout << "\n\t------------------------------------------";
	
}

void Sort(Student** studentsDataBase, int amountStudents) {

	cout << "\n\n\tChoose a sorting method";
	cout << "\n\t\t1. By last name";
	cout << "\n\t\t2. By age";
	cout << "\n\t\t3. By phone number";

	int choseSort;
	cout << "\n\n\tMethod sorting: ";
	cin >> choseSort;

	switch (choseSort)
	{
	case(1):
	{
		for (int i = 0; i < amountStudents; i++)
		{
			for (int j = i + 1; j < amountStudents; j++) 
			{

				if (strcmp(studentsDataBase[i][0].lastName, studentsDataBase[j][0].lastName) > 0)
				{
					Student* tmp = studentsDataBase[i];
					studentsDataBase[i] = studentsDataBase[j];
					studentsDataBase[j] = tmp;
				}
			}
		}
	}
	break;
	case(2):
	{
		for (int i = 0; i < amountStudents; i++)
		{
			for (int j = i + 1; j < amountStudents; j++)
			{

				if (studentsDataBase[i][0].age > studentsDataBase[j][0].age)
				{
					Student* tmp = studentsDataBase[i];
					studentsDataBase[i] = studentsDataBase[j];
					studentsDataBase[j] = tmp;
				}
			}
		}
	}
	break;
	case(3):
	{
		for (int i = 0; i < amountStudents; i++)
		{
			for (int j = i + 1; j < amountStudents; j++)
			{

				if (strcmp(studentsDataBase[i][0].phoneNumber, studentsDataBase[j][0].phoneNumber) > 0)
				{
					Student* tmp = studentsDataBase[i];
					studentsDataBase[i] = studentsDataBase[j];
					studentsDataBase[j] = tmp;
				}
			}
		}
	}
	break;

	default:cout << "\n\tWrong chose!";
		break;
	}	
}

void ExitProgramm(Student** studentsDataBase, int amountStudents) {

	for (int i = 0; i < amountStudents; i++)
	{
		delete[] studentsDataBase[i];
	}
	delete[]studentsDataBase;
	exit(0);
}

void SearchForContactsInTheRange(Student** studentsDataBase, int amountStudents, bool createReport) {

	char* startKeySearch;
	char* endKeySearch;
	int startIndex = -1;
	int endIndex = -1;

	cout << "\n\n\tEnter start key for search: ";
	startKeySearch = ReadString();

	cout << "\n\n\tEnter end key for search: ";
	endKeySearch = ReadString();

		
	for (int h = 0; h < amountStudents; h++)
	{
		if (startIndex != -1 )
		{
			break;
		}
		if (SearchString(startKeySearch, studentsDataBase[h][0].lastName, h))
		{
			startIndex = h;				
		}
	}

	for (int h = 0; h < amountStudents; h++)
	{
		if (endIndex != -1)
		{
			break;
		}
		if (SearchString(endKeySearch, studentsDataBase[h][0].lastName, h))
		{
			endIndex = h;
		}
	}
	for (int i = startIndex; i <= endIndex; i++)
	{
		Print(studentsDataBase,i);
		if (createReport)
		{
			CreateReport(studentsDataBase, i);
		}

	}
}

bool ChekMask(char stringEnter[], char mask[]) {

	int counterSymbQue = 0;
	int counterSymbol = 0;

	for (int i = 0; i < strlen(mask); i++)
	{
		if (mask[i] == '?')
		{
			counterSymbQue++;

			if (counterSymbQue == strlen(mask) && counterSymbQue != strlen(stringEnter))
			{
				return false;
			}
		}
		if (mask[i] != '*')
		{
			counterSymbol++;
		}
	}

	if (counterSymbol > strlen(stringEnter))
	{
		return false;
	}

	int indexStartMask = 0;
	int indexStartEnterStr = 0;
	int indexEndMask = strlen(mask) - 1;
	int indexEndEnterStr = strlen(stringEnter);

	if (mask[0] != '*')
	{
		for (int i = 0; i < strlen(mask); i++)
		{
			if (mask[i] == '?')
			{
				continue;
			}
			if (mask[i] == '*')
			{
				break;
			}
			if (mask[i] != stringEnter[i])
			{
				return false;
			}

			indexStartMask = i + 1;
			indexStartEnterStr = i + 1;
		}
	}

	if (mask[strlen(mask) - 1] != '*')
	{
		for (int j = 0; j < strlen(mask); j++)
		{
			if (mask[strlen(mask) - 1 - j] == '?')
			{
				continue;
			}
			if (mask[strlen(mask) - 1 - j] == '*')
			{
				break;
			}
			if (mask[strlen(mask) - 1 - j] != stringEnter[strlen(stringEnter) - 1 - j])
			{
				return false;
			}
			indexEndMask = strlen(mask) - 1 - j - 1;
			indexEndEnterStr = strlen(stringEnter) - 1 - j;
		}
	}
	char keySearch[20];
	int counterMask = 0;
	for (int k = indexStartMask; k <= indexEndMask; k++)
	{
		if (mask[k] != '*')
		{
			keySearch[counterMask] = mask[k];
			counterMask++;
		}
		if (mask[k] == '*' && mask[k - 1] != '*' && counterMask != 0)
		{
			keySearch[counterMask] = '\0';
			counterMask = 0;

			for (int x = indexStartEnterStr; x < indexEndEnterStr - strlen(keySearch) + 1; x++)
			{
				if (stringEnter[x] == keySearch[0] || keySearch[0] == '?')
				{
					for (int q = 0; q < strlen(keySearch); q++)
					{
						if (q == strlen(keySearch) - 1)
						{
							indexStartEnterStr = x + q + 1;
							x = indexEndEnterStr - strlen(keySearch) + 1;
							break;
						}
						if (keySearch[q] == '?')
						{
							continue;
						}

						if (stringEnter[x + q] != keySearch[q])
						{
							break;
						}
					}
				}
				if (x == indexEndEnterStr - strlen(keySearch))
				{
					return false;
				}
			}
		}
	}
	return true;
}

void SearchMask(Student** studentsDataBase, int amountStudents, bool createReport) {

	char mask[20];
	cout << "\n\tEnter the mask using the characters '*' and '?': ";
	if (cin.peek() == '\n')
	{
		cin.get();
	}
	gets_s(mask);

	for (int i = 0; i < amountStudents; i++)
	{
		if (ChekMask(studentsDataBase[i][0].lastName, mask))
		{
			Print(studentsDataBase, i);
			if (createReport)
			{
				CreateReport(studentsDataBase, i);
			}
		}
	}

}

void Search(Student** studentsDataBase, int amountStudents){

	cout << "\n\n\tSelect a search method";
	cout << "\n\n\t\t 1. Last name";
	cout << "\n\t\t 2. Name";
	cout << "\n\t\t 3. Age";
	cout << "\n\t\t 4. Phone number";
	cout << "\n\t\t 5. Country";
	cout << "\n\t\t 6. Region";
	cout << "\n\t\t 7. Area";
	cout << "\n\t\t 8. City/Village";
	cout << "\n\t\t 9. Given range";
	cout << "\n\t\t10. Mask";
	
	cout << "\n\n\tSeanch method: ";
	int searchMethod;
	cin >> searchMethod;

	cout << "\n\n\tDo you want to create a report on search results? Yes(y) / No(n):  ";
	
	char charReport;
	bool createReport = false;
	
	cin >> charReport;

	if (charReport=='y')
	{
		createReport = true;
	}

	

	
	switch (searchMethod)
	{
	case(1):
	{
		char* keySearch;
		cout << "\n\tInpput key for search last name: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].lastName, h))
			{
				Print(studentsDataBase,h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(2):
	{
		char* keySearch;
		cout << "\n\tInpput key for search name: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].name, h))
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(3):
	{
		int keySearch;
		cout << "\n\tInpput key for search age: ";
		cin >> keySearch;

		for (int h = 0; h < amountStudents; h++)
		{
			if (keySearch == studentsDataBase[h][0].age)
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(4):
	{
		char* keySearch;
		cout << "\n\tInpput key for search phone number: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].phoneNumber, h))
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(5):
	{
		char* keySearch;
		cout << "\n\tInpput key for search country: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].address.country, h))
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(6):
	{
		char* keySearch;
		cout << "\n\tInpput key for search region: ";
		keySearch = ReadString();
		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].address.regoin, h))
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(7):
	{
		char* keySearch;
		cout << "\n\tInpput key for search area: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].address.area, h))
			{
				Print(studentsDataBase, h);

				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(8):
	{
		char* keySearch;
		cout << "\n\tInpput key for search city: ";
		keySearch = ReadString();

		for (int h = 0; h < amountStudents; h++)
		{
			if (SearchString(keySearch, studentsDataBase[h][0].address.city, h))
			{
				Print(studentsDataBase, h);
				if (createReport)
				{
					CreateReport(studentsDataBase, h);
				}
			}
		}
	}
	break;
	case(9):
	{
		SearchForContactsInTheRange(studentsDataBase, amountStudents, createReport);
	}
	break;
	case(10):
	{
		SearchMask(studentsDataBase, amountStudents, createReport);
	}
	break;
	default:cout << "\n\n\tWrong operation!!!";
		break;
	}

}

void OpenDataBaseStudent(Student** &studentsDataBase, int &amountStudents) {
	
	FILE* file;

	const char* fileName = "StudentDataBase.txt";

	if (!fopen_s(&file, fileName, "rb"))
	{
		fread(&amountStudents,sizeof(int), 1, file);

		cout << "\n\n\tThe database contains data on " << amountStudents << " students.\n";

		Student** tmp = new Student* [amountStudents];

		for (int i = 0; i < amountStudents; i++)
		{
			tmp[i] = new Student;
		}

		for (int i = 0; i < amountStudents; i++)
		{

			int sizeString;

			fread(&sizeString, sizeof(int), 1, file);
			char* bufferLastName = new char[sizeString];
			fread(bufferLastName, sizeString, 1, file);
			tmp[i]->lastName = bufferLastName;

			fread(&sizeString, sizeof(int), 1, file);
			char* bufferName = new char[sizeString];
			fread(bufferName, sizeString, 1, file);
			tmp[i]->name = bufferName;

			
			int bufferAge;
			fread(&bufferAge, sizeof(int), 1, file);
			tmp[i]->age = bufferAge;

			fread(&sizeString, sizeof(int), 1, file);
			char* bufferPhoneNumber = new char[sizeString];
			fread(bufferPhoneNumber, sizeString, 1, file);
			tmp[i]->phoneNumber = bufferPhoneNumber;

			fread(&sizeString, sizeof(int), 1, file);
			char* bufferCountry = new char[sizeString];
			fread(bufferCountry, sizeString, 1, file);
			tmp[i]->address.country = bufferCountry;
			
			fread(&sizeString, sizeof(int), 1, file);
			char* bufferRegion = new char[sizeString];
			fread(bufferRegion, sizeString, 1, file);
			tmp[i]->address.regoin = bufferRegion;
			
			fread(&sizeString, sizeof(int), 1, file);
			char* bufferArea = new char[sizeString];
			fread(bufferArea, sizeString, 1, file);
			tmp[i]->address.area = bufferArea;
			
			fread(&sizeString, sizeof(int), 1, file);
			char* bufferCity = new char[sizeString];
			fread(bufferCity, sizeString, 1, file);
			tmp[i]->address.city = bufferCity;
			
			fread(&sizeString, sizeof(int), 1, file);
			char* bufferStreet = new char[sizeString];
			fread(bufferStreet, sizeString, 1, file);
			tmp[i]->address.street = bufferStreet;
						
			fread(&sizeString, sizeof(int), 1, file);
			char* bufferHause = new char[sizeString];
			fread(bufferHause, sizeString, 1, file);
			tmp[i]->address.hause = bufferHause;

			fread(&sizeString, sizeof(int), 1, file);
			char* bufferFlat = new char[sizeString];
			fread(bufferFlat, sizeString, 1, file);
			tmp[i]->address.flat = bufferFlat;
			
		}		
		studentsDataBase = tmp;
	}
	else
	{
		cout << "\n\n\tError open file!";
		
	}
	fclose(file);
	
}

void SaveDataToFile(Student** studentsDataBase, int amountStudents, const char* fileName) {

	FILE* file;

	//const char* fileName = "StudentDataBase.txt";

	if(!fopen_s(&file, fileName, "wb"))
	{
		fwrite(&amountStudents, sizeof(int), 1, file);

		for (int i = 0; i < amountStudents; i++)
		{
			int sizeString;
			
			sizeString = strlen(studentsDataBase[i]->lastName) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->lastName, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->name) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->name, sizeString, 1, file);

			fwrite(&(studentsDataBase[i]->age), sizeof(int), 1, file);

			sizeString = strlen(studentsDataBase[i]->phoneNumber) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->phoneNumber, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.country) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.country, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.regoin) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.regoin, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.area) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.area, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.city) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.city, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.street) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.street, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.hause) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.hause, sizeString, 1, file);

			sizeString = strlen(studentsDataBase[i]->address.flat) + 1;
			fwrite(&sizeString, sizeof(int), 1, file);
			fwrite(studentsDataBase[i]->address.flat, sizeString, 1, file);
		}
	}
	else
	{
		cout << "\n\n\tError open file";
	}
	fclose(file);
}

void CreateReport(Student** studentsDataBase, int i) {

	FILE* file;

	const char* fileName = "ReportSearch.txt";

	if (!fopen_s(&file, fileName, "a"))
	{

			int sizeString;
			

			const char* lastNR = "Last name:\t";
			fputs(lastNR, file);
			sizeString = strlen(studentsDataBase[i]->lastName) + 1;
			
			fwrite(studentsDataBase[i]->lastName, sizeString, 1, file);


			const char* nameR = "\nName:\t\t";
			fputs(nameR, file);
			sizeString = strlen(studentsDataBase[i]->name) + 1;			
			fwrite(studentsDataBase[i]->name, sizeString, 1, file);

			const char* phoneNumberR = "\nPhone number:\t";
			fputs(phoneNumberR, file);
			sizeString = strlen(studentsDataBase[i]->phoneNumber) + 1;			
			fwrite(studentsDataBase[i]->phoneNumber, sizeString, 1, file);


			const char* ageR = "\nAge:\t\t";
			fputs(ageR, file);

			int a = studentsDataBase[i]->age;
			char intToChar[3];
			if (a < 10 && a>0)
			{
				intToChar[0] = (char)(a + 48);
				intToChar[1] = '\0';
			}
			if (a > 9 && a < 100) {

				int digit10 = a / 10;
				int digit1 = a % 10;
				intToChar[0] = (char)(digit10 + 48);
				intToChar[1] = (char)(digit1 + 48);
				intToChar[2] = '\0';
			}
			sizeString = strlen(intToChar) + 1;
			fwrite(intToChar, sizeString, 1, file);


			const char* countryR = "\nCountry:\t";
			fputs(countryR, file);
			sizeString = strlen(studentsDataBase[i]->address.country) + 1;			
			fwrite(studentsDataBase[i]->address.country, sizeString, 1, file);


			const char* regionR = "\nRegion:\t\t";
			fputs(regionR, file);
			sizeString = strlen(studentsDataBase[i]->address.regoin) + 1;			
			fwrite(studentsDataBase[i]->address.regoin, sizeString, 1, file);


			const char* areaR = "\nArea:\t\t";
			fputs(areaR, file);
			sizeString = strlen(studentsDataBase[i]->address.area) + 1;			
			fwrite(studentsDataBase[i]->address.area, sizeString, 1, file);


			const char* cityR = "\nCity:\t\t";
			fputs(cityR, file);
			sizeString = strlen(studentsDataBase[i]->address.city) + 1;			
			fwrite(studentsDataBase[i]->address.city, sizeString, 1, file);


			const char* streetR = "\nStreet:\t\t";
			fputs(streetR, file);
			sizeString = strlen(studentsDataBase[i]->address.street) + 1;			
			fwrite(studentsDataBase[i]->address.street, sizeString, 1, file);



			const char* hauseR = "\nHause:\t\t";
			fputs(hauseR, file);
			sizeString = strlen(studentsDataBase[i]->address.hause) + 1;			
			fwrite(studentsDataBase[i]->address.hause, sizeString, 1, file);


			const char* flatR = "\nFlat:\t\t";
			fputs(flatR, file);
			sizeString = strlen(studentsDataBase[i]->address.flat) + 1;
			fwrite(studentsDataBase[i]->address.flat, sizeString, 1, file);
			const char* lineR = "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
			fputs(lineR, file);
	}
	else
	{
		cout << "\n\n\tError open file";
	}
	fclose(file);


}