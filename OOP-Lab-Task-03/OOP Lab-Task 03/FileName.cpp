#include <iostream>
#include <vector>
using namespace std;


void manageStudentGrades() {
    vector<int> grades;


    grades.push_back(99);
    grades.push_back(91);
    grades.push_back(86);


    cout << "\tStudents Grades\n\n";
    for (int grade : grades) {
        cout << "\t" << grade << endl;
    }
}


void contactManagementSystem() {

    string contacts[][2] = {
        {"Lotfullah", "07493009644"},
        {"Hamza", "0588845551"},
        {"Ali", "0731291510"}
    };


    string name;
    cout << "\tEnter name to search: ";
    cin >> name;

    bool found = false;
    for (auto contact : contacts) {
        if (contact[0] == name) {
            cout << "\n\tPhone number of " << name << " is: " << contact[1] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\tContact not found." << endl;
    }
}


class Node {
public:
    string taskDescription;
    Node* next;

    Node(string desc) {
        this->taskDescription = desc;
        this->next = nullptr;
    }
};

class TaskList {
public:
    Node* head;

    TaskList() {
        head = nullptr;
    }

    void addTask(const string& desc) {
        Node* newNode = new Node(desc);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayTasks() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "\tTask: " << temp->taskDescription << endl;
            temp = temp->next;
        }
    }

    ~TaskList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

void manageTaskList() {
    TaskList tasks;
    tasks.addTask("Finish Lab 3");
    tasks.addTask("Submit assignment");

    cout << "\tTasks in the list:\n";
    tasks.displayTasks();
}

int main() {
    cout << "\n\t\tOOP-Lab3 \n\n";
    cout << "\tManaging Student Grades\n";
    manageStudentGrades();
    cout << "\n";

    cout << "\tContact Management System\n";
    contactManagementSystem();
    cout << "\n";

    cout << "\tManaging a List of Tasks\n";
    manageTaskList();

    return 0;
}