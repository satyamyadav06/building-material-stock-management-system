#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<stdlib.h>
#include<ctype.h>
int isDuplicateName(const char* pname);
class Material
{
int id;
char name[20];
int qty;
char unit[15];
float cost;
public:
void input()
{
cin.ignore();
do
 {
    int valid = 1;
    cout << "Enter the name of product: ";
    cin.getline(name, 20);

    for (int i = 0; name[i] != '\0'; i++)
{
	if (!isalpha(name[i]) && name[i] != ' ')
 {
	    valid = 0;
	    break;
	}
    }

    if (strlen(name) == 0 || !valid)
 {
	cout << "Invalid name! Only alphabets and spaces allowed.\n";
	continue;
    }

    if (isDuplicateName(name))
 {
	cout << "This product name already exists! Enter a unique name.\n";
	continue;
    }

    break;
}
while (1);

char input[20];
int valid;

do
{
    valid = 1;

    cout << "Enter the quantity: ";
    cin >> input;

    for (int i = 0; input[i] != '\0'; i++)
    {
	if (!isdigit(input[i]))
	{
	    valid = 0;
	    break;
	}
    }

    if (!valid || atoi(input) <= 0)
    {
	cout << "\n Invalid quantity! Please enter a positive number only.\n";
    }

}
while (!valid || atoi(input) <= 0);

qty = atoi(input);

cin.ignore();
do
 {
    int valid = 1;
    cout << "Enter unit of product  ";
    cin.getline(unit, 15);

    for (int i = 0; unit[i] != '\0'; i++)
 {
	if (!isalpha(unit[i]))
 {
	    valid = 0;
	    break;
 }
   }

    if (!valid || strlen(unit) == 0)
 {
	cout << "\n Invalid unit! Only alphabetic characters allowed.\n";
    }
    else
{
	break;
    }
}
while (1);

char costInput[20];
float costVal;
int validCost;

do {
    validCost = 1;
    int dotCount = 0;

    cout << "Enter the cost of 1 unit of product: ";
    cin >> costInput;

    for (int i = 0; costInput[i] != '\0'; i++)
    {
	if (costInput[i] == '.')
	{
	    dotCount++;
	}
	else if (!isdigit(costInput[i]))
	{
	    validCost = 0;
	    break;
	}
    }

    if (dotCount > 1)
	validCost = 0;

    costVal = atof(costInput);
    if (!validCost || costVal <= 0)
    {
	cout << "\nInvalid cost! Only positive numbers allowed.\n";
	validCost = 0;
    }

}
 while (!validCost);

cost = costVal;
}
void display()
{
cout<<"\n-------------------\n";
cout<<"product id:"<<id<<endl;
cout<<"product name:"<<name<<endl;
cout<<"product quantity:"<<qty<<" "<<unit<<endl;
cout<<"cost of 1 "<< unit<<":"<< cost<<endl;
cout<<"Total cost: "<<cost*qty<<endl;
}
int getid()
{
return id;
}
int getqty()
{
return qty;
}
void updateQty(int newQty)
{
qty = newQty;
}
char* getName()
{
return name;
}
char* getUnit()
{
return unit;
}
float getCost()
{
return cost;
}
void setid(int i)
{
    id = i;
}
void setName(const char* n)
{
    strcpy(name, n);
}

};
class StockManager
{
public:
void addStocks()
{
    clrscr();
    char choice;

    do
    {
	int lastId = 0;
	Material temp;
	ifstream fin("material.dat", ios::binary);
	while (fin.read((char*)&temp, sizeof(temp)))
	{
	    lastId = temp.getid();
	}
	fin.close();

	int newId = lastId + 1;

	Material m;
	m.setid(newId);
	m.input();

	ofstream fout("material.dat", ios::binary | ios::app);
	fout.write((char*)&m, sizeof(m));
	fout.close();

	cout << "\n Product added successfully with ID: " << newId << "\n";

	cout << "\nAdd another product? (y/n): ";
	cin >> choice;
       }
while (choice == 'y' || choice == 'Y');
}
void showStocks()
{
clrscr();
Material m;
ifstream fin("material.dat", ios::binary);
int count = 0;
if (!fin)
 {
	cout << "\nError: Unable to open file.\n";
	return;
 }

    cout << "\n===================== All Building Material Stocks ============================\n\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout <<setw(5) << "ID"
	 << setw(15) << "Name"
	 << setw(14) << "Quantity"
	 << setw(10) << "Unit"
	 << setw(16) << "Cost/Unit"
	 << setw(16) << "Total Cost"
	 << "\n";
    cout << "-------------------------------------------------------------------------------\n";
while (fin.read((char*)&m, sizeof(m)))
{
cout	     << setw(5) << m.getid()
	     << setw(15) << m.getName()
	     << setw(14) << m.getqty()
	     << setw(10) << m.getUnit()
	     << setw(14) << m.getCost()
	     << setw(14) << (m.getCost() * m.getqty())
	     << "\n";
		count++;
}
if (count == 0)
	{
	cout << "\nNo Stock found.";
	}
fin.close();
}
void user_display()
{
clrscr();
Material m;
ifstream fin("material.dat", ios::binary);
int count = 0;
if (!fin)
 {
	cout << "\nError: Unable to open file.\n";
	return;
 }

    cout << "\n===================== All Building Material Stocks ============================\n\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout <<setw(5) << "ID"
	 << setw(15) << "Name"
	// << setw(14) << "Quantity"
	 << setw(10) << "Unit"
	 << setw(16) << "Cost/Unit"
	// << setw(16) << "Total Cost"
	 << "\n";
    cout << "-------------------------------------------------------------------------------\n";
while (fin.read((char*)&m, sizeof(m)))
{
cout	     << setw(5) << m.getid()
	     << setw(15) << m.getName()
	  //   << setw(14) << m.getqty()
	     << setw(10) << m.getUnit()
	     << setw(14) << m.getCost()
	    // << setw(14) << (m.getCost() * m.getqty())
	     << "\n";
		count++;
}
if (count == 0)
	{
	cout << "\nNo Stock found.";
	}
fin.close();
}

void updateStock()
{
fstream stock;
Material m;
int pid,flag=0;
showStocks();
stock.open("material.dat",ios::in|ios::out|ios::binary);
if(!stock)
{
cout<<"\nstock not found"<<endl;
return;
}
cout<<"\nenter product id to update";
cin>>pid;
while (stock.read((char*)&m, sizeof(m)))
{
if(m.getid()==pid)
{
cout<<"\n insert updated record:";
m.input();
int pos =stock.tellg()-sizeof(m);
stock.seekp(pos);
stock.write((char*)&m,sizeof(m));
flag=1;
cout<<"\n Stock updated successfully"<<endl;
stock.close();
break;
}
}
if(!flag)
{
cout<<"\nstock not found"<<endl;
stock.close();
}
}
void deleteStocks()
{
Material m;
int pid, found = 0;
cout << "\nEnter Product id to delete: ";
cin >> pid;
ifstream fin("material.dat", ios::binary);
ofstream fout("temp.dat", ios::binary);
while (fin.read((char*)&m, sizeof(m)))
 {
	if (m.getid() != pid)
	{
	  fout.write((char*)&m, sizeof(m));
	} else {
	    found = 1;
	}
    }
fin.close();
fout.close();
remove("material.dat");
rename("temp.dat", "material.dat");
if (found)
{
	cout << "Stock deleted successfully.\n";
}
else
{
	cout << "Stock not found.\n";
}
}
void lowStockAlert()
{
    Material m;
    int lowstock = 10;
    int found = 0;

    ifstream fin("material.dat", ios::binary);
    cout << "\n==== Low Stock Alert (Qty < " << lowstock << ") ====\n";

    while (fin.read((char*)&m, sizeof(m)))
 {
	if (m.getqty() < lowstock)
	{
	    m.display();
	    found = 1;
	}
 }

    fin.close();

    if (!found)
    {
	cout << "\nNo low stock items found.\n";
    }
}
void purchase()
{
    fstream file("material.dat", ios::in | ios::out | ios::binary);
    Material m;
    int pid, qtyToAdd, found = 0;

    showStocks();

    cout << "\nEnter product ID to purchase (add stock): ";

    // ✅ Input validation for product ID
    if (!(cin >> pid))
    {
        cout << "\nInvalid input! Product ID must be a number.";
        cin.clear();          // clear error flags
        fflush(stdin);        // flush garbage
        cout << "\nPress any key to return...";
        getch();
        return;
    }

    while (file.read((char*)&m, sizeof(m)))
    {
	if (m.getid() == pid)
	{
	    found = 1;
	    cout << "\nEnter quantity to purchase: ";

	    // ✅ Input validation for quantity
	    if (!(cin >> qtyToAdd))
	    {
		cout << "\nInvalid quantity! Must be a number.";
		cin.clear();
		fflush(stdin);
		break;
	    }

	    if (qtyToAdd > 0)
	    {
		int pos = file.tellg() - sizeof(m);
		file.seekp(pos);
		m.updateQty(m.getqty() + qtyToAdd);
		file.write((char*)&m, sizeof(m));
		cout << "\nStock updated successfully!\n";
	    }
	    else
	    {
		cout << "\nInvalid quantity!";
	    }
	    break;
	}
    }

    file.close();

    if (!found)
	cout << "\nProduct ID not found!";

    cout << "\nPress any key to return to menu...";
    getch();
    fflush(stdin);  // ✅ clean up buffer before returning
}
void buy()
{
    clrscr();
    fstream file("material.dat", ios::in | ios::out | ios::binary);
    ofstream bill("bill.txt", ios::app);
    ofstream temp("current_bill.txt");

    Material m;
    int pid, qtytobuy, found;
    long int totalAmount = 0;
    char choice;
    char username[30];
    char mode[20], upi[40];
    int billID = random(9000) + 1000;
    int anyPurchase = 0;

    cin.ignore();
    do
    {
	int valid = 1;
	cout << "\nEnter Your Name: ";
	cin.getline(username, 30);

	for (int i = 0; username[i] != '\0'; i++)
	{
	    if (!isalpha(username[i]) && username[i] != ' ')
	    {
		valid = 0;
		break;
	    }
	}

	if (!valid || strlen(username) == 0)
	{
	    cout << "\nInvalid name! Only alphabets and spaces are allowed.\n";
	}
else
 {
	    break;
   }
    }
while (1);

      bill << "---------------------- BILL ----------------------\n";
    temp << "---------------------- BILL ----------------------\n";

    bill << "Bill ID: " << billID << "\n";
    temp << "Bill ID: " << billID << "\n";

    struct date d;
    struct time t;
    getdate(&d);
    gettime(&t);

    bill << "Date: " <<int( d.da_day) << "/" <<int( d.da_mon) << "/" <<int( d.da_year) << "\n";
    temp << "Date: " <<int( d.da_day) << "/" <<int( d.da_mon) << "/" << int(d.da_year) << "\n";

    bill << "Time: " <<int( t.ti_hour) << ":" <<int( t.ti_min) << ":" << int(t.ti_sec) << "\n";
    temp << "Time: " <<int( t.ti_hour) << ":" <<int( t.ti_min) << ":" <<int( t.ti_sec) << "\n";

    bill << "Customer Name: " << username << "\n";
    temp << "Customer Name: " << username << "\n";

    bill << "--------------------------------------------------\n";
    temp << "--------------------------------------------------\n";

    bill << "ID    Name     Qty     Rate     Total\n";
    temp << "ID    Name     Qty     Rate     Total\n";

	user_display();

      do
	{
	found = 0;
	cout << "\nEnter product ID to buy: ";
	cin >> pid;

	if (cin.fail())
	{
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "\nInvalid product ID!\n";
	    continue;
	}

	file.clear();
	file.seekg(0, ios::beg);

	while (file.read((char*)&m, sizeof(m)))
	 {
	    if (m.getid() == pid)
	{
		found = 1;
		cout << "Enter quantity to buy: ";
		cin >> qtytobuy;

		if (cin.fail() || qtytobuy <= 0)
		 {
		    cin.clear();
		    cin.ignore(1000, '\n');
		    cout << "\nInvalid quantity!\n";
		    break;
		}

		if (qtytobuy <= m.getqty())
		{
		    int pos = file.tellg() - sizeof(m);
		    file.seekp(pos);
		    m.updateQty(m.getqty() - qtytobuy);
		    file.write((char*)&m, sizeof(m));

		    float total = qtytobuy * m.getCost();
		    totalAmount += total;
		    anyPurchase = 1;

		    bill << m.getid() << setw(10) << m.getName()
			 << setw(6) << qtytobuy << setw(9) << m.getCost()
			 << setw(10) << total << "\n";

		    temp << m.getid() << setw(10) << m.getName()
			 << setw(6) << qtytobuy << setw(9) << m.getCost()
			 << setw(10) << total << "\n";

		    cout << "\nProduct bought successfully!";
		}
		else
		{
		    cout << "\n Not enough stock!";
		}

		break;
	    }
	}

	if (!found)
 {
	    cout << "\n Product ID not found!";
	}

	cout << "\nBuy another? (y/n): ";
	cin >> choice;

    }
while (choice == 'y' || choice == 'Y');

    if (!anyPurchase)
    {
	cout << "\n No valid purchase. Bill not generated.";
	bill.close();
	temp.close();
	remove("current_bill.txt");
	return;
    }

    cout << "\nEnter Mode of Payment (Cash/NetBanking/UPI): ";
    cin >> mode;

    bill << "Payment Mode: " << mode << "\n";
    temp << "Payment Mode: " << mode << "\n";

    if (strcmpi(mode, "UPI") == 0)
 {
	int valid;
	do
{
	    cout << "Enter UPI ID: ";
	    cin >> upi;
	    valid = 0;

	    for (int i = 0; upi[i] != '\0'; i++)
{
		if (upi[i] == '@') {
		    valid = 1;
		    break;
		}
	    }

	    if (!valid)
		cout << "\n Invalid UPI ID! Try again.\n";

	}
while (!valid);

	bill << "UPI ID: " << upi << "\n";
	temp << "UPI ID: " << upi << "\n";
    }

    bill << "--------------------------------------------------\n";
    bill << "Total Amount: Rs. " << totalAmount << "\n";
    bill << "Thank you " << username << " for shopping!\n\n";

    temp << "--------------------------------------------------\n";
    temp << "Total Amount: Rs. " << totalAmount << "\n";
    temp << "Thank you " << username << " for shopping!\n";

    bill.close();
    temp.close();
    file.close();

      cout << "\n\n---------------- YOUR BILL -----------------\n";
    ifstream show("current_bill.txt");
    char ch;
    while (show.get(ch))
	cout << ch;
    show.close();
}
void generateReport()
{
    Material m;
    ifstream fin("material.dat", ios::binary);
    ofstream report("report.txt");

    if (!fin || !report)
 {
	cout << "\nError opening file for report generation.\n";
	return;
    }
struct date d;
    struct time t;
    getdate(&d);
    gettime(&t);

    report << "============== Building Material Stock Report ==============\n";
    cout   << "============== Building Material Stock Report ==============\n";
    report << "ID"
	   << setw(10)<<"Name"
	   << setw(10)<<"Qty"
	   << setw(10)<<"Unit"
	   << setw(15)<<"Cost/Unit"
	   << setw(16)<<"Total Cost\n";
    report << "------------------------------------------------------------------\n";
    cout   << "ID"
	   << setw(10)<<"Name"
	   << setw(10)<<"Qty"
	   << setw(10)<<"Unit"
	   << setw(15)<<"Cost/Unit"
	   << setw(20)<<"Total Cost\n";
    cout   << "------------------------------------------------------------------\n";


    float grandTotal = 0;
    int count = 0;

	    while (fin.read((char*)&m, sizeof(m)))
 {
	report << m.getid()
	       << setw(10)<< m.getName()
	       << setw(10)<< m.getqty()
	       << setw(13)<< m.getUnit()
	       << setw(17)<< m.getCost()
	       << setw(20)<< (m.getCost() * m.getqty()) << "\n";
	   cout<< m.getid()
	       << setw(10)<< m.getName()
	       << setw(10)<< m.getqty()
	       << setw(13)<< m.getUnit()
	       << setw(11)<< m.getCost()
	       << setw(20)<< (m.getCost() * m.getqty()) << "\n";

	grandTotal += (m.getCost() * m.getqty());
	count++;
    }

    report << "----------------------------------------------------------\n";
    report << "Total Products: " << count << "\n";
    report << "Grand Total Value: Rs. " << grandTotal << "\n";
    report << "Report Generated On: "
	   <<int( d.da_day) << "/" << int(d.da_mon) << "/" << int(d.da_year)
	   << "  at  "
	   << int(t.ti_hour) << ":" << int(t.ti_min) << ":" << int(t.ti_sec) << "\n";
    cout   <<"------------------------------------------------------------------\n";
    cout   <<"Total Products: " << count << "\n";
    cout   << "Grand Total Value: Rs. " << grandTotal << "\n";
    cout   << "Report Generated On: "
	   <<int( d.da_day) << "/" << int(d.da_mon) << "/" << int(d.da_year)
	   << "  at  "
	   << int(t.ti_hour) << ":" << int(t.ti_min) << ":" << int(t.ti_sec) << "\n";



    fin.close();
    report.close();

    cout << "\nReport generated successfully.\n";
}
 void viewAllBills()
{
    clrscr();
    ifstream fin("bill.txt");

    if (!fin || fin.peek() == EOF)
    {
	cout << "\nNo bills found!";
	getch();
	return;
    }

    char line[200];
    char billID[10] = "-", date[15] = "-", time[10] = "-", customer[30] = "-", payment[20] = "-", amount[20] = "-";
    int inBill = 0;

    cout << "\n======================== BILL REGISTER (SUMMARY TABLE) ========================\n";
    cout << setw(10) << "Bill ID"
	 << setw(14) << "Date"
	 << setw(12)  << "Time"
	 << setw(17) << "Customer"
	 << setw(12) << "Payment"
	 << setw(14) << "Amount (Rs.)" << endl;
    cout << "-------------------------------------------------------------------------------\n";

    while (fin.getline(line, 200))
    {
	if (strstr(line, "---------------------- BILL ----------------------"))
	{

	    inBill = 1;
	    strcpy(billID, "-");
	    strcpy(date, "-");
	    strcpy(time, "-");
	    strcpy(customer, "-");
	    strcpy(payment, "-");
	    strcpy(amount, "-");
	}
	else if (inBill && strstr(line, "Bill ID:"))
	{
	    sscanf(line, "Bill ID: %s", billID);
	}
	else if (inBill && strstr(line, "Date:"))
	{
	    sscanf(line, "Date: %s", date);
	}
	else if (inBill && strstr(line, "Time:"))
	{
	    sscanf(line, "Time: %s", time);
	}
	else if (inBill && strstr(line, "Customer Name:"))
	{
	    strcpy(customer, line + strlen("Customer Name: "));
	}
	else if (inBill && strstr(line, "Payment Mode:"))
	{
	    strcpy(payment, line + strlen("Payment Mode: "));
	}
	else if (inBill && strstr(line, "Total Amount: Rs."))
	{
	    strcpy(amount, line + strlen("Total Amount: Rs. "));

	       cout << setw(10) << billID
		 << setw(14) << date
		 << setw(9)  << time
		 << setw(20) << customer
		 << setw(12) << payment
		 << setw(14) << amount << endl;

	    inBill = 0;
	}
    }

    fin.close();

    cout << "\nPress any key to return to menu...";
    getch();
}
void admin_menu()
{
    char username[20];
    char password[20];
    char ch;
    int i = 0;
    clrscr();

    cout << "\n\t\t WELCOME TO ADMIN MENU LOGIN TO PROCEED" << endl;
    cout << "Enter username: ";
    cin >> username;

    cout << "\nEnter password: ";

    while (1)
    {
	ch = getch();
	if (ch == 13)
	{
	    password[i] = '\0';
	    break;
	}
	else if (ch == 8 && i > 0)
	{
	    cout << "\b \b";
	    i--;
	}
	else if (i < 19)
	{
	    password[i++] = ch;
	    cout << "*";
	}
    }

    if ((strcmp(username, "stockadmin") == 0 && strcmp(password, "BMMS@2026") == 0))
    {
	cout << "\n\nLogged in SUCCESSFULLY!" << endl;
	cout << "\n\t* * * WELCOME TO ADMIN MENU * * * ";
	delay(1000);
	clrscr();

	int choice;
	char choiceStr[10];

	do
	{
	    cout << "\n\t\t======= Admin Menu =======";
	    cout << "\n1. Add New Stock";
	    cout << "\n2. Show All Stocks";
	    cout << "\n3. Delete stock";
	    cout << "\n4. Low stock alert";
	    cout << "\n5. Purchase stock";
	    cout << "\n6. Generate report";
	    cout << "\n7. View All Bills Generated";
	    cout << "\n8. Return to Main Menu";
	    cout << "\n=> Enter your choice: ";

 fflush(stdin);

	    cin >> choiceStr;

	    if (strlen(choiceStr) != 1 || !isdigit(choiceStr[0]))
	    {
		cout << "\nInvalid input! Please enter a number between 1 and 9.";
		getch();
		continue;
	    }


	    choice = choiceStr[0] - '0';

	    switch (choice)
	    {
		case 1:
		    addStocks();
		    break;
		case 2:
		    showStocks();
		    break;
		case 3:
		    deleteStocks();
		    break;
		case 4:
		    lowStockAlert();
		    break;
		case 5:
		    purchase();
		    break;
		case 6:
		    generateReport();
		    break;
		case 7:
		    viewAllBills();
		    break;
		case 8:
		    cout << "\nReturning to main menu...";
		    break;
		default:
		    cout << "\nInvalid choice!";
		    getch();
	    }
	}
	while (choice != 8);
    }
    else
    {
	cout << "\n!Invalid Name or Password!";
	getch();
    }
}
void user_menu()
{
    cout << "\n\t\t***WELCOME TO USER MENU***";
    int choice2;
    char choiceStr[10];

    do
    {
	cout << "\n\t\t\t***USER MENU***";
	cout << "\n Press 1 to view all stock";
	cout << "\n Press 2 to buy stock";
	cout << "\n Press 3 to return to MAIN MENU";
	cout << "\n => Enter your choice: ";

	cin >> choiceStr;

	if (strlen(choiceStr) != 1 || !isdigit(choiceStr[0]))
	{
	    cout << "\nInvalid input! Please enter a number between 1 and 3.";
	    getch();
	    continue;
	}

	choice2 = choiceStr[0] - '0';

	switch (choice2)
	{
	    case 1:
	       //	showStocks();
	       user_display();
		break;
	    case 2:
		buy();
		break;
	    case 3:
		cout << "Returning to Main Menu...";
		break;
	    default:
		cout << "\nINVALID CHOICE";
		getch();
	}
    }
    while (choice2 != 3);
}
};
int isDuplicateName(const char* pname)
{
    Material m;
    ifstream fin("material.dat", ios::binary);
    while (fin.read((char*)&m, sizeof(m)))
    {
	if (strcmpi(m.getName(), pname) == 0)
	{
	    fin.close();
	    return 1;
	}
    }
    fin.close();
    return 0;
}

void main()
{
    clrscr();
    srand(time(0));
    StockManager m2;
    int choice1;
    char choiceStr[10];

    do
{
    clrscr();
    cout << "\n\t\t*****************************************\n";
    cout << "\t\tBUILDING MATERIAL STOCK MANAGEMENT SYSTEM\n";
    cout << "\t\t*****************************************\n";
    cout << "\n\t\t\t\t***MAIN MENU***";
    cout << "\n press 1 for admin menu";
    cout << "\n press 2 for user menu";
    cout << "\n press 3 to exit";
    cout << "\n enter your choice: ";

    cin >> choiceStr;

    if (strlen(choiceStr) != 1 || !isdigit(choiceStr[0]))
    {
	cout << "\nInvalid input! Please enter a number between 1 and 3.\n";
	getch();
	continue;
    }

    choice1 = choiceStr[0] - '0';

    switch(choice1)
    {
	case 1:
	    m2.admin_menu();
	    break;
	case 2:
	    m2.user_menu();
	    break;
	case 3:
	    cout << "\nExiting program...";
	    break;
	default:
	    cout << "\nInvalid choice!";
	    getch();
    }
}
while (choice1 != 3);
    getch();
}
