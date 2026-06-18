// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. Dayang Farah Farzana binti Abang Idham (A23CS0071)
// 2. Farra Nurzahin binti Zaharil Anuar (A23CS0079)
// 3. Safiya Nursyahadah binti Masnoor (A23CS0176)

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string name, int cwMark, int feMark){
    this->name = name;
    this->cwMark = cwMark;
    this->feMark = feMark;
}

int Student :: getTotalMark() const{
    return cwMark + feMark;
}

string Student :: getGrade(){
        int total = getTotalMark();

        if(total>=75 && total<=100)
            return "A";
        else if(total>=65 && total<=74)
            return "B";
        else if(total>=50 && total<=64)
            return "C";
        else if(total>=35 && total<=49)
            return "D";
        else if(total>=0 && total<=34)
            return "E";
        else
            return "error";
    }

void Student::printInfo() const{
    cout << "Name :" << name << "\ncoursework: " << cwMark << "\nFinal Exam: " << feMark << "\n\n";
}

void Student::printResult(){
    cout<<name<<" "<<getTotalMark()<<" "<<getGrade()<<"\n";
}

void Student::printResultFile(fstream &outFile) {
    outFile << name << " " << getTotalMark() << " " << getGrade() << endl;
}

Student::~Student(){
    cout << "Destroy Student Object - " << name << endl;
} 

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];

    fstream inFile("Marks.txt", ios::in);

    if(!inFile){
        cout<<"Cannot open!\n";
    }
    else cout<<"Successfully open\n";

    string name;
    int cwMark, feMark;
    int i = 0;

    while (inFile >> name >> cwMark >> feMark && i < LIST_SIZE) {
        studList[i] = new Student(name, cwMark, feMark);
        i++;
   }
   
    inFile.close();
   
    cout << "\nStudent mark info :\n";
    for (int j = 0; j < i; j++) {
        studList[j]->printInfo();
    }

    fstream outFile("Results.txt", ios::out);
    if (!outFile) {
        cout << "Cannot open Results.txt!\n";
        return 1;
    }

    cout << "\nPrint and save results from file:\n";
    for (int j = 0; j < i; j++) {
        studList[j]->printResult();      
        studList[j]->printResultFile(outFile); 
         delete studList[j];
    }

    outFile.close();

    system("pause");
    return 0;
}




