// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. DAYANG FARAH FARZANA BINTI ABANG IDHAM
// 2. FARRA NURZAHIN BINTI ZAHARIL ANUAR
// 3. SAFIYA NURSYAHADAH BINTI MASNOOR

#include <iostream>
#include <string>

using namespace std;

void printStar(int n) {
    if (n <= 0) return;
    cout << "*";
    printStar(n-1);
}

void printNum(int n) {
    if(n>0){
        printNum(n-1);
        cout << n << " - ";
        printStar(n);
        cout << endl;
    }  
}

int totalOdd(int list[], int n, int i = 0){
    if(i>=n)
    return 0;
    if(list[i] % 2 != 0){
        cout<<list[i] <<" ";
        return list[i]+ totalOdd(list, n, i+1);
    }
    return totalOdd(list,n,i+1);
}


// Main function
int main(int argc, char *argv[])
{
    printNum(6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;
    system("pause");
    return 0;
    
}
