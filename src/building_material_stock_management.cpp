#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <iomanip.h>
#include <ctype.h>

// Building Material Stock Management System
// Educational Turbo C++ project
// Demo Admin Credentials: stockadmin / BMMS@2026

class Material {
private:
    int id;
    char name[50];
    float price;
    int quantity;
    char category[30];
public:
    void setData(int i, char n[], float p, int q, char c[]) {
        id = i;
        strcpy(name, n);
        price = p;
        quantity = q;
        strcpy(category, c);
    }
    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity;
        cout << "\nCategory: " << category << "\n";
    }
    int getId() { return id; }
    int getQuantity() { return quantity; }
    float getPrice() { return price; }
    char* getName() { return name; }
    char* getCategory() { return category; }
    void updateQuantity(int q) { quantity = q; }
};

class StockManager {
public:
    void addMaterial() {
        Material m;
        int id, q;
        float p;
        char n[50], c[30];
        clrscr();
        cout << "\nEnter Material ID: "; cin >> id;
        cout << "Enter Material Name: "; cin >> n;
        cout << "Enter Price: "; cin >> p;
        cout << "Enter Quantity: "; cin >> q;
        cout << "Enter Category: "; cin >> c;
        m.setData(id, n, p, q, c);
        ofstream out("material.dat", ios::binary | ios::app);
        out.write((char*)&m, sizeof(m));
        out.close();
        cout << "\nMaterial added successfully!";
        getch();
    }

    void viewStock() {
        Material m;
        ifstream in("material.dat", ios::binary);
        clrscr();
        cout << "\n========== AVAILABLE STOCK ==========";
        while (in.read((char*)&m, sizeof(m))) m.display();
        in.close();
        getch();
    }

    void deleteMaterial() {
        int id;
        Material m;
        clrscr();
        cout << "\nEnter Material ID to delete: "; cin >> id;
        ifstream in("material.dat", ios::binary);
        ofstream out("temp.dat", ios::binary);
        int found = 0;
        while (in.read((char*)&m, sizeof(m))) {
            if (m.getId() == id) found = 1;
            else out.write((char*)&m, sizeof(m));
        }
        in.close(); out.close();
        remove("material.dat"); rename("temp.dat", "material.dat");
        cout << (found ? "\nMaterial deleted successfully." : "\nMaterial not found.");
        getch();
    }

    void lowStock() {
        Material m;
        ifstream in("material.dat", ios::binary);
        clrscr();
        cout << "\n========== LOW STOCK ITEMS ==========";
        while (in.read((char*)&m, sizeof(m)))
            if (m.getQuantity() < 10) m.display();
        in.close();
        getch();
    }

    void purchaseStock() {
        int id, addQty;
        Material m;
        clrscr();
        cout << "\nEnter Material ID: "; cin >> id;
        cout << "Enter quantity to add: "; cin >> addQty;
        ifstream in("material.dat", ios::binary);
        ofstream out("temp.dat", ios::binary);
        int found = 0;
        while (in.read((char*)&m, sizeof(m))) {
            if (m.getId() == id) {
                m.updateQuantity(m.getQuantity() + addQty);
                found = 1;
            }
            out.write((char*)&m, sizeof(m));
        }
        in.close(); out.close();
        remove("material.dat"); rename("temp.dat", "material.dat");
        cout << (found ? "\nStock updated successfully." : "\nMaterial not found.");
        getch();
    }

    void report() {
        Material m;
        ifstream in("material.dat", ios::binary);
        ofstream out("report.txt");
        clrscr();
        out << "BUILDING MATERIAL STOCK REPORT\n\n";
        while (in.read((char*)&m, sizeof(m))) {
            out << "ID: " << m.getId() << "\n";
            out << "Name: " << m.getName() << "\n";
            out << "Price: " << m.getPrice() << "\n";
            out << "Quantity: " << m.getQuantity() << "\n";
            out << "Category: " << m.getCategory() << "\n\n";
        }
        in.close(); out.close();
        cout << "\nReport generated successfully in report.txt";
        getch();
    }
};

void adminMenu() {
    char username[30], password[30];
    clrscr();
    cout << "\n========== ADMIN LOGIN ==========";
    cout << "\nUsername: "; cin >> username;
    cout << "Password: ";
    int i = 0; char ch;
    while ((ch = getch()) != 13 && i < 29) {
        if (ch == 8 && i > 0) { i--; cout << "\b \b"; }
        else if (ch != 8) { password[i++] = ch; cout << '*'; }
    }
    password[i] = '\0';
    if (strcmp(username, "stockadmin") != 0 || strcmp(password, "BMMS@2026") != 0) {
        cout << "\nInvalid credentials!"; getch(); return;
    }
    StockManager sm;
    int choice;
    do {
        clrscr();
        cout << "\n========== ADMIN MENU ==========";
        cout << "\n1. Add Material";
        cout << "\n2. View Stock";
        cout << "\n3. Delete Material";
        cout << "\n4. Low Stock Alert";
        cout << "\n5. Purchase/Add Stock";
        cout << "\n6. Generate Stock Report";
        cout << "\n0. Exit";
        cout << "\nEnter choice: "; cin >> choice;
        switch(choice) {
            case 1: sm.addMaterial(); break;
            case 2: sm.viewStock(); break;
            case 3: sm.deleteMaterial(); break;
            case 4: sm.lowStock(); break;
            case 5: sm.purchaseStock(); break;
            case 6: sm.report(); break;
        }
    } while(choice != 0);
}

void userMenu() {
    clrscr();
    cout << "\n========== USER MODULE ==========";
    cout << "\nCustomer purchase and billing functionality is available in the original project.\n";
    cout << "\nPress any key to return...";
    getch();
}

void main() {
    int choice;
    do {
        clrscr();
        cout << "\n========================================";
        cout << "\n BUILDING MATERIAL STOCK MANAGEMENT SYSTEM";
        cout << "\n========================================";
        cout << "\n1. Admin";
        cout << "\n2. User";
        cout << "\n0. Exit";
        cout << "\nEnter choice: "; cin >> choice;
        if (choice == 1) adminMenu();
        else if (choice == 2) userMenu();
    } while(choice != 0);
}
