#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contact information
typedef struct {
    char *name;
    char *phone;
} Contact;

// Function to initialize a contact
void initContact(Contact *contact, const char *name, const char *phone) {
    contact->name = strdup(name);
    contact->phone = strdup(phone);
}

// Function to print a contact
void printContact(Contact *contact) {
    printf("Name: %s, Phone: %s\n", contact->name, contact->phone);
}

// Function to free memory used by a contact
void freeContact(Contact *contact) {
    free(contact->name);
    free(contact->phone);
}

int main() {
    Contact *contacts = NULL;
    int numContacts = 0;
    int capacity = 0;

    int choice;
    do {
        printf("\n1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100];
                char phone[100];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);

                // Check if array needs resizing
                if (numContacts == capacity) {
                    capacity = (capacity == 0) ? 1 : capacity * 2;
                    contacts = (Contact *)realloc(contacts, capacity * sizeof(Contact));
                }

                // Initialize new contact
                initContact(&contacts[numContacts], name, phone);
                numContacts++;

                printf("Contact added successfully!\n");
                break;
            }
            case 2:
                if (numContacts == 0) {
                    printf("No contacts to display.\n");
                } else {
                    printf("Contacts:\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("%d. ", i + 1);
                        printContact(&contacts[i]);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    // Free memory before exiting
    for (int i = 0; i < numContacts; i++) {
        freeContact(&contacts[i]);
    }
    free(contacts);

    return 0;
}