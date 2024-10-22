#include <iostream>
#include <fstream> // For file handling
#include <sstream> // For string manipulation
#include <map>
#include <vector>

using namespace std;

// Forward declaration of Teacher class
class Teacher;

// Function Declariation

void MainMenu();
void Section_Wise_TimeTable();
void Student_Wise_TimeTable();
void Rooms_Wise_TimeTable();


// Teacher class
class Teacher {
private:
    string id;
    string name;
    string department;

public:
    // Default constructor is needed when we creat an object of a class  withoutt specifying a value to it
    Teacher() {}

    // Constructor with parameters
    Teacher(string id, string name, string department) : id(id), name(name), department(department) {}

    // Getter for Teacher ID
    string getId() const { return id; }

    // Getter for Teacher Name
    string getName() const { return name; }

    // Getter for department
    string getDepartment() const { return department; }

    // Friend function to access private members
    friend void Teacher_Wise_TimeTable();
};

int main() {

    // Creating teacher files for each section
    Teacher_File();
    MainMenu();



    return 0;
}

void MainMenu() {
    char choice;
    bool isValidChoice = false;

    do {
        cout << "\n\t\t\t*Time Table for Software Engineering Department*" << endl;
        cout << "               ----------------------------------------------------------------------\n";
        cout << "\n\t\t\tMain Menu:" << endl;
        cout << "\n\t\t1. Teacher wise time table" << endl;
        cout << "\t\t2. Section wise time table" << endl;
        cout << "\t\t3. Student wise time table" << endl;
        cout << "\t\t4. Room wise and Lab wise" << endl;
        cout << "\t\t5. Search by day" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        // Check if the entered choice is a single digit
        if (cin.fail() || choice < '1' || choice > '6') {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "\n\nInvalid choice. Please enter a single-digit number from 1 to 6." << endl;
            continue;
        }

        switch (choice) {
        case '1':
            Teacher_Wise_TimeTable();
            break;
        case '2':
            Section_Wise_TimeTable();
            break;
        case '3':
            Student_Wise_TimeTable();
            break;
        case '4':
            Rooms_Wise_TimeTable();
            break;
        case '5':
            searchByDay();
            break;
        case '6':
            cout << "Exiting..." << endl;
            break;
        }
    } while (choice != '6');
}

// Function to display section-wise timetable
void Section_Wise_TimeTable() {
    // Define a list of valid sections in your program
    vector<string> validSections = { "BSE-A", "BSE-B", "BSE-C", "BSE-D", "BSE-E" };

    string section;
    bool validSection = false;

    while (!validSection) {
        cout << "\n\n\t\t\tEnter the section (e.g., BSE-A....BSE-E): ";
        cin >> section;

        // Cheking the input
        for (const string& validSec : validSections) {
            if (section == validSec) {
                validSection = true;
                break;
            }
        }

        // if the entered section is not vaild re ask
        if (!validSection) {
            cout << "This section is not available " << section << endl;
            cout << "Please enter a valid section (e.g., BSE-A.....BSE-E)." << endl;
            MainMenu();

        }
    }

    // Generate and save the timetable for the specified section
    Saving_TimeTables_IntoFiles(section);

    // Display the timetable for the specific section
    ifstream timetableFile(section + "_timetable.txt");
    if (!timetableFile.is_open()) {
        cout << "Unable to open timetable file for section " << section << endl;
        return;
    }

    string line;
    cout << "Timetable for section " << section << ":\n";
    while (getline(timetableFile, line)) {
        cout << line << endl;
    }
    timetableFile.close();
}

// Function to display student-wise timetable
void Student_Wise_TimeTable() {
    string section;
    bool validSection = false;

    while (!validSection) {
        cout << "\n\n\t\t\tEnter your section (e.g., BSE-A.....BSE-E): ";
        cin >> section;

        // Check if the entered section is one of the valid sections in your program
        vector<string> validSections = { "BSE-A", "BSE-B", "BSE-C", "BSE-D", "BSE-E" };
        for (const string& validSec : validSections) {
            if (section == validSec) {
                validSection = true;
                break;
            }
        }

        // If the entered section is not valid, ask the user to enter a valid section
        if (!validSection) {
            cout << "\nThats not available Section: " << section << endl;
            cout << "Please enter a valid section (e.g., BSE-A.....BSE-E)." << endl;
            MainMenu();
        }
    }

    // Generate and save the timetable for the specific section
    Saving_TimeTables_IntoFiles(section);

    // Display the timetable for the specified section
    ifstream timetableFile(section + "_timetable.txt");
    if (!timetableFile.is_open()) {
        cout << "Unable to open timetable file for section " << section << endl;
        return;
    }

    string line;
    cout << "Timetable for section " << section << ":\n";
    while (getline(timetableFile, line)) {
        cout << line << endl;
    }
    timetableFile.close();
}

//dunction to search room
void Rooms_Wise_TimeTable() {

    string roomNo;
    cout << "\n\n\t\t\tEnter the room number you want to check: ";
    cin >> roomNo;

    // list of valid room number
    vector<string> validRoomNumbers = { "4-01", "4-02", "4-17", "4-18", "4-19" };

    // Check if the entered room number is valid
    bool isValid = false;
    for (const string& validRoom : validRoomNumbers) {
        if (roomNo == validRoom) {
            isValid = true;
            break;
        }
    }

    // If the entered room number is not valid, ask the user to correct and return
    if (!isValid) {
        cout << "\nRoom " << roomNo << " is not available in our Rooms.\n";
        cout << "Please enter one of the following room numbers : 4 - 01, 4 - 02, 4 - 17, 4 - 18, or 4 - 19." << endl;
        return;
    }

    // Load all sections and print timetable for the specified room number
    vector<string> sections = { "BSE-A", "BSE-B", "BSE-C", "BSE-D", "BSE-E" };
    bool roomFound = false;
    for (const string& section : sections) {
        ifstream timetableFile(section + "_timetable.txt");
        if (!timetableFile.is_open()) {
            cout << "Unable to open timetable file for section " << section << endl;
            continue;
        }

        string line;
        cout << "Timetable for Room/Lab " << roomNo << " in section " << section << ":\n";
        bool found = false;
        while (getline(timetableFile, line)) {
            if (line.find("Room " + roomNo) != string::npos) {
                cout << line << endl;
                found = true;
                roomFound = true;
            }
        }
        if (!found) {
            cout << "No classes scheduled in Room/Lab " << roomNo << " for section " << section << endl;
        }
        timetableFile.close();
    }
    // If room is not found in any section, display error message
    if (!roomFound) {
        cout << "\nRoom/Lab " << roomNo << " is not available.\n\n" << endl;
    }

}
