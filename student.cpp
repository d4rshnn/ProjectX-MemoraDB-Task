#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

// Maximum students
const int MAX_STUDENTS = 100;

// Student database
Student students[MAX_STUDENTS];

// Current student count
int studentCount = 0;

// Find student index by name
int findStudent(const char name[])
{
    for(int i = 0; i < studentCount; i++)
    {
        if(strcmp(students[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

// Add a new submission
void addSubmission(const char name[], const char problem[], int date)
{
    int index = findStudent(name);

    // Create student if not found
    if(index == -1)
    {
        index = studentCount;

        strcpy(students[index].name, name);
        students[index].latest = NULL;

        studentCount++;
    }

    // Create new submission
    Submission* newSubmission = new Submission;

    strcpy(newSubmission->problem, problem);
    newSubmission->date = date;

    // Link to previous submission
    newSubmission->prev = students[index].latest;

    // Update latest pointer
    students[index].latest = newSubmission;
}

// Get latest submission of a student
void getLatestSubmission(const char name[])
{
    int index = findStudent(name);

    if(index == -1)
    {
        cout << "Student not found" << endl;
        return;
    }

    if(students[index].latest == NULL)
    {
        cout << "No submissions found" << endl;
        return;
    }

    cout << "Latest Submission" << endl;
    cout << "Problem: "
         << students[index].latest->problem
         << endl;

    cout << "Date: "
         << students[index].latest->date
         << endl;
}

// Show submission history
void showHistory(const char name[])
{
    int index = findStudent(name);

    if(index == -1)
    {
        cout << "Student not found" << endl;
        return;
    }

    Submission* current = students[index].latest;

    if(current == NULL)
    {
        cout << "No submissions found" << endl;
        return;
    }

    cout << "Submission History" << endl;

    while(current != NULL)
    {
        cout << "Problem: "
             << current->problem
             << " Date: "
             << current->date
             << endl;

        current = current->prev;
    }
}

// Find latest submission before a date
void findLatestBeforeDate(const char name[], int date)
{
    int index = findStudent(name);

    if(index == -1)
    {
        cout << "Student not found" << endl;
        return;
    }

    Submission* current = students[index].latest;

    while(current != NULL)
    {
        if(current->date <= date)
        {
            cout << "Latest Submission Before Date" << endl;
            cout << "Problem: "
                 << current->problem
                 << endl;

            cout << "Date: "
                 << current->date
                 << endl;

            return;
        }

        current = current->prev;
    }

    cout << "No submission found before given date" << endl;
}