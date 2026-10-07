#include <iostream>
#include <string>
using namespace std;

// ============================================================
// CIRCULAR LINKED LIST - TRAFFIC SIGNAL MANAGEMENT
// ============================================================

struct Signal {
    int id;
    string name;
    string direction;
    string status;
    Signal* next;
};

class CircularSignalList {
private:
    Signal* last;

public:
    CircularSignalList() {
        last = nullptr;
    }

    // Add a traffic signal
    void addSignal(int id, string name, string direction) {
        Signal* newSignal = new Signal;
        newSignal->id = id;
        newSignal->name = name;
        newSignal->direction = direction;
        newSignal->status = "RED";

        if (last == nullptr) {
            last = newSignal;
            last->next = last;
        } else {
            newSignal->next = last->next;
            last->next = newSignal;
            last = newSignal;
        }

        cout << "Traffic signal added successfully.\n";
    }

    // Delete a traffic signal
    void deleteSignal(int id) {
        if (last == nullptr) {
            cout << "No traffic signals available.\n";
            return;
        }

        Signal* current = last->next;
        Signal* previous = last;

        do {
            if (current->id == id) {
                if (current == last && current->next == last) {
                    delete current;
                    last = nullptr;
                } else {
                    previous->next = current->next;

                    if (current == last)
                        last = previous;

                    delete current;
                }

                cout << "Traffic signal deleted successfully.\n";
                return;
            }

            previous = current;
            current = current->next;

        } while (current != last->next);

        cout << "Signal not found.\n";
    }

    // Display all signals
    void displaySignals() {
        if (last == nullptr) {
            cout << "No traffic signals available.\n";
            return;
        }

        Signal* current = last->next;

        cout << "\nTraffic Signal Cycle:\n";

        do {
            cout << "Signal " << current->id
                 << " | " << current->name
                 << " | Direction: " << current->direction
                 << " | Status: " << current->status << endl;

            current = current->next;

        } while (current != last->next);
    }

    // Set one signal to GREEN and others to RED
    void setEmergencySignal(int id) {
        if (last == nullptr) {
            cout << "No traffic signals available.\n";
            return;
        }

        Signal* current = last->next;
        bool found = false;

        do {
            if (current->id == id) {
                current->status = "GREEN";
                found = true;
            } else {
                current->status = "RED";
            }

            current = current->next;

        } while (current != last->next);

        if (found)
            cout << "Emergency priority activated.\n";
        else
            cout << "Signal not found.\n";
    }

    // Resume normal operation
    void resetSignals() {
        if (last == nullptr)
            return;

        Signal* current = last->next;

        do {
            current->status = "RED";
            current = current->next;
        } while (current != last->next);

        // First signal becomes GREEN
        last->next->status = "GREEN";

        cout << "Normal traffic signal cycle resumed.\n";
    }

    // Move signal cycle
    void nextSignal() {
        if (last == nullptr) {
            cout << "No signals available.\n";
            return;
        }

        // Current first signal becomes RED
        last->next->status = "RED";

        // Move first node to next node
        last->next = last->next->next;

        last->next->status = "GREEN";

        cout << "Moved to next traffic signal.\n";
        cout << "Current Signal: "
             << last->next->name << endl;
    }
};


// ============================================================
// DOUBLY LINKED LIST - ROAD / JUNCTION MANAGEMENT
// ============================================================

struct Junction {
    int id;
    string name;
    Junction* prev;
    Junction* next;
};

class DoublyRoadList {
private:
    Junction* head;
    Junction* tail;

public:
    DoublyRoadList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add a junction
    void addJunction(int id, string name) {
        Junction* newJunction = new Junction;

        newJunction->id = id;
        newJunction->name = name;
        newJunction->prev = nullptr;
        newJunction->next = nullptr;

        if (head == nullptr) {
            head = tail = newJunction;
        } else {
            tail->next = newJunction;
            newJunction->prev = tail;
            tail = newJunction;
        }

        cout << "Junction added successfully.\n";
    }

    // Delete a junction
    void deleteJunction(int id) {
        if (head == nullptr) {
            cout << "No junctions available.\n";
            return;
        }

        Junction* current = head;

        while (current != nullptr) {
            if (current->id == id) {

                if (current->prev != nullptr)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;

                delete current;

                cout << "Junction deleted successfully.\n";
                return;
            }

            current = current->next;
        }

        cout << "Junction not found.\n";
    }

    // Forward traversal
    void displayForward() {
        if (head == nullptr) {
            cout << "No junctions available.\n";
            return;
        }

        Junction* current = head;

        cout << "\nRoad Network - Forward Direction:\n";

        while (current != nullptr) {
            cout << "[" << current->id << "] "
                 << current->name;

            if (current->next != nullptr)
                cout << " <-> ";

            current = current->next;
        }

        cout << endl;
    }

    // Backward traversal
    void displayBackward() {
        if (tail == nullptr) {
            cout << "No junctions available.\n";
            return;
        }

        Junction* current = tail;

        cout << "\nRoad Network - Backward Direction:\n";

        while (current != nullptr) {
            cout << "[" << current->id << "] "
                 << current->name;

            if (current->prev != nullptr)
                cout << " <-> ";

            current = current->prev;
        }

        cout << endl;
    }

    // Search junction
    void searchJunction(int id) {
        Junction* current = head;

        while (current != nullptr) {
            if (current->id == id) {
                cout << "Junction Found: "
                     << current->name << endl;
                return;
            }

            current = current->next;
        }

        cout << "Junction not found.\n";
    }
};


// ============================================================
// MAIN PROGRAM
// ============================================================

int main() {

    CircularSignalList signals;
    DoublyRoadList roads;

    int choice;

    // Initial traffic signals
    signals.addSignal(1, "North Signal", "North");
    signals.addSignal(2, "East Signal", "East");
    signals.addSignal(3, "South Signal", "South");
    signals.addSignal(4, "West Signal", "West");

    // Initial road network
    roads.addJunction(1, "Main Gate");
    roads.addJunction(2, "Central Junction");
    roads.addJunction(3, "Hospital Junction");
    roads.addJunction(4, "Market Junction");

    // First signal is GREEN
    signals.resetSignals();

    do {
        cout << "\n============================================\n";
        cout << " SMART TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Display Traffic Signals\n";
        cout << "2. Move to Next Signal\n";
        cout << "3. Add Traffic Signal\n";
        cout << "4. Delete Traffic Signal\n";
        cout << "5. Emergency Vehicle Priority\n";
        cout << "6. Resume Normal Signal Cycle\n";
        cout << "7. Display Road Network - Forward\n";
        cout << "8. Display Road Network - Backward\n";
        cout << "9. Add Road Junction\n";
        cout << "10. Delete Road Junction\n";
        cout << "11. Search Road Junction\n";
        cout << "12. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            signals.displaySignals();
            break;

        case 2:
            signals.nextSignal();
            break;

        case 3: {
            int id;
            string name, direction;

            cout << "Enter signal ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter signal name: ";
            getline(cin, name);

            cout << "Enter direction: ";
            getline(cin, direction);

            signals.addSignal(id, name, direction);
            break;
        }

        case 4: {
            int id;

            cout << "Enter signal ID to delete: ";
            cin >> id;

            signals.deleteSignal(id);
            break;
        }

        case 5: {
            int id;

            cout << "\nEmergency Vehicle Detected\n";
            cout << "Enter signal ID requiring priority: ";
            cin >> id;

            signals.setEmergencySignal(id);
            signals.displaySignals();

            break;
        }

        case 6:
            signals.resetSignals();
            signals.displaySignals();
            break;

        case 7:
            roads.displayForward();
            break;

        case 8:
            roads.displayBackward();
            break;

        case 9: {
            int id;
            string name;

            cout << "Enter junction ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter junction name: ";
            getline(cin, name);

            roads.addJunction(id, name);
            break;
        }

        case 10: {
            int id;

            cout << "Enter junction ID to delete: ";
            cin >> id;

            roads.deleteJunction(id);
            break;
        }

        case 11: {
            int id;

            cout << "Enter junction ID to search: ";
            cin >> id;

            roads.searchJunction(id);
            break;
        }

        case 12:
            cout << "\nExiting Smart Traffic Management System.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 12);

    return 0;
}
