#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    // Add a task to the to-do list
    void addTask(const string& task) {
        tasks.push_back(task);
    }

    // Display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
        } else {
            cout << "\nTo-Do List:" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }

    // Delete a task from the to-do list
    void deleteTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + (index - 1));
            cout << "Task " << index << " deleted." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    string task;
    int taskIndex;

    while (true) {
        // Display menu
        cout << "\nTo-Do List Menu" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to ignore the newline left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, task);
                toDoList.addTask(task);
                cout << "Task added!" << endl;
                break;

            case 2:
                toDoList.displayTasks();
                break;

            case 3:
                toDoList.displayTasks();
                cout << "Enter task number to delete: ";
                cin >> taskIndex;
                toDoList.deleteTask(taskIndex);
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
