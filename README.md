# Building Material Stock Management System

A console-based inventory and billing management system developed in Turbo C++ for managing building-material stock, customer purchases, billing, low-stock alerts, and stock reports.

## 📸 Project Screenshots

### Main Menu

![Main Menu](screenshots/01-main-menu.png)

### Admin Menu

![Admin Menu](screenshots/02-admin-menu.png)

### Stock & Low-Stock Alert

![Stock and Low Stock Alert](screenshots/03-stock-and-low-stock-alert.png)

### Stock Report

![Stock Report](screenshots/04-stock-report.png)

### Customer Bill

![Customer Bill](screenshots/05-customer-bill.png)

## Features

- Admin and User modules
- Admin login with masked password input
- Add new building materials
- Automatic product ID generation
- View available stock
- Update stock records
- Delete stock records
- Low-stock alerts
- Purchase/add stock
- Customer purchase and billing
- Cash, NetBanking, and UPI payment options
- Automatic bill IDs
- Bill register/summary
- Stock valuation report
- Input validation
- Binary file handling using `material.dat`
- Text-file reports and bills

## Technology

- C++
- Turbo C++
- File Handling
- Turbo C++/DOS-specific libraries

## Project Structure

```text
Building-Material-Stock-Management-System/
├── README.md
├── building_material_stock_management_system.cpp
└── screenshots/
    ├── 01-main-menu.png
    ├── 02-admin-menu.png
    ├── 03-stock-and-low-stock-alert.png
    ├── 04-stock-report.png
    └── 05-customer-bill.png
```

## Demo Admin Credentials

For this educational/demo version:

- Username: `stockadmin`
- Password: `BMMS@2026`

These are demo credentials for the application and are not intended to represent production-grade authentication.

## Data Files

The application uses runtime files such as:

- `material.dat` — binary stock records
- `bill.txt` — generated bill history
- `current_bill.txt` — current bill display
- `report.txt` — generated stock report

Generated runtime data should generally not be committed unless intentionally included as sample data.

## How the System Works

The application provides separate Admin and User modules.

### Admin

The administrator can manage stock, check low-stock items, add/purchase stock, generate reports, and view bills.

### User

Users can view products, purchase materials, and use the billing/payment functionality.

## Note

This project was developed as a Turbo C++ educational application and uses legacy Turbo C++/DOS-specific headers and functions. It is presented in its original programming environment rather than as a modern C++ application.

## Developer

Academic project — Building Material Stock Management System.
