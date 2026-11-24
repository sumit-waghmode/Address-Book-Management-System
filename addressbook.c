#include "addressbook.h"

//                                                           ADD CONTACTS 

// Function definition for adding contacts
void add_contact(struct AddressBook *addressBook)
{
    // Declare variables to store user input
    char user_name[50];
    char phone_no[11];
    char email_id[50];

    // Variables to store validation results
    int ret_phone_no;
    int ret_email;

    // Check whether the Address Book has reached maximum capacity
    if(addressBook->contactCount >= 100)
    {
        printf(RED"Address Book is full\n"RESET);
        return;
    }

// NAME
    // Read contact name from the user
    printf("Enter name : ");
    scanf(" %[^\n]", user_name);

// PHONE NUMBER
    // Read phone number from user
    do
    {
        printf("Enter phone number : ");
        scanf(" %[^\n]", phone_no);
    
        // Call the phone number validation function
        ret_phone_no = validate_phone_num(addressBook, phone_no);

    } while(ret_phone_no == 0);

// EMAIL
    // Read email id from user
    do
    {
        printf("Enter email I'd : ");
        scanf(" %[^\n]", email_id);

        // Call the email validation function
        ret_email = validate_email_id(addressBook, email_id);

    } while(ret_email == 0);

// FOR COPYING DATA
    // Check whether both phone number and email are valid
    if(ret_email == 1 && ret_phone_no == 1)
    {
        // Copy entered name into the Address Book
        strcpy(addressBook->contacts[addressBook->contactCount].name, user_name);

        // Copy entered phone number into the Address Book
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone_no);

        // Copy entered email into the Address Book
        strcpy(addressBook->contacts[addressBook->contactCount].email, email_id);

        // Increase contact count after successfully saving the contact
        addressBook->contactCount++;

        // Display success message
        printf(GREEN "<<< Contact saved successfully >>>\n" RESET);
    }
}

//                                                          SEARCH CONTACTS

// Function definition for searching contacts in the Address Book
void search_contact(struct AddressBook *addressBook)
{
    int choice;

    do
    {
        // Display search menu
        printf(BLUE"\n");
        printf("============================================\n");
        printf("               SEARCH CONTACT               \n");
        printf("============================================\n"RESET);

        printf(CYAN"\n             SEARCH OPTIONS\n"RESET);
        printf("--------------------------------------------\n");

        printf(GREEN"  [1] "RESET" Search by Name\n");
        printf(GREEN"  [2] "RESET" Search by Phone Number\n");
        printf(GREEN"  [3] "RESET" Search by Email ID\n");

        printf("--------------------------------------------\n");
        printf(YELLOW"  Enter your choice: "RESET);

        // Read user's choice
        scanf(" %d", &choice);
        getchar();

        printf("\n");

        // Perform search operation
        switch (choice)
        {
            case 1:
                search_by_name(addressBook);
                break;

            case 2:
                search_by_phone_no(addressBook);
                break;

            case 3:
                search_by_email_id(addressBook);
                break;

            default:
                printf(RED"  Invalid choice! Please select 1 to 3.\n"RESET);
                break;
        }

    } while(choice < 1 || choice > 3);
}

//                                                               EDIT CONTACTS

// Function definition for editing contacts in the Address Book
void edit_contact(struct AddressBook *addressBook)
{
    int choice;
    int index_of_srno;
    int sr_no;
    int index_to_edit;

    // Search for contacts in the Address Book
    search_contact(addressBook);

    // Return if no matching contact is found
    if(addressBook->ir_size == 0)
    {
        //printf(RED"Contact not found\n"RESET);
        return;
    }

    // Ask the user to select the serial number of the contact
    printf("Enter Sr no. contact to edit : \n");
    scanf(" %d",&sr_no);

    // Validate the entered serial number
    if(sr_no < 1 || sr_no > addressBook->ir_size)
    {
        printf(RED"Entered incorrect Sr no.\n\n"RESET);
        return;
    }

    // Convert serial number into array index
    index_of_srno = sr_no - 1;

    // Get the actual contact index from search results
    index_to_edit = addressBook->index_record[index_of_srno];

    // Display edit menu repeatedly until the user exits
    do
    {
        printf("What you want to edit : \n");
        printf("1. Name : \n");
        printf("2. Phone number : \n");
        printf("3. Email I'd : \n");
        printf("4. Exit\n");
        printf("Enter your choice : ");

        scanf(" %d",&choice);
        printf("\n");

        // Perform editing based on user's choice
        switch(choice)
        {
            case 1:
                edit_by_name(addressBook, index_to_edit);
                break;

            case 2:
                edit_by_phone_no(addressBook, index_to_edit);
                break;

            case 3:
                edit_by_email(addressBook, index_to_edit);
                break;

            case 4:
                printf(CYAN"       Exiting...\n"RESET GREEN"<<< Exited Successfully >>>\n"RESET);
                return;

            default:
                printf(RED"Invalid Choice\n"RESET);
                break;
        }

    } while(1);
}

//                                                              DELETE CONTACTS

// Function definition for deleting contacts from the Address Book
void delete_contact(struct AddressBook *addressBook)
{
    int choice;
    int index_of_srno;
    int sr_no;
    int index_to_delete;

    // Search for contacts in the Address Book
    search_contact(addressBook);

    // Return if no matching contact is found
    if(addressBook->ir_size == 0)
    {
        return;
    }

    // Ask the user to select the serial number of the contact
    printf("Enter Sr no. to delete : \n");
    scanf(" %d",&sr_no);

    // Validate the entered serial number
    if(sr_no < 1 || sr_no > addressBook->ir_size)
    {
        printf(RED"Entered incorrect Sr no.\n\n"RESET);
        return;
    }

    // Ask for confirmation before deleting the contact
    printf("Confirm to delete : \n");
    printf(RED"1. Yes\n"RESET GREEN"2. No\n"RESET);
    printf("Enter your choice : ");
    scanf(" %d",&choice);

    if(choice == 2)
    {
        printf(GREEN"Contact not deleted\n"RESET);
        return;
    }

    // Convert serial number into array index
    index_of_srno = sr_no - 1;

    // Get the actual contact index from search results
    index_to_delete = addressBook->index_record[index_of_srno];

    // Shift remaining contacts one position to the left
    for(int i = index_to_delete; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrease the contact count after deletion
    addressBook->contactCount--;

    printf(GREEN"<<< CONTACT DELETED SUCCESSFULLY >>>\n"RESET);
}

//                                                                LIST CONTACT
// Function definition for displaying all contacts in the Address Book
void list_contacts(struct AddressBook *addressBook)
{
    printf("\n");

    // Check whether the Address Book is empty
    if(addressBook->contactCount == 0)
    {
        printf(RED"\n  No contacts found!\n"RESET);
        return;
    }

    // Display table heading
    printf(BLUE);
    printf("===============================================================\n");
    printf("                     CONTACT DIRECTORY                          \n");
    printf("===============================================================\n");
    printf(RESET);

    // Display table column headings
    printf(CYAN);
    printf("+------+----------------------+-----------------+--------------------------------+\n");
    printf("| Sr   | Name                 | Phone No        | Email                          |\n");
    printf("+------+----------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Display all contact information
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf(YELLOW);
        printf("| %-4d | %-20.20s | %-15.15s | %-30.30s |\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
        printf(RESET);
    }

    // Display bottom border
    printf(CYAN);
    printf("+------+----------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Display total number of contacts
    printf(GREEN"\n  Total Contacts: %d\n"RESET,
           addressBook->contactCount);

    printf("\n");
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//                                                          CHECK PHONE NUMBER VALIDATIONS

// Function definition for validating phone numbers
int validate_phone_num(struct AddressBook *addressBook, char* phone_no)
{
    int length = strlen(phone_no);
    int i = 0;

    // Check whether the phone number contains exactly 10 digits
    if(length != 10)
    {
        printf(RED"Enter must be 10 digits\n"RESET);
        return 0;
    }

    // Check whether all characters are digits (0-9)
    while(phone_no[i] != '\0')
    {
        if(phone_no[i] >= '0' && phone_no[i] <= '9')
        {
            i++;
        }
        else
        {
            printf(RED"Phone number must be only digit\n"RESET);
            return 0;
        }
    }

    // Check whether the phone number already exists in the Address Book
    i = 0;
    while(i < addressBook->contactCount)
    {
        if(strcmp(addressBook->contacts[i].phone, phone_no) == 0)
        {
            printf(RED"Phone number already exist\n"RESET);
            return 0;
        }
        else
            i++;
    }

    // Return 1 if the phone number passes all validation checks
    return 1;
} 


//                                                         VALIDATE EMAILD ID 

// Function definition for validating email IDs
int validate_email_id(struct AddressBook *addressBook, char *email_id)
{
    int length = strlen(email_id);
    int j = 0;
    char com[5] = ".com";
    int count = 0;

    // Check whether @ is present at the beginning or end
    if(email_id[length - 1] == '@' || email_id[0] == '@')
    {
        printf(RED"@ character should not be present at first or last\n"RESET);
        return 0;
    }

    // Check for uppercase letters, spaces and multiple @ characters
    for(int i = 0; i < length; i++)
    {
        if(email_id[i] >= 'A' && email_id[i] <= 'Z')
        {
            printf(RED"Must contain lowercase letters only (no uppercase)\n"RESET);
            return 0;
        }
        else if(email_id[i] == ' ')
        {
            printf(RED"Must not contain space\n"RESET);
            return 0;
        }
        else if(email_id[i] == '@')
            count++;

        if(count > 1)
        {
            printf(RED"@ must appears only one time\n"RESET);
            return 0;
        }
    }

    // Check -the email contains exactly one @ character
    if(count < 1)
    {
        printf(RED"Must contain @\n"RESET);
        return 0;
    }

    // Check whether the email ends with .com
    for(int i = length - 4; i <= length - 1; i++)
    {
        if(email_id[i] != com[j])
        {
            printf(RED"Emaild I'd ends with only '.com'\n"RESET);
            return 0;
        }
        j++;
    }

    // Check whether the email ID already exists in the Address Book
    int i = 0;
    while(i < addressBook->contactCount)
    {
        if(strcmp(addressBook->contacts[i].email, email_id) == 0)
        {
            printf(RED"Email I'd already exist\n"RESET);
            return 0;
        }
        i++;
    }

    // Return 1 if the email passes all validation checks
    return 1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//                                                               SEARCH CONTACTS BY NAME

// Function definition for searching contacts by name
void search_by_name(struct AddressBook *addressBook)
{
    char user_name[50];
    int found = 0;
    int sr_no = 1;

    // Reset search result count
    addressBook->ir_size = 0;

    printf("Enter name : ");
    scanf(" %[^\n]", user_name);

    // Display table header in Cyan
    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf("| %-4s| %-25s | %-15s | %-30s |\n",
           "Sr.no", "Name", "Phone No", "Email");
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Search for matching names in the Address Book
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcasestr(addressBook->contacts[i].name, user_name))
        {
            // Display matching contact details in Yellow
            printf(YELLOW);
            printf("| %-4d | %-25s | %-15s | %-30s |\n",
                   sr_no,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            printf(RESET);

            sr_no++;
            found = 1;

            // Store the actual contact index for edit and delete operations
            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
        }
    }

    // Display bottom border in Cyan
    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Display message if no matching contact is found
    if(found == 0)
    {
        printf(RED "Name not found\n" RESET);
    }
}


//                                                     SEARCH CONTACTS BY PHONE NUMBER

// Function definition for searching contacts by phone number
void search_by_phone_no(struct AddressBook *addressBook)
{
    char phone_no[11];
    int found = 0;
    int sr_no = 1;

    // Reset search result count
    addressBook->ir_size = 0;

    printf("Enter phone number : ");
    scanf(" %[^\n]", phone_no);

    // Check whether the entered phone number contains only digits
    int length = strlen(phone_no);

    for(int i = 0; i < length - 1; i++)
    {
        if(phone_no[i] < 0 || phone_no[i] > 9)
        printf(RED"Phone number must be digit only\n"RESET);
        return;
    }

    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf("| %-4s| %-25s | %-15s | %-30s |\n",
           "Sr.no", "Name", "Phone No", "Email");
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Search for matching phone numbers
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strstr(addressBook->contacts[i].phone, phone_no))
        {
            // Display matching contact details in Yellow
            printf("\033[33m%-4d %-25s %-15s %-30s\033[0m\n", sr_no , addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);

            sr_no++;
            found = 1;

            // Store the actual contact index for edit and delete operations
            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
        }
    }

    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Display message if no matching contact is found
    if(found == 0)
        printf(RED"Phone number not found\n"RESET);
}


//                                                       SEARCH CONTACTS BY EMAIL I'D 


// Function definition for searching contacts by email ID
void search_by_email_id(struct AddressBook *addressBook)
{
    char email_id[50];
    int found = 0;
    int sr_no = 1;

    // Reset search result count
    addressBook->ir_size = 0;

    printf("Enter email i'd : ");
    scanf(" %[^\n]", email_id);

    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf("| %-4s| %-25s | %-15s | %-30s |\n", "Sr.no", "Name", "Phone No", "Email");
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Search for matching email IDs
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcasestr(addressBook->contacts[i].email, email_id))
        {
            // Display matching contact details in Yellow
            printf("\033[33m%-4d %-25s %-15s %-30s\033[0m\n", sr_no , addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);

            sr_no++;
            found = 1;

            // Store the actual contact index for edit and delete operations
            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
        }
    }

    printf(CYAN);
    printf("+------+---------------------------+-----------------+--------------------------------+\n");
    printf(RESET);

    // Display message if no matching contact is found
    if(found == 0)
        printf(RED"Email I'd not found\n"RESET);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//                                                          EDIT CONTACT BY NAME

// Function definition for editing contact name
void edit_by_name(struct AddressBook *addressBook, int index_to_edit)
{
    char new_name[50];

    printf("Enter new name to edit : ");
    scanf(" %[^\n]", new_name);

    // Update the contact name at the selected index
    strcpy(addressBook->contacts[index_to_edit].name, new_name);

    printf(GREEN"<<< Name Changed Successfully >>>\n"RESET);
}


//                                                         EDIT CONTACT BY PHONE NUMBER


// Function definition for editing contact phone number
void edit_by_phone_no(struct AddressBook *addressBook, int index_to_edit)
{
    char new_number[11];
    int ret_phone_num;

    printf("Enter new phone number to edit : ");
    scanf(" %[^\n]", new_number);

    printf("\n");

    // Validate the new phone number
    ret_phone_num = validate_phone_num(addressBook, new_number);

    // Return if the entered phone number is invalid
    if(ret_phone_num == 0)
    {
        //printf("Invalid phone number\n");
        return;
    }

    // Update the phone number at the selected index
    strcpy(addressBook->contacts[index_to_edit].phone, new_number);

    printf(GREEN"<<< Mobile Number Changed Successfully >>>\n"RESET);
}


//                                                     EDIT CONTACT BY EMAIL I'D


// Function definition for editing contact email ID
void edit_by_email(struct AddressBook *addressBook, int index_to_edit)
{
    char new_email_id[50];
    int ret_email;

    printf("Enter new Email I'd : ");
    scanf(" %[^\n]", new_email_id);

    // Validate the new email ID
    ret_email = validate_email_id(addressBook, new_email_id);

    // Return if the entered email ID is invalid
    if(ret_email == 0)
    {
        //printf("Invalid Email I'd\n");
        return;
    }

    // Update the email ID at the selected index
    strcpy(addressBook->contacts[index_to_edit].email, new_email_id);

    printf(GREEN"<<< Email I'd changed successfully >>>\n"RESET);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function definition for saving contacts into a CSV file
void save_contacts_to_file(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv", "w");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf(RED"Unable to open file\n"RESET);
        return;
    }

    // Write all contact details into the file
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
    }

    // Close the file after saving
    fclose(fp);
}

// Function definition for loading contacts from a CSV file
void load_contacts_from_file(struct AddressBook *addressBook)
{
    int ret, i = 0;

    FILE *fp = fopen("database.csv", "r");

    // Check whether the file exists and opened successfully
    if(fp == NULL)
    {
        printf(RED"NO DATA FOUND\n"RESET);
        return;
    }

    // Read contact details from the file until 100 contacts or end of file
    while(i < 100)
    {
        ret = fscanf(fp, " %49[^,],%14[^,],%49[^\n]", addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);

        // Move to the next contact only if all three fields are read
        if(ret == 3)
            i++;
        else
            break;
    }

    // Update the total number of loaded contacts
    addressBook->contactCount = i;

    // Close the file after loading
    fclose(fp);
}
