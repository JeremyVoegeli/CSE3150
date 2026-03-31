#ifndef SOLUTION_H
#define SOLUTION_H
namespace solution{
    void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
    void updateGPA(double* gpaPtr, double newGpa);
    void printStudent(const char* name, const double& gpa);
    double averageGPA(const double gpas[], int size);
}
#endif
