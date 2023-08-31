using namespace std;

struct Address
{
	char* country;
	char* regoin;
	char* area;
	char* city;
	char* street;
	char* hause;
	char* flat;
};

struct Student {

	char* lastName;
	char* name;
	int age;
	char* phoneNumber;
	Address address;

};

void AddStudents(Student** &studentsDataBase, int* amountStudents);

void DeleteStudent(Student** &studentsDataBase, int* amountStudents);

void Edit(Student** &studentsDataBase, int amountStudents);

void Print(Student** studentsDataBase, int amountStudents);

void PrintStudentDataBase(Student** studentsDataBase,int amountStudents);

void ExitProgramm(Student** studentsDataBase, int amountStudents);

void Sort(Student** studentsDataBase, int amountStudents);

char* ReadString();

void Search(Student** studentsDataBase, int amountStudents);

void SearchForContactsInTheRange(Student** studentsDataBase, int amountStudents, bool createReport);

bool ChekMask(char stringEnter[], char mask[]);

void SearchMask(Student** studentsDataBase, int amountStudents, bool createReport);

bool SearchString(char* keySearch, char* fieldSearch, int indexStudent);

void OpenDataBaseStudent(Student** &studentsDataBase, int& amountStudents);

void SaveDataToFile(Student** studentsDataBase, int amountStudents, const char* fileName);

void CreateReport(Student** studentsDataBase, int h);