#include <iostream>
#include <fstream> // For file handling
#include <sstream> // For string manipulation
#include <map>
#include <vector>

using namespace std;

// Function Declariation
void Teacher_Wise_TimeTable();
void Teacher_File();
void Loading_Teachers_File(const string& section);
void Saving_TimeTables_IntoFiles(const string& section);
void searchByDay();

int main() {

    // Creating teacher files for each section
    Teacher_File();
    MainMenu();  


    return 0;
}

// Function to create files for teachers of each section
void Teacher_File() {
    //declaration of courses and teachers 
    map<string, vector<vector<string>>> sectionData = {
        {"BSE-A", {{"Engr.Sadaf", "(DS)", "4-17"}, {"Dr.Tamim", "(OOP)", "4-18"}, {"Engr.Waleed", "(OOP-Lab)", "4-01"}, {"Dr.Awais", "(ISE)", "4-19"}, {"Mr.Zubair", "(LA)", "4-20"}}},
        {"BSE-B", {{"Engr.Mubashir", "(ENG)", "4-17"}, {"Dr.Ahmad", "(AP)", "4-18"}, {"Engr.Amir", "(CF-Lab)", "4-01"}, {"Engr.Bilal", "(CP-Lab)", "4-02"}, {"Dr.Raja", "(CP)", "4-19"}}},
        {"BSE-C", {{"Dr.Joddat", "(DBMS)", "4-17"}, {"Engr.Iqra", "(AP-Lab)", "4-02"}, {"Dr.Adeel", "(AC)", "4-18"}, {"Dr.Rahimullah", "(IS)", "4-19"}, {"Dr.Ali", "(EFC)", "4-20"}}},
        {"BSE-D", {{"Dr.Lotfullah", "(AI)", "4-17"}, {"Dr.Hamza", "(AI-Lab)", "4-02"}, {"Engr.Qasim", "(DS&A)", "4-18"}, {"Engr.Naveed", "(OHS)", "4-19"}, {"Dr.Muslimwal", "(ML)", "4-20"}}},
        {"BSE-E", {{"Mr.Sara", "(GRA)", "4-17"}, {"Dr.Khan", "(DL)", "4-18"}, {"Engr.Izaz", "(DL-Lab)", "4-01"}, {"Dr.Faisal", "(ICE)", "4-19"}, {"Dr.Ubaid", "(Dri)", "4-20"}}}
    };

    for (const auto& [section, data] : sectionData) {
        ofstream file(section + "_teachers.txt"); // Creating a file for teachers
        if (!file.is_open()) {
            cout << "Unable to create file for section " << section << endl;
            continue;
        }
        // Writing teacher data of IDs, names, subjects, and room numbers
        for (size_t i = 0; i < data.size(); ++i) {
            file << i + 1 << " ";
            for (const string& info : data[i]) {
                file << info << " ";
            }
            file << endl;
        }
        file.close();
    }

}

void Teacher_Wise_TimeTable() {
    string section;
    bool validSection = false;

    while (!validSection) {
        cout << "Enter the section (e.g., BSE-A): ";
        cin >> section;

        if (section.length() == 5 && section[3] == '-' && isalpha(section[4])) {
            validSection = true;
        }
        else {
            cout << "Invalid input. Please enter a valid section." << endl;
        }
    }

    Loading_Teachers_File(section); // Load teachers for the specified section

    string id;
    cout << "Enter the teacher's ID: ";
    cin >> id;

    // Open the file to read teachers data
    ifstream file(section + "_teachers.txt");
    if (!file.is_open()) {
        cout << "Unable to open file for section " << section << endl;
        return;
    }

    string teacherId, teacherName, teacherCourse, teacherDepartment;
    bool found = false;
    // Find teacher's details
    while (file >> teacherId >> teacherName >> teacherCourse >> teacherDepartment) {
        if (teacherId == id) {
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Teacher with ID " << id << " not found." << endl;
        return;
    }

    cout << "Teacher ID: " << teacherId << endl;
    cout << "Name: " << teacherName << endl;
    cout << "Course: " << teacherCourse << endl;

    // Display the timetable for the teacher in each section
    ifstream timetableFile(section + "_timetable.txt");
    if (!timetableFile.is_open()) {
        cout << "Unable to open timetable file for section " << section << endl;
        return;
    }

    string line;
    cout << "Timetable for " << teacherName << ":\n";
    bool teacherFound = false;
    while (getline(timetableFile, line)) {
        if (line.find(teacherName) != string::npos) {
            cout << line << endl;
            teacherFound = true;
        }
    }
    if (!teacherFound) {
        cout << "Timetable not found for teacher " << teacherName << endl;
    }
    timetableFile.close();
}

// Function to load teachers for a specific section

void Loading_Teachers_File(const string& section) {
    ifstream file(section + "_teachers.txt");
    if (!file.is_open()) {
        cout << "Unable to open file for section " << section << endl;
        return;
    }

    map<string, Teacher> teachers;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string teacherId, name, department;
        ss >> teacherId >> name >> department;
        teachers[teacherId] = Teacher(teacherId, name, department);
    }

    file.close();

    // Debugging: print loaded teacher information
    cout << "Loaded teachers for section " << section << ":\n";
    for (const auto& [id, teacher] : teachers) {
        cout << "ID: " << teacher.getId() << ", Name: " << teacher.getName() << ", Department: " << teacher.getDepartment() << endl;
    }
}

// Function to save the timetable for a specific section

void Saving_TimeTables_IntoFiles(const string& section) {
    ofstream timetableFile(section + "_timetable.txt"); // creat a file to save the timetable
    if (!timetableFile.is_open()) {
        cout << "Unable to create timetable file for section " << section << endl;
        return;
    }

    // Define the timetable for each section based on the provided courses and teachers
    map<string, vector<pair<string, pair<string, string>>>> timetableData;

    if (section == "BSE-A") {
        timetableData = {
            {"Friday", {{"09:00-10:30", {"ISE (Dr.Awais)", "4-17"}}, {"11:00-12:30", {"ISE (Dr.Awais)", "4-18"}}, {"14:00-15:30", {"ISE (Dr.Awais)", "4-19"}}}},
            {"Monday", {{"09:00-10:30", {"DS (Engr.Sadaf)", "4-17"}}, {"11:00-12:30", {"OOP (Dr.Tamim)", "4-18"}}, {"14:00-15:30", {"OOP-Lab (Engr.Waleed)", "4-01"}}}},
            {"Tuesday", {{"09:00-10:30", {"DS (Engr.Sadaf)", "4-17"}}, {"11:00-12:30", {"OOP (Dr.Tamim)", "4-18"}}, {"14:00-15:30", {"OOP-Lab (Engr.Waleed)", "4-01"}}}},
            {"Wednesday", {{"09:00-10:30", {"DS (Engr.Sadaf)", "4-17"}}, {"11:00-12:30", {"OOP (Dr.Tamim)", "4-18"}}, {"14:00-15:30", {"OOP-Lab (Engr.Waleed)", "4-01"}}}},
            {"Thursday", {{"09:00-10:30", {"ISE (Dr.Awais)", "4-17"}}, {"11:00-12:30", {"ISE (Dr.Awais)", "4-18"}}, {"14:00-15:30", {"ISE (Dr.Awais)", "4-19"}}}},
        };
    }
    else if (section == "BSE-B") {
        timetableData = {
             {"Monday", {{"09:00-10:30", {"ENG (Engr.Mubashir)", "4-17"}}, {"11:00-12:30", {"AP (Dr.Ahmad)", "4-18"}}, {"14:00-15:30", {"CF-Lab (Engr.Amir)", "4-01"}}}},
            {"Tuesday", {{"09:00-10:30", {"CP (Dr.Raja)", "4-18"}}, {"11:00-12:30", {"CP-Lab (Engr.Bilal)", "4-01"}}, {"14:00-15:30", {"CP (Dr.Raja)", "4-18"}}}},
            {"Wednesday", {{"09:00-10:30", {"ISE (Dr.Awais)", "4-17"}}, {"11:00-12:30", {"ISE (Dr.Awais)", "4-18"}}, {"14:00-15:30", {"ISE (Dr.Awais)", "4-19"}}}},
            {"Thursday", {{"09:00-10:30", {"CP (Dr.Raja)", "4-18"}}, {"11:00-12:30", {"CP-Lab (Engr.Bilal)", "4-01"}}, {"14:00-15:30", {"CP (Dr.Raja)", "4-18"}}}},
            {"Friday", {{"09:00-10:30", {"DS (Engr.Sadaf)", "4-17"}}, {"11:00-12:30", {"OOP (Dr.Tamim)", "4-18"}}, {"14:00-15:30", {"OOP-Lab (Engr.Waleed)", "4-01"}}}},
        };
    }
    else if (section == "BSE-C") {
        timetableData = {
           {"Monday", {{"09:00-10:30", {"DBMS (Dr.Joddat)", "4-17"}}, {"11:00-12:30", {"AP-Lab (Engr.Iqra)", "4-02"}}, {"14:00-15:30", {"AC (Dr.Adeel)", "4-18"}}}},
            {"Tuesday", {{"09:00-10:30", {"DBMS (Dr.Joddat)", "4-17"}}, {"11:00-12:30", {"AP-Lab (Engr.Iqra)", "4-02"}}, {"14:00-15:30", {"AC (Dr.Adeel)", "4-18"}}}},
            {"Wednesday", {{"09:00-10:30", {"DBMS (Dr.Joddat)", "4-17"}}, {"11:00-12:30", {"AP-Lab (Engr.Iqra)", "4-02"}}, {"14:00-15:30", {"AC (Dr.Adeel)", "4-18"}}}},
            {"Thursday", {{"09:00-10:30", {"IS (Dr.Rahimullah)", "4-19"}}, {"11:00-12:30", {"IS (Dr.Rahimullah)", "4-19"}}, {"14:00-15:30", {"IS (Dr.Rahimullah)", "4-19"}}}},
            {"Friday", {{"09:00-10:30", {"EFC (Dr.Ali)", "4-19"}}, {"11:00-12:30", {"Dri (Dr.Adeel)", "4-18"}}, {"14:00-15:30", {"EFC (Dr.Ali)", "4-19"}}}},
        };
    }
    else if (section == "BSE-D") {
        timetableData = {
            {"Monday", {{"09:00-10:30", {"AI (Dr.Lotfullah)", "4-17"}}, {"11:00-12:30", {"AI-Lab (Dr.Hamza)", "4-02"}}, {"14:00-15:30", {"DS&A (Engr.Qasim)", "4-18"}}}},
            {"Tuesday", {{"09:00-10:30", {"AI (Dr.Lotfullah)", "4-17"}}, {"11:00-12:30", {"AI-Lab (Dr.Hamza)", "4-02"}}, {"14:00-15:30", {"DS&A (Engr.Qasim)", "4-18"}}}},
            {"Wednesday", {{"09:00-10:30", {"AI (Dr.Lotfullah)", "4-17"}}, {"11:00-12:30", {"AI-Lab (Dr.Hamza)", "4-02"}}, {"14:00-15:30", {"DS&A (Engr.Qasim)", "4-18"}}}},
            {"Thursday", {{"09:00-10:30", {"OHS (Engr.Naveed)", "4-18"}}, {"11:00-12:30", {"ML (Dr.Muslimwal)", "4-17"}}, {"14:00-15:30", {"OHS (Engr.Naveed)", "4-18"}}}},
            {"Friday", {{"09:00-10:30", {"OHS (Engr.Naveed)", "4-18"}}, {"11:00-12:30", {"ML (Dr.Muslimwal)", "4-17"}}, {"14:00-15:30", {"OHS (Engr.Naveed)", "4-18"}}}},
        };
    }
    else if (section == "BSE-E") {
        timetableData = {
            {"Monday", {{"09:00-10:30", {"GRA (Mr.Sara)", "4-17"}}, {"11:00-12:30", {"DL (Dr.Khan)", "4-18"}}, {"14:00-15:30", {"DL-Lab (Engr.Izaz)", "4-01"}}}},
            {"Tuesday", {{"09:00-10:30", {"GRA (Mr.Sara)", "4-17"}}, {"11:00-12:30", {"DL (Dr.Khan)", "4-18"}}, {"14:00-15:30", {"DL-Lab (Engr.Izaz)", "4-01"}}}},
            {"Wednesday", {{"09:00-10:30", {"GRA (Mr.Sara)", "4-17"}}, {"11:00-12:30", {"DL (Dr.Khan)", "4-18"}}, {"14:00-15:30", {"DL-Lab (Engr.Izaz)", "4-01"}}}},
            {"Thursday", {{"09:00-10:30", {"ICE (Dr.Faisal)", "4-19"}}, {"11:00-12:30", {"Dri (Dr.Ubaid)", "4-18"}}, {"14:00-15:30", {"ICE (Dr.Faisal)", "4-19"}}}},
            {"Friday", {{"09:00-10:30", {"ICE (Dr.Faisal)", "4-19"}}, {"11:00-12:30", {"Dri (Dr.Ubaid)", "4-18"}}, {"14:00-15:30", {"ICE (Dr.Faisal)", "4-19"}}}},
        };
    }


    // Write the timetable data to the file
    for (const auto& [day, classes] : timetableData) {
        timetableFile << day << ":\n";
        for (const auto& [time, courseInfo] : classes) {
            timetableFile << "  " << time << " - " << courseInfo.first << " (Room " << courseInfo.second << ")" << endl;
        }
    }
    timetableFile.close();
}

void searchByDay() {

        string dayToSearch;
        cout << "Enter the day to search (e.g., Mon, Tue, etc.): ";
        cin >> dayToSearch;
   
    // Load all sections and print classes for the specified day in each section
    vector<string> sections = { "BSE-A", "BSE-B", "BSE-C", "BSE-D", "BSE-E" };
    bool classesFound = false; 
    for (const string& section : sections) {
        ifstream timetableFile(section + "_timetable.txt");
        if (!timetableFile.is_open()) {
            cout << "Unable to open timetable file for section " << section << endl;
            continue;
        }

        cout << "Timetable for section " << section << ":\n";

        string line;
        bool dayScheduled = false; 
        cout << "Classes scheduled for " << dayToSearch << ":\n";
        //finding Mon, Tue... using binary search
        while (getline(timetableFile, line)) {
            if (line.find(dayToSearch) != string::npos && line.find("(Mon)") || line.find(dayToSearch) != string::npos && line.find("(Tue)") || line.find(dayToSearch) != string::npos && line.find("(Wed)") || line.find(dayToSearch) != string::npos && line.find("(Thu)") || line.find(dayToSearch) != string::npos && line.find("(Fri)")) {
                cout << line << endl;
                dayScheduled = true;
                classesFound = true;
            }
        
        }
        if (!dayScheduled) {
            cout << "No classes scheduled for " << dayToSearch << " in section " << section << endl;
        }
        cout << endl;
        timetableFile.close();
    }

    // If no class is found for the specified day in any section, display error message
    if (!classesFound) {
        cout << "No classes scheduled for " << dayToSearch << " in any section.\n";
    }
}


