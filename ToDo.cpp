#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

class toDoList {
private:
    vector<tuple<string, string, string>> tasks; // Store task with due date and status

public:
    toDoList(vector<tuple<string, string, string>> initialTasks) :
     tasks(initialTasks) {}

    void add_task(string task, string dueDate, string status) {
        tasks.push_back({task, dueDate, status});
    }

    string display_all_Tasks() {
        string allTasks = "";
        for (size_t i = 0; i < tasks.size(); ++i) {
            allTasks += to_string(i + 1) + ". " + get<0>(tasks[i]) + " -> Due: " 
            + get<1>(tasks[i]) + " -> Status: " + get<2>(tasks[i]) + "\n";
        }
        return allTasks;
    }

    void set_status(int index, string status) {
        if (index >= 0 && index < tasks.size()) {
            get<2>(tasks[index]) = status;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
//This function returns the current date in YYYY-MM-DD format
// It uses the <chrono> library to get the current time and formats it using <iomanip>.
    string get_default_due_date() {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        tm* local_time = localtime(&now_time);

        stringstream ss;
        ss << put_time(local_time, "%Y-%m-%d");
        return ss.str();
    }
};

int main() {
    vector<tuple<string, string, string>> items = {
        {"Read Newspaper", "2025-05-08", "Pending"},
        {"Solve Past Questions", "2025-05-09", "Pending"},
        {"Go to the Gym", "2025-05-07", "Completed"}
    };

    toDoList myList(items);

    while (true) {
        int choice;
        cout << "Welcome to ToDo List creator" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Add task\n2. View tasks\n3. Mark as Done\n4. Exit\n";
        cin >> choice;

        if (choice == 2) {
            cout << "Here are the tasks in your list: " << endl;
            cout << myList.display_all_Tasks() << endl;
        } else if (choice == 1) {
            string newTask, status, dueDate;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, newTask);
            cout << "Enter status (Pending/Completed): ";
            getline(cin, status);
            cout << "Enter due date (YYYY-MM-DD) or press Enter for default: ";
            getline(cin, dueDate);

            if (dueDate.empty()) {
                dueDate = myList.get_default_due_date();
            }

            myList.add_task(newTask, dueDate, status);

            cout << "Updated Task List:" << endl;
            cout << myList.display_all_Tasks() << endl;
        } else if (choice == 3) {
            cout << "Here are the tasks in your list: " << endl;
            cout << myList.display_all_Tasks() << endl;

            int taskIndex;
            cout << "Enter the task number to mark as done: ";
            cin >> taskIndex;

            myList.set_status(taskIndex - 1, "Completed");

            cout << "Task marked as done!" << endl;
            cout << "Updated Task List:" << endl;
            cout << myList.display_all_Tasks() << endl;
        } else if (choice == 4) {
            cout<<"Tasks Summary: " << endl;
            cout << myList.display_all_Tasks() << endl;
            cout << "Exiting the application. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}