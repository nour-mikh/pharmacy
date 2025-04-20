# Pharmacy CRM System

**Lebanese American University**

**Pharmacy Customer Relationship Management System**

**README**  
**COE 415 - Computer Programming II**

**Project Manager:**  
Elie Joe Farah - 202100358

**Solutions Architect :**  
Mohamad Riad El Terek - 202100178

**Technical Expert:**  
Nour Mikhael - 202102809

**Presales Engineer:**  
Taline Zeidan - 202104293

**Prepared by:** Nour Mikhael

---

## Pharmacy Customer Relationship Management System - README

### PharmacyCRM

A Qt-based Customer Relationship Management (CRM) desktop application tailored for pharmacy operations. The system allows pharmacy staff to manage clients, medicines, employees, and sales receipts efficiently with a user-friendly GUI and persistent storage using SQLite.

---

## Technologies Used

● Programming Language: C++  
● Framework: Qt 6.9 (Qt Widgets)  
● Database: SQLite (file-based)  
● Build System: qmake  
● IDE: Qt Creator (Recommended)

---

## Features

● Add, view, and manage client records  
● Maintain an inventory of medicines  
● Record sales receipts associated with clients  
● Manage employees and managers with role-based access  
● GUI built entirely with Qt Designer  
● Data persistence via SQLite backend

---

## How to Run the Project

### Prerequisites

To run this project, you need to have Qt installed on your machine. Qt is a cross-platform development framework that includes everything needed to build and run this application. You can download it by following these steps:

1. Visit the official Qt website: https://www.qt.io/download  
2. Click Download Qt Online Installer for Windows/macOS depending on your system  
3. Install the package and choose the latest available version (e.g., Qt 6.9.0) during setup  
4. Ensure that Qt Creator and at least one C++ compiler toolchain (MinGW or Clang) are selected during installation  

If you do not have a Qt account, you may need to register for a free community account during installation.

● Qt 6.9.0 or higher installed (with Qt Creator)  
● A compatible C++17 compiler (e.g., MinGW for Windows, Clang for macOS)  
● Basic familiarity with using Qt Creator

---

### Step-by-Step Guide

#### For Windows Users:

1. Open Qt Creator  
2. Click Open Project... and select the file `PharmacyCRM.pro`  
3. Choose a kit like MinGW 64-bit Qt 6.9.0 (or similar)  
4. Click Configure Project  
5. Press the green play button to build and launch the app

#### For macOS Users:

1. Open Qt Creator (ensure Xcode or Clang is installed)  
2. Open `PharmacyCRM.pro`  
3. Choose a kit such as Clang (Qt 6.9.0)  
4. Configure and run the project as above

> On macOS, ensure file permissions are set to allow writing a local `pharmacy.db`

---

## Notes

● If `.pro.user` errors appear, ignore and reconfigure the kit  
● All data is saved locally in `pharmacy.db`, created in the project directory  
● Ensure the database file exists or the system has permissions to generate it

---

## Folder Structure - Visible once Qt creator is open

<pre>
PharmacyCRM/
├── Headers/         # .h files for each class
├── Sources/         # .cpp files for each module
├── Forms/           # .ui files (Qt Designer)
├── pharmacy.db      # SQLite DB (created at runtime)
└── PharmacyCRM.pro  # Project file
</pre>

---

## License

This project was created as part of an academic course and is not intended for commercial distribution.
