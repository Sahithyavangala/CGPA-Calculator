#include <iostream>
#include <vector>
#include <iomanip> // for setprecision

using namespace std;

// Function to convert grade to grade points
double gradeToPoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<double> credits(numCourses);
    vector<char> grades(numCourses);

    // Input credits and grades for each course
    cout << "Enter credits and grades for each course:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << " credit hours: ";
        cin >> credits[i];
        cout << "Course " << i + 1 << " grade (A/B/C/D/F): ";
        cin >> grades[i];
    }

    // Calculate semester GPA
    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        double gradePoint = gradeToPoint(grades[i]);
        if (gradePoint == -1.0) {
            cout << "Invalid grade entered. Exiting.\n";
            return 1;
        }
        totalGradePoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    double gpa = totalGradePoints / totalCredits;

    // Output GPA with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Your GPA for this semester is: " << gpa << endl;

    // Option to calculate CGPA based on previous semesters
    char calculateCGPA;
    cout << "Do you want to calculate your CGPA based on previous semesters? (Y/N): ";
    cin >> calculateCGPA;

    if (calculateCGPA == 'Y' || calculateCGPA == 'y') {
        // Here you could add code to calculate CGPA based on previous semesters
        // For simplicity, assuming this is the first semester and CGPA is the same as GPA
        double cgpa = gpa;
        cout << "Your CGPA based on all semesters is: " << cgpa << endl;
    }

    return 0;
    }