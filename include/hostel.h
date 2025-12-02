#ifndef HOSTEL_H
#define HOSTEL_H

#define MAX_STUDENTS 100

struct Student{
    int id;
    char name[50];
    int roomNumber;
};

//Function declarations
void addStudent();
void viewStudents();
void searchByRoom();
void leaveRoom();
int isRoomTaken(int);
void update_Student_detail();
void saveToFile();

//Global variables
extern struct Student students[MAX_STUDENTS];
extern int count;

#endif
