#include "addressbook.h"

int main() 
{
    // Integer variable to store the user's menu choice
    int choice;

    // Declare and initialize the AddressBook structure
    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;

    // Load previously saved contacts from the file into the address book
    load_contacts_from_file(&addressBook);

    // Display the address book menu repeatedly until the user selects Exit
    do
{
    printf(BLUE"\n");
    printf("============================================\n");
    printf("          ADDRESS BOOK MANAGEMENT           \n");
    printf("============================================\n"RESET);

    printf(CYAN"\n              MAIN MENU\n"RESET);
    printf("--------------------------------------------\n");

    printf(GREEN"  [1] "RESET" Add New Contact\n");
    printf(GREEN"  [2] "RESET" Search Contact\n");
    printf(GREEN"  [3] "RESET" Edit Contact\n");
    printf(GREEN"  [4] "RESET" Delete Contact\n");
    printf(GREEN"  [5] "RESET" List All Contacts\n");
    printf(RED"  [6] "RESET" Save & Exit\n");

    printf("--------------------------------------------\n");
    printf(YELLOW"  Enter your choice: "RESET);

    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
        case 1:
            add_contact(&addressBook);
            break;

        case 2:
            search_contact(&addressBook);
            break;

        case 3:
            edit_contact(&addressBook);
            break;

        case 4:
            delete_contact(&addressBook);
            break;

        case 5:
            list_contacts(&addressBook);
            break;

        case 6:
            save_contacts_to_file(&addressBook);
            printf(GREEN"\n  Saving and Exiting...\n");
            printf("  Contacts Saved Successfully!\n"RESET);
            break;

        default:
            printf(RED"\n  Invalid choice! Please try again.\n"RESET);
    }

} while (choice != 6);

    return 0;
}