#include <iostream>
#include <fstream>
#include <iomanip>
#include <set> // include set instead of list
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//change std::list to std::set
// function prototypes
int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string names[], string colors[]);
void display_trip(set<Goat> &trip);
int main_menu();

int main() {
    srand(time(0));

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    
    // change the list of goats to set of goats to manage trip
    set<Goat> trip; // Manager for Goat
    
    bool running = true;
    
    // The main loop
    while (running) {
        int choice = main_menu();
        switch(choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

// Second Task: create main_menu()
int main_menu() {
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a Goat" << endl;
    cout << "[2] Delete a Goat" << endl;
    cout << "[3] List a Goat" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    return choice;
}

// Third Task: Add a goat to the list
// Change list to set
void add_goat(set<Goat> &trip, string names[], string colors[]) {
    int rand_name_idx = rand() % SZ_NAMES;
    int rand_color_idx = rand() % SZ_COLORS;
    int rand_age = rand() % MAX_AGE + 1;
    
    Goat new_goat(names[rand_name_idx], rand_age, colors[rand_color_idx]);
    trip.insert(new_goat); // insert new goat into set (sorted by age automatically)
    cout << "Added: " << new_goat.description() << endl;
    
}

// Third Task: Now we delete a goat from the list
// change from list to set
void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats can be deleted" << endl;
        return;
    }
    
    // asks user to select which goat to delete
    int index = select_goat(trip);
    if (index == -1) {
        cout << "Invalid Selection." << endl;
        return;
    }
    
    // find iterator for selected goat within the set
    auto it = trip.begin();
    advance(it, index);
    
    // output the goat that is to be deleted and remove it from the set
    cout << "Deleting: " << it->description() << endl;
    trip.erase(it);
}

// Third Task: Display whole list of goats
void display_trip(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in the trip" << endl;
        return;
    }
    
    int i = 1;
    for (const auto &goat : trip) {
        cout << "[" << i++ << "] " << goat.description() << "\n";
    }
}

// Task three: Select goat from list
int select_goat(list<Goat> trip) {
    if (trip.empty()) return -1;
    
    int i = 1;
    for (const auto &goat : trip) {
        cout << "[" << i++ << "] " << goat.description() << endl;
    }
    
    int choice;
    cout << "Select a ghost by the number: ";
    cin >> choice;
    
    if (choice < 1 || choice > trip.size()) return -1;
    return choice - 1;
}
