#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    int choice;

    while(true)
    {
        cout << "\n===== MemoraDB Task =====" << endl;
        cout << "1. Add Submission" << endl;
        cout << "2. Get Latest Submission" << endl;
        cout << "3. Show Submission History" << endl;
        cout << "4. Find Latest Submission Before Date" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            char name[50];
            char problem[100];
            int date;

            cout << "Student Name: ";
            cin >> name;

            cout << "Problem Name: ";
            cin >> problem;

            cout << "Date (DDMMYYYY): ";
            cin >> date;

            addSubmission(name, problem, date);
        }
        else if(choice == 2)
        {
            char name[50];

            cout << "Student Name: ";
            cin >> name;

            getLatestSubmission(name);
        }
        else if(choice == 3)
        {
            char name[50];

            cout << "Student Name: ";
            cin >> name;

            showHistory(name);
        }
        else if(choice == 4)
        {
            char name[50];
            int date;

            cout << "Student Name: ";
            cin >> name;

            cout << "Date (DDMMYYYY): ";
            cin >> date;

            findLatestBeforeDate(name, date);
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}