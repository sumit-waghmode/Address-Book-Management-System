# 📒 Address Book Management System

## 1. Project Overview
The Address Book Management System is a menu-driven console application developed using the C programming language. It is designed to manage contact information efficiently by providing operations such as adding, searching, editing, deleting, and displaying contacts.

The application uses structures, arrays, functions, pointers, and file handling to manage contact records. It stores contact information permanently in a CSV file so that records can be accessed even after restarting the application.

## 2. Project Objectives
- To develop a contact management application using C.
- To understand modular programming and function implementation.
- To implement CRUD operations.
- To manage records using structures and arrays.
- To understand file handling for permanent data storage.
- To improve logical thinking and problem-solving skills.

## 3. Features

### Add Contact
- Add new contact details.
- Store name, phone number, and email ID.
- Validate user input.
- Prevent duplicate phone numbers.

### Search Contact
- Search contacts using name.
- Search contacts using phone number.
- Search contacts using email ID.
- Display matching contact information.

### Edit Contact
- Search for an existing contact.
- Select the required contact.
- Update name, phone number, or email ID.
- Validate updated information.

### Delete Contact
- Search and select a contact.
- Display selected contact details.
- Ask for deletion confirmation.
- Remove the selected contact from the Address Book.

### List All Contacts
- Display all stored contacts.
- Show records in a structured table.
- Display serial number, name, phone number, and email ID.
- Display the total number of contacts.

### Save and Exit
- Save contact records into a CSV file.
- Preserve records for future use.
- Exit the application after successful saving.

## 4. Input Validation

### Phone Number Validation
- Accept exactly 10 digits.
- Allow only numeric characters.
- Prevent duplicate phone numbers.

### Email ID Validation
- Must contain exactly one '@' symbol.
- Must contain '.com'.
- Must not start or end with '@'.
- Accept lowercase characters only.
- Spaces are not allowed.

## 5. Technologies Used
- Programming Language: C
- Compiler: GCC
- Code Editor: Visual Studio Code
- Data Storage: CSV File

## 6. C Programming Concepts Implemented
- Structures and Arrays
- User-defined Functions
- Function Declaration and Definition
- Pointers and Pointer Arguments
- Conditional Statements
- Loops and Switch Statements
- String Handling Functions
- File Handling
- Searching and Data Validation
- Modular Programming

## 7. Data Structures
The project uses two main structures:

**Contact Structure**
- Name
- Phone Number
- Email ID

**AddressBook Structure**
- Array of contact records
- Contact count
- Search result index array
- Search result count

## 8. File Handling
The application uses a CSV file named `database.csv` to store contact information.

File handling operations include:
- Loading existing contacts when the application starts.
- Writing contact records into the CSV file.
- Saving updated contact information.
- Maintaining records between program executions.

## 9. Project Structure
```text
AddressBook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── database.csv
└── README.md
```

## 10. Compilation and Execution

**Compile the project:**
```bash
gcc *.c -o addressbook
```

**Run on Windows:**
```bash
addressbook.exe
```

**Run on Linux:**
```bash
./addressbook
```

## 11. Learning Outcomes
- Improved understanding of C programming fundamentals.
- Gained practical experience with structures and arrays.
- Learned modular programming using multiple functions.
- Improved understanding of pointers.
- Implemented CRUD operations.
- Practiced string manipulation and validation.
- Learned file reading and writing operations.
- Understood CSV-based data storage.
- Improved debugging and logical thinking.
- Developed a complete menu-driven application.

## 12. Future Enhancements
- Implement advanced sorting options.
- Improve input validation and error handling.
- Add additional search filters.
- Introduce a graphical user interface.
- Improve data storage and security.

## 13. Author
**Sumit Waghmode**

Electronics and Telecommunication Engineering

## 14. Acknowledgement
This project was developed as part of my C programming learning journey to gain practical experience in modular programming, data structures, file handling, and problem-solving.

⭐ Thank you for visiting my project!