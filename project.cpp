
#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;
    float marks;

public:

    // Function to add student details
    void addStudent()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "\nStudent Added Successfully!\n";
    }

    // Function to display student details
    void displayStudent()
    {
        cout << "\n------------------------";
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nMarks: " << marks;

        if (marks >= 90)
            cout << "\nGrade: A";

        else if (marks >= 75)
            cout << "\nGrade: B";

        else if (marks >= 60)
            cout << "\nGrade: C";

        else if (marks >= 40)
            cout << "\nGrade: D";

        else
            cout << "\nGrade: Fail";

        cout << "\n------------------------\n";
    }

    // Function to search student
    bool searchStudent(int r)
    {
        if (rollNo == r)
            return true;

        return false;
    }

    // Function to update student details
    void updateStudent()
    {
        cout << "\nEnter New Name: ";
        cin >> name;

        cout << "Enter New Age: ";
        cin >> age;

        cout << "Enter New Marks: ";
        cin >> marks;

        cout << "\nStudent Details Updated!\n";
    }

    // Function to delete student record
    void deleteStudent()
    {
        rollNo = -1;
    }
};

int main()
{
    Student s[100];

    int count = 0;
    int choice;
    int roll;
    int found;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if (count < 100)
                {
                    s[count].addStudent();
                    count++;
                }
                else
                {
                    cout << "\nStudent Limit Reached!\n";
                }
                break;

            case 2:
                if (count == 0)
                {
                    cout << "\nNo Student Records Found!\n";
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        s[i].displayStudent();
                    }
                }
                break;

            case 3:
                cout << "\nEnter Roll Number to Search: ";
                cin >> roll;

                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (s[i].searchStudent(roll))
                    {
                        s[i].displayStudent();
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    cout << "\nStudent Not Found!\n";

                break;

            case 4:
                cout << "\nEnter Roll Number to Update: ";
                cin >> roll;

                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (s[i].searchStudent(roll))
                    {
                        s[i].updateStudent();
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    cout << "\nStudent Not Found!\n";

                break;

            case 5:
                cout << "\nEnter Roll Number to Delete: ";
                cin >> roll;

                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (s[i].searchStudent(roll))
                    {
                        s[i].deleteStudent();
                        found = 1;
                        cout << "\nStudent Deleted Successfully!\n";
                        break;
                    }
                }

                if (found == 0)
                    cout << "\nStudent Not Found!\n";

                break;

            case 6:
                cout << "\nThank You for Using Student Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
