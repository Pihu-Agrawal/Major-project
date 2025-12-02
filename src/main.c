#include <stdio.h>
#include "hostel.h"

int main(){
    int choice;
    while (1){
        printf("\n===== Hostel Room Allocation System =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student by Room\n");
        printf("4. Leave Room\n");
        printf("5. Update Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchByRoom(); break;
        case 4: leaveRoom(); break;
        case 5: update_Student_detail(); break;
        case 6:
            saveToFile();
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! try again.\n");
        }
    }
}
