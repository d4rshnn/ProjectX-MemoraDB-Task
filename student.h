#ifndef STUDENT_H
#define STUDENT_H

struct Submission
{
    char problem[100];
    int date;

    Submission* prev;
};

struct Student
{
    char name[50];

    Submission* latest;
};

// Functions
void addSubmission(const char name[], const char problem[], int date);

void getLatestSubmission(const char name[]);

void showHistory(const char name[]);

void findLatestBeforeDate(const char name[], int date);

#endif