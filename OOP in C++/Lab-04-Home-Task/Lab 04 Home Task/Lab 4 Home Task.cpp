#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    string taskName;
    list<ToDoList> subTasks;

public:
    // Constructor
    ToDoList(const string& name) : taskName(name) {}

    // Method to add a sub-task
    void addSubTask(const string& subTaskName) {
        subTasks.push_back(ToDoList(subTaskName));
    }

    // Method to add a sub-task (overloaded for ToDoList object)
    void addSubTask(const ToDoList& subTask) {
        subTasks.push_back(subTask);
    }

    // Method to display the task and its sub-tasks
    void display(int level = 0) const {
        for (int i = 0; i < level; ++i)
            cout << "  ";
        cout << taskName << endl;
        for (const auto& subTask : subTasks) {
            subTask.display(level + 1);
        }
    }
};

int main() {

    cout << "\n\n\t\t\tWelcome to the Home task 4*\n\n";
    ToDoList myToDoList("Main Task");
    myToDoList.addSubTask("Task 1");
    myToDoList.addSubTask("Task 2");
    myToDoList.addSubTask("Task 3");

    ToDoList subTask1("  Task 1.1");
    subTask1.addSubTask("Task 1.2");
    subTask1.addSubTask("Task 1.3");

    myToDoList.addSubTask(subTask1);

    ToDoList subTask2("  Task 2.1");
    subTask2.addSubTask("Task 2.2");
    subTask2.addSubTask("Task 2.3");

    myToDoList.addSubTask(subTask2);

    ToDoList subTask3("  Task 3.1");
    subTask3.addSubTask("Task 3.2");
    subTask3.addSubTask("Task 3.3");

    myToDoList.addSubTask(subTask3);

    myToDoList.display();

    return 0;
}