// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. Dayang Farah Farzana binti Abang Idham (A23CS0071)
// 2. Farra Nurzahin binti Zaharil Anuar (A23CS0079)
// 3. Safiya Nursyahadah binti Masnoor (A23CS0176)

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
    private:
        string name;
        int cwMark;
        int feMark;
        
    public:
        // Constructor
        Student(string, int, int);

        // Methods
        int getTotalMark() const;
        string getGrade();
        void printInfo() const;
        void printResult();
        void printResultFile(fstream &outFile);
         ~Student();
};

#endif
