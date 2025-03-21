#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to hold student details
struct Student {
    string name;
    int rollNumber;
    vector<double> marks;
    double totalMarks;
    char grade;
};

// Function to calculate grade based on total marks
char calculateGrade(double totalMarks) {
    if (totalMarks >= 90) return 'A';
    else if (totalMarks >= 80) return 'B';
    else if (totalMarks >= 70) return 'C';
    else if (totalMarks >= 60) return 'D';
    else return 'F';
}

// Function to input student details
Student inputStudentDetails() {
    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter roll number: ";
    cin >> student.rollNumber;

    int numSubjects;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    student.marks.resize(numSubjects);
    student.totalMarks = 0;

    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter marks for subject " << i + 1 << " (out of 100): ";
        cin >> student.marks[i];
        student.totalMarks += student.marks[i];
    }

    student.grade = calculateGrade(student.totalMarks / numSubjects);
    cin.ignore(); // Clear the input buffer
    return student;
}

// Function to display student details
void displayStudentDetails(const Student& student) {
    cout << "\nStudent Details:\n";
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Marks:\n";
    for (size_t i = 0; i < student.marks.size(); ++i) {
        cout << "Subject " << i + 1 << ": " << student.marks[i] << endl;
    }
    cout << "Total Marks: " << student.totalMarks << endl;
    cout << "Grade: " << student.grade << endl;
}

int main() {
    vector<Student> students;
    char addMore;

    do {
        cout << "\nEnter details for a new student:\n";
        Student student = inputStudentDetails();
        students.push_back(student);

        cout << "\nDo you want to add another student? (y/n): ";
        cin >> addMore;
        cin.ignore(); // Clear the input buffer
    } while (addMore == 'y' || addMore == 'Y');

    cout << "\n--- Student Grading System Report ---\n";
    for (const auto& student : students) {
        displayStudentDetails(student);
        cout << "---------------------------\n";
    }

    return 0;
}