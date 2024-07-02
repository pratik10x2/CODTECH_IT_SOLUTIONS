#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    vector<int> grades;
};

vector<Student> students;
int nextId = 1;

void addStudent() {
    Student newStudent;
    newStudent.id = nextId++;
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    int grade;
    char moreGrades;
    do {
        cout << "Enter grade: ";
        cin >> grade;
        newStudent.grades.push_back(grade);
        cout << "Add another grade? (y/n): ";
        cin >> moreGrades;
    } while (moreGrades == 'y' || moreGrades == 'Y');

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

void editStudent() {
    int id;
    cout << "Enter student ID to edit: ";
    cin >> id;

    for (auto &student : students) {
        if (student.id == id) {
            cout << "Editing student: " << student.name << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, student.name);

            student.grades.clear();
            int grade;
            char moreGrades;
            do {
                cout << "Enter grade: ";
                cin >> grade;
                student.grades.push_back(grade);
                cout << "Add another grade? (y/n): ";
                cin >> moreGrades;
            } while (moreGrades == 'y' || moreGrades == 'Y');

            cout << "Student information updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void calculateGrades() {
    int id;
    cout << "Enter student ID to calculate grades: ";
    cin >> id;

    for (const auto &student : students) {
        if (student.id == id) {
            int total = 0;
            for (int grade : student.grades) {
                total += grade;
            }
            double average = static_cast<double>(total) / student.grades.size();
            cout << "Student: " << student.name << "\n";
            cout << "Average Grade: " << fixed << setprecision(2) << average << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void listStudents() {
    cout << "Listing all students:\n";
    for (const auto &student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", Grades: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

void displayMenu() {
    cout << "\nStudent Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Edit Student\n";
    cout << "3. Delete Student\n";
    cout << "4. Calculate Grades\n";
    cout << "5. List Students\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                calculateGrades();
                break;
            case 5:
                listStudents();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
