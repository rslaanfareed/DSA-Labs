#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct BusRoute {
    string routeName;
    int students;
    int distance;
    bool available;


    bool operator<(const BusRoute& other) const {
        int thisPriority = available ? (students * 10 + distance) : -1;
        int otherPriority = other.available ? (other.students * 10 + other.distance) : -1;

        return thisPriority < otherPriority;
    }
};

int main() {
    priority_queue<BusRoute> busQueue;


    busQueue.push({"Route A", 50, 12, true});
    busQueue.push({"Route B", 30, 5, true});
    busQueue.push({"Route C", 70, 20, true});
    busQueue.push({"Route D", 40, 15, false});
    busQueue.push({"Route E", 60, 10, true});

    cout << "University Bus Scheduling Order:\n\n";

    int order = 1;
    while (!busQueue.empty()) {
        BusRoute current = busQueue.top();
        busQueue.pop();

        cout << "Order " << order++ << ":\n";
        cout << "Route Name     : " << current.routeName << endl;
        cout << "Students       : " << current.students << endl;
        cout << "Distance (km)  : " << current.distance << endl;
        cout << "Bus Available  : " << (current.available ? "Yes" : "No") << endl;

        if (current.available)
            cout << "Reason         : Highest priority (more students & distance)\n\n";
        else
            cout << "Reason         : Bus not available\n\n";
    }

    return 0;
}
