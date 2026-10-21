// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "MedicineBatch.h"

using namespace std;

// Sorting rule
bool compareExpiry(MedicineBatch a, MedicineBatch b) {
    if (a.expYear != b.expYear) return a.expYear < b.expYear;
    return a.expMonth < b.expMonth;
}

// --- NEW DEDICATED FUNCTIONS ---

// Function for Choice 1
void handleAddBatch(vector<MedicineBatch>& inventory) {
    string name, id;
    int qty, m, y;
    cout << "Name, BatchID, Quantity, ExpMonth, ExpYear (separated by spaces): ";
    cin >> name >> id >> qty >> m >> y;
    
    inventory.push_back(MedicineBatch(name, id, qty, m, y));
    sort(inventory.begin(), inventory.end(), compareExpiry);
    cout << "Added and sorted!\n";
}

// Function for Choice 2
void handleIssueMedicine(vector<MedicineBatch>& inventory) {
    string reqName;
    int reqQty;
    cout << "Enter Medicine Name and Quantity needed: ";
    cin >> reqName >> reqQty;

    for (size_t i = 0; i < inventory.size() && reqQty > 0; i++) {
        if (inventory[i].name == reqName && inventory[i].quantity > 0) {
            if (inventory[i].quantity <= reqQty) {
                cout << "Issued " << inventory[i].quantity << " from " << inventory[i].batchID << "\n";
                reqQty -= inventory[i].quantity;
                inventory[i].quantity = 0; 
            } else {
                cout << "Issued " << reqQty << " from " << inventory[i].batchID << "\n";
                inventory[i].quantity -= reqQty;
                reqQty = 0; 
            }
        }
    }

    if (reqQty > 0) {
        cout << "Warning: Not enough stock! Missing " << reqQty << " pills.\n";
    }
}

// Function for Choice 3
void handleViewStock(const vector<MedicineBatch>& inventory) {
    cout << "\n--- Current Inventory (Sorted by Expiry) ---\n";
    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].quantity > 0) { 
            cout << inventory[i].name << " | Batch: " << inventory[i].batchID 
                 << " | Qty: " << inventory[i].quantity 
                 << " | Exp: " << inventory[i].expMonth << "-" << inventory[i].expYear << "\n";
        }
    }
}

// --- SUPER CLEAN MAIN FUNCTION ---

int main() {
    vector<MedicineBatch> inventory;
    int choice;

    while (true) {
        cout << "\n=== Pharmacy System ===\n";
        cout << "1. Add Batch\n2. Issue Medicine\n3. View Stock\n4. Exit\nEnter: ";
        cin >> choice;

        if (choice == 1) {
            handleAddBatch(inventory);
        } else if (choice == 2) {
            handleIssueMedicine(inventory);
        } else if (choice == 3) {
            handleViewStock(inventory);
        } else if (choice == 4) {
            cout << "Exiting system...\n";
            break;
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}