# PharmacyCRM

A Qt-based Customer Relationship Management (CRM) desktop application tailored for pharmacy operations. The system enables efficient management of clients, medicines, employees, and sales receipts with a user-friendly GUI and persistent storage using SQLite.

## 📚 Project Information

**University:** Lebanese American University  
**Course:** COE 415 - Computer Programming II  

**Team Members:**
- **Project Manager:** Elie Joe Farah (202100358)
- **Solutions Architect:** Mohamad Riad El Terek (202100178)
- **Technical Expert & Documentation:** Nour Mikhael (202102809)
- **Presales Engineer:** Taline Zeidan (202104293)

---

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Framework:** Qt 6.9 (Qt Widgets)
- **Database:** SQLite (file-based)
- **Build System:** qmake
- **IDE:** Qt Creator (recommended)

---

## ✨ Features

- Add, view, and manage client records
- Maintain an inventory of medicines
- Record sales receipts associated with clients
- Manage employees and managers with role-based access
- GUI fully built with Qt Designer
- Data persistence via SQLite backend

---

## 🚀 How to Run the Project

### ✅ Prerequisites

1. **Install Qt**:
   - Download from [qt.io/download](https://www.qt.io/download)
   - Use the Qt Online Installer
   - Select **Qt 6.9.0** or higher during installation
   - Ensure **Qt Creator** and a **C++ compiler** (MinGW or Clang) are selected

2. **System Requirements**:
   - Qt 6.9.0 or higher
   - Compatible C++17 compiler (e.g., MinGW for Windows, Clang for macOS)
   - Basic familiarity with Qt Creator

---

### 🪟 For Windows Users

1. Open **Qt Creator**
2. Click **Open Project...** and select `PharmacyCRM.pro`
3. Choose a kit (e.g., MinGW 64-bit Qt 6.9.0)
4. Click **Configure Project**
5. Press the green **Play** button to build and run

---

### 🍎 For macOS Users

1. Open **Qt Creator** (ensure Xcode or Clang is installed)
2. Open `PharmacyCRM.pro`
3. Choose a kit (e.g., Clang Qt 6.9.0)
4. Configure and run the project

**Note:** Make sure `pharmacy.db` has the correct write permissions.

---

## ⚠️ Notes

- If you encounter `.pro.user` errors, ignore and reconfigure the kit
- The database `pharmacy.db` is created locally in the project directory
- Ensure the system has write permissions for database creation

---

## 📁 Folder Structure

To be customized with actual directory structure, e.g.:

<pre>
PharmacyCRM/
├── Headers/         # .h files for each class
├── Sources/         # .cpp files for each module
├── Forms/           # .ui files (Qt Designer)
├── pharmacy.db      # SQLite DB (created at runtime)
└── PharmacyCRM.pro  # Project file
</pre>


---

## 📄 License

This project was developed for academic purposes and is **not intended for commercial distribution**.