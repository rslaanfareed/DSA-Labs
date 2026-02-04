#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
};


bool operator<(const Task& a, const Task& b) {
    return a.priority < b.priority;
}

void displayTasks(priority_queue<Task, vector<Task>> pq) {
    if (pq.empty()) {
        cout << "No tasks available\n";
        return;
    }

    cout << "\nTasks by priority:\n";
    while (!pq.empty()) {
        Task t = pq.top();
        pq.pop();
        cout << t.name << " | Priority: " << t.priority << endl;
    }
}

int main() {
    priority_queue<Task, vector<Task>> taskQueue;
    int choice;

    do {
        cout << "\n1. Add Task";
        cout << "\n2. Execute Task";
        cout << "\n3. Display All Tasks";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Task t;
                cout << "Task name: ";
                cin.ignore();
                getline(cin, t.name);

                cout << "Priority: ";
                cin >> t.priority;

                taskQueue.push(t);
                cout << "Task added\n";
                break;
            }
            case 2: {
                if (taskQueue.empty()) {
                    cout << "No task to execute\n";
                } else {
                    Task t = taskQueue.top();
                    taskQueue.pop();
                    cout << "Executing: " << t.name
                         << " | Priority: " << t.priority << endl;
                }
                break;
            }
            case 3:
                displayTasks(taskQueue);
                break;

            case 4:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
