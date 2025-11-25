#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    struct Patient *next;
};

struct Patient *head = NULL;

// Helper to remove newline from fgets
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Add new patient
void addPatient() {
    struct Patient *newP = (struct Patient *)malloc(sizeof(struct Patient));

    printf("Enter Patient ID: ");
    scanf("%d", &newP->id);
    getchar();  // clear buffer

    printf("Enter Name: ");
    fgets(newP->name, 50, stdin);
    removeNewline(newP->name);

    printf("Enter Age: ");
    scanf("%d", &newP->age);
    getchar();  // clear buffer

    printf("Enter Disease: ");
    fgets(newP->disease, 50, stdin);
    removeNewline(newP->disease);

    newP->next = head;
    head = newP;

    printf("\nPatient Added Successfully.\n");
}

// Display patients
void displayPatients() {
    if (head == NULL) {
        printf("No patient records found.\n");
        return;
    }

    struct Patient *temp = head;
    printf("\n--- Patient Records ---\n");

    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Disease: %s\n", temp->disease);
        printf("------------------------\n");

        temp = temp->next;
    }
}

// Search patient
void searchPatient() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    struct Patient *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nPatient Found:\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Disease: %s\n", temp->disease);
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

// Delete patient
void deletePatient() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    struct Patient *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Patient Deleted Successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

// Update patient
void updatePatient() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    getchar(); // clear buffer

    struct Patient *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter new name: ");
            fgets(temp->name, 50, stdin);
            removeNewline(temp->name);

            printf("Enter new age: ");
            scanf("%d", &temp->age);
            getchar();

            printf("Enter new disease: ");
            fgets(temp->disease, 50, stdin);
            removeNewline(temp->disease);

            printf("Record Updated Successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Update Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // buffer clear

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: updatePatient(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
