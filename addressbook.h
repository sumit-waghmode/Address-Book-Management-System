#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

// Macros for colour 
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


// Structure to store individual contact details
struct Contact
{
    char name[50];     // String variable to store name
    char phone[15];    // String variable to store phone number
    char email[50];    // String variable to store email ID
};


// Structure to manage all contacts in the address book
struct AddressBook
{
    struct Contact contacts[100];  // Array to store maximum 100 contacts
    int contactCount;              // Keeps track of the total number of contacts
    int index_record[100];         // Stores the indexes of searched contacts
    int ir_size;                   // Stores the total number of search results
};


// Function declarations for adding contacts and validating contact details

// Function to add a new contact
void add_contact(struct AddressBook *addressBook);

// Function to validate the phone number and check for duplicates
int validate_phone_num(struct AddressBook *addressBook, char *phone_no);

// Function to validate the email ID and check for duplicates
int validate_email_id(struct AddressBook *addressBook, char *email_id);


// Function declarations for searching contacts


// Function to display the search menu
void search_contact(struct AddressBook *addressBook);

// Function to search contacts by name
void search_by_name(struct AddressBook *addressBook);

// Function to search contacts by phone number
void search_by_phone_no(struct AddressBook *addressBook);

// Function to search contacts by email ID
void search_by_email_id(struct AddressBook *addressBook);


// Function declarations for editing contacts


// Function to display the edit menu
void edit_contact(struct AddressBook *addressBook);

// Function to edit contact details using the name
void edit_by_name(struct AddressBook *addressBook, int);

// Function to edit contact details using the phone number
void edit_by_phone_no(struct AddressBook *addressBook, int);

// Function to edit contact details using the email ID
void edit_by_email(struct AddressBook *addressBook, int);


// Function to delete an existing contact
void delete_contact(struct AddressBook *addressBook);


// Function to display all contacts stored in the address book
void list_contacts(struct AddressBook *addressBook);


// Function to save all contacts into a file
void save_contacts_to_file(struct AddressBook *addressBook);

// Function to load previously saved contacts from a file
void load_contacts_from_file(struct AddressBook *addressBook);

#endif