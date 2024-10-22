#include<iostream>
#include<string>
#include<vector>
using namespace std;

// creating class 

class Student {
private:
	int rollno, age;
	string name;

public:
	Student(int stdrollno, int stdage, string stdname)
	{
		rollno = stdrollno;
		age = stdage;
		name = stdname;
	}

	// setter and getter for rollno
	void setRollno( int stdrollno)
	{
		rollno = stdrollno;
	}
	int getRollno()
	{
		return rollno;
	}
	
	// setter and getter for age
	void setAge(int stdage)
	{
		age = stdage;
	}
	int getAge()
	{
		return age;
	}

	// setter and getter for name
	void setName(string stdname)
	{
		name = stdname;
	}
	string getName()
	{
		return name;
	}

	void displaystudent()
	{
		cout << "Roll No is : " << rollno << endl;
		cout << "Age is : " << age << endl;
		cout << "Name is : " << name << endl;
	}
	
};


// create a function to add new students

void addNewStudents(vector<Student> &students)
{
	int rollno, age;
	string name;
	cout << "\n\n\t\tEnter Roll No : ";
	cin >> rollno;

	// check if student already exits

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getRollno() == rollno)
		{
			cout << "Student Already Exits.......\n";
			return;
		}
	}
	cout << "\t\tEnter Age :  ";
	cin >> age;
	cout << "\t\tEnter name : ";
	cin >> name;

	Student newStudent(rollno, age, name);
	students.push_back(newStudent);

	cout << "\t\t\nStudent Add sucessfully.........\n";
	system("cls");
}

//display student function

void DisplayAllStudents(vector<Student>& students)
{
	if (students.empty())
	{
		cout << "\n\n\t\tNo Student found...." << endl;
		return;
	}
	for (int i = 0; i < students.size(); i++)
	{
		students[i].displaystudent();
		cout << endl;
	}
	
}

// search students function


void searchstudent(vector<Student>& students)
{
	int rollno;
	cout << "\n\n\t\t\tEnter Roll No : ";
	cin >> rollno;

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getRollno() == rollno)
		{
			cout << "\n\n\t\t\t........Student Found.......\n\n\n";
			students[i].displaystudent();
			return;
		}
	}
}


// Update students function

void Updatestudent(vector<Student>& students)
{
	string sname;
	bool found = false;

	int choice;


	cout << "\n\n\t\t\tEnter the name of the student which you update  : ";
	cin.ignore();
	getline(cin, sname);

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getName() == sname)
		{
			found = true;
			cout << "\n\t\t\t......Student Found....\n\n";
			cout << "\t\t\t1.Update Roll No\n";
			cout << "\t\t\t2.Update Name\n";
			cout << "\t\t\t3.Update Age\n";
			cout << "\t\t\tEnter your choice : ";
			cin >> choice;


			switch (choice)
			{
			case 1:
			{
				int rno;
				cout << "\n\t\t\tEnter the New Roll No : ";
				cin >> rno;
				students[i].setRollno(rno);
				break;
			}

			case 2:
			{
				string name;
				cout << "\n\t\t\tEnter the New Name : ";
				cin.ignore();
				getline(cin, name);
				students[i].setName(name);
				break;
			}

			case 3:
			{
				int age;
				cout << "\n\t\t\tEnter the New Age : ";
				cin >> age;
				students[i].setAge(age);
				break;
			}
			default :
				cout << "\n\t\t\t......Invalid Number .......\n";
			}
		}
		if (!found)
		{
			cout << "Record Not found......\n";
			return;
		}
	}
}


// delete students function

void deletestudents(vector<Student>& students)
{
	string name;
	cout << "\n\t\t\tEnter name to delete..:";
	cin.ignore();
	getline(cin, name);


	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getName() == name)
		{
			students.erase((students.begin() + i));
			cout << "\n\t\t\t........Student remove Sucessfully.....\n";
		}
	}
}

int main()
{
	vector<Student> students;
	students.push_back(Student(1, 057, "Hamza"));

	char choice;
	do {
		int op;
		cout << "\n\n\t\t\t\t....Welcome to Update World....\n";
		cout << "\n\n\t\t1.Add new student \n";
		cout << "\t\t2.Display all student \n";
		cout << "\t\t3.Search student \n";
		cout << "\t\t4.Update student \n";
		cout << "\t\t5.Delete student \n";
		cout << "\t\t6.Exit \n";
		cout << "\n\tEnter your choice : ";
		cin >> op;

		switch (op) {
		case 1:
			addNewStudents(students);
			break;
		case 2:
			DisplayAllStudents(students);
			break;
		case 3:
			searchstudent(students);
			break;
		case 4:
			Updatestudent(students);
			break;
		case 5:
			deletestudents(students);
			break;
		case 6:
			exit(1);
		default :
			cout << "Invalid Number ........" << endl;

		}

		cout << "\n\n\n\t\t\t\t Do you want to continue....[Yes/No]....";
		cin >> choice;
		system("cls");
	} while (choice == 'Y' || choice == 'y');
	

	return 0;
}