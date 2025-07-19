#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bill {
public:
    string item;
    int rate;
    int quantity;

    void inputItem() {
        cin.ignore(); 
        cout << "Enter Item Name: ";
        getline(cin, item);  

        cout << "Enter Rate: ";
        cin >> rate;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void saveToFile() {
        ofstream out("Bill.txt", ios::app);
        out << item << " | " << rate << " | " << quantity << endl;
        out.close();
        cout << "Item added successfully!\n";
    }
};

void printBill() {
    ifstream in("Bill.txt");
    string itemLine;
    int total = 0;

    cout << "\n--- Bill Summary ---\n";
    cout << "Item\t\tRate\tQty\tAmount\n";

    while (getline(in, itemLine)) {
        string itemName;
        int rate, quantity;

        size_t pos1 = itemLine.find(" | ");
        size_t pos2 = itemLine.find(" | ", pos1 + 3);

        if (pos1 != string::npos && pos2 != string::npos) {
            itemName = itemLine.substr(0, pos1);
            rate = stoi(itemLine.substr(pos1 + 3, pos2 - (pos1 + 3)));
            quantity = stoi(itemLine.substr(pos2 + 3));
            int amount = rate * quantity;

            cout << itemName << "\t" << rate << "\t" << quantity << "\t" << amount << endl;
            total += amount;
        }
    }

    cout << "------------------------------\n";
    cout << "Total Bill: " << total << endl;
    in.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Item\n2. Print Bill\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Bill b;
            b.inputItem();
            b.saveToFile();
        }
        else if (choice == 2) {
            printBill();
        }
        else if (choice == 3) {
            cout << "Thank you for using the billing system!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
