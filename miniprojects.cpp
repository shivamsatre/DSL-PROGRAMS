//#Satre Shivam Anil
//#SE-II (Q)
//#Roll No.: 27
//#PRN: F23112043

#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
using namespace std;

const int MENU_SIZE = 8;

void displayMenu(string items[], double prices[]) {
    cout << "\n---*** Welcome To Online Restaurant ***---\n";
    cout << "\n---  Menu ---\n";    
    for (int i = 0; i < MENU_SIZE; i++) {
        cout << (i + 1) << ". " << items[i] << " - Rs. " << prices[i] << "\n";
    }
    cout << "9. Checkout\n";
    cout << "-------------------------------------------\n";
}

double addItemToBill(int choice, double totalBill, double prices[], int quantities[]) {
    if (choice >= 1 && choice <= MENU_SIZE) {
        int quantity;

        cout << "Enter quantity for item " << choice << ": ";
        cin >> quantity;

        if (quantity > 0) {
            quantities[choice - 1] += quantity; // Update quantity for this item
            double itemTotal = prices[choice - 1] * quantity;
            totalBill += itemTotal;
            cout << "\nOrder placed for " << quantity << " of item " << choice 
                 << " (Rs. " << prices[choice - 1] << " each). Total: Rs. " 
                 << itemTotal << "\n" << endl;
        } else {
            cout << "Invalid quantity. Please try again.\n";
        }
    } else if (choice == 9) {
        cout << "Your Order Placed Successfully!\n";
    } else {
        cout << "Invalid selection. Please try again.\n";
    }
    return totalBill;
}

void printBill(double totalBill, string items[], double prices[], int quantities[]) {
    cout << "\n----------- Final Bill ------------\n";
    cout << fixed << setprecision(2); // Set precision for currency display

    for (int i = 0; i < MENU_SIZE; i++) {
        if (quantities[i] > 0) {
            double itemTotal = prices[i] * quantities[i];
            cout << items[i] << " x " << quantities[i] << " = Rs. " << itemTotal << "\n";
        }
    }

    cout << "-------------------------------------\n";
    cout << "Total Amount: Rs. " << totalBill << " /- only. \n" << endl;
    cout << "Thank you for dining with us!\n";
    cout << " " << endl;
}

void generatePaymentid(double totalBill) {
    cout << "Do payment through UPI ID: 7385517497@ibl\n" << endl;
}

int main() {
    int choice;
    double totalBill = 0.0;
    int quantities[MENU_SIZE] = {0}; // Array to store quantities of each item

    string menuItems[MENU_SIZE] = {
        "Palak Paneer      ",
        "Mutter Paneer     ",
        "Shahi Paneer      ",
        "Plain Rice        ",
        "Jeera Rice        ",
        "Gulab Jamun       ",
        "Mineral Water     ",
        "Tandoori Roti     ",
    };

    double menuPrices[MENU_SIZE] = {120.0, 140.0, 150.0, 40.0, 60.0, 50.0, 20.0, 15.0};

    displayMenu(menuItems, menuPrices);
    
    while (true) {
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        if (choice == 9) {
            break; 
        }

        totalBill = addItemToBill(choice, totalBill, menuPrices, quantities);
    }

    printBill(totalBill, menuItems, menuPrices, quantities);
    generatePaymentid(totalBill); 

    return 0;
}






/*OUTPUT  :
---*** Welcome To Online Restaurant ***---

---  Menu ---
1. Palak Paneer       - Rs. 120
2. Mutter Paneer      - Rs. 140
3. Shahi Paneer       - Rs. 150
4. Plain Rice         - Rs. 40
5. Jeera Rice         - Rs. 60
6. Gulab Jamun        - Rs. 50
7. Mineral Water      - Rs. 20
8. Tandoori Roti      - Rs. 15
9. Checkout
-------------------------------------------
Enter your choice (1-9): 4
Enter quantity for item 4: 2

Order placed for 2 of item 4 (Rs. 40 each). Total: Rs. 80

Enter your choice (1-9): 5
Enter quantity for item 5: 2

Order placed for 2 of item 5 (Rs. 60 each). Total: Rs. 120

Enter your choice (1-9): 6
Enter quantity for item 6: 1

Order placed for 1 of item 6 (Rs. 50 each). Total: Rs. 50

Enter your choice (1-9): 3
Enter quantity for item 3: 7

Order placed for 7 of item 3 (Rs. 150 each). Total: Rs. 1050

Enter your choice (1-9): 9

----------- Final Bill ------------
Shahi Paneer       x 7 = Rs. 1050.00
Plain Rice         x 2 = Rs. 80.00
Jeera Rice         x 2 = Rs. 120.00
Gulab Jamun        x 1 = Rs. 50.00
-------------------------------------
Total Amount: Rs. 1300.00 /- only.

Thank you for dining with us!

Do payment through UPI ID: 7385517497@ibl
*/