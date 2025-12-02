#include <stdio.h>
#include <string.h>
#include "hostel.h"

//global variables
struct Student students[MAX_STUDENTS];
int count = 0;

//adding student
void addStudent(){
    if (count >= MAX_STUDENTS){
        printf("Hostel is full!\n");
        return;
    }
    int room;
    printf("Enter Room Number: ");
    scanf("%d", &room);
    if (isRoomTaken(room)){
        printf("Room already occupied! Try another room.\n");
        return;
    }
    students[count].roomNumber = room;
    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);

    getchar(); //clear newline
    printf("Enter Name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';//remove new line

    count++;
    saveToFile();
    printf("Student added successfully!\n");
}

//viewing all students
void viewStudents(){
    if (count == 0){
        printf("No record found.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++){
        printf("ID: %d | Name: %s | Room: %d\n",
               students[i].id, students[i].name, students[i].roomNumber);
    }
}

//finding the detail of the student of a given room.
void searchByRoom(){
    int room;
    printf("Enter room number to search: ");
    scanf("%d", &room);
    for (int i = 0; i < count; i++){
        if (students[i].roomNumber == room){
            printf("Student Found:\nID=%d\nName=%s\n",
                   students[i].id, students[i].name);
            return;
        }
    }
    printf("No student found in this room.\n");
}

//student leaving a room.
void leaveRoom(){
    int ID;
    printf("Enter Student ID to remove: ");
    scanf("%d", &ID);
    int index = -1;
    for (int i = 0; i < count; i++){
        if (students[i].id == ID){
            index = i;
            break;
        }
    }
    if (index == -1){
        printf("No student found with this ID.\n");
        return;
    }
    for (int i = index; i < count - 1; i++){
        students[i] = students[i + 1];
    }
    count--;
    saveToFile();
    printf("Student successfully removed.\n");
}

//finding if the room is already occupied
int isRoomTaken(int room){
    for (int i = 0; i < count; i++){
        if (students[i].roomNumber == room){
        return 1;
        }
    }
    return 0;
}

//updating student detail
void update_Student_detail(){
    int ID;
    printf("Enter Student ID to update: ");
    scanf("%d", &ID);
    for (int i = 0; i < count; i++){
        if (students[i].id == ID){
            printf("\n--- Current Details ---\n");
            printf("ID   : %d\n", students[i].id);
            printf("Name : %s\n", students[i].name);
            printf("Room : %d\n", students[i].roomNumber);

            int choice;
            printf("\nChoose what to update:\n");
            printf("1. Update Name\n");
            printf("2. Update Room\n");
            printf("3. Update Both\n");
            printf("Enter option: ");
            scanf("%d", &choice);

            if (choice == 1 || choice == 3){
                getchar();//clear new line
                printf("Enter new name: ");
                fgets(students[i].name, sizeof(students[i].name), stdin);
                students[i].name[strcspn(students[i].name, "\n")] = '\0';//remove new line
                printf("Name updated.\n");
            }
            if (choice == 2 || choice == 3){
                int newRoom;
                printf("Enter new room number: ");
                scanf("%d", &newRoom);
                if (isRoomTaken(newRoom) && students[i].roomNumber != newRoom){
                    printf("Room already taken!\n");
                    return;
                }
                students[i].roomNumber = newRoom;
                printf("Room updated.\n");
            }
            saveToFile();
            printf("Student details updated successfully.\n");
            return;
        }
    }
    printf("No student found with ID %d\n", ID);
}

//saving information to file
void saveToFile(){
    FILE *fp = fopen("Hostel.txt", "w");
    if (fp == NULL){
        printf("Error: Could not open file.\n");
        return;
    }
    for (int i = 0; i < count; i++){
        fprintf(fp, "%d %s %d\n",
                students[i].id,
                students[i].name,
                students[i].roomNumber);
    }
    fclose(fp);
}
