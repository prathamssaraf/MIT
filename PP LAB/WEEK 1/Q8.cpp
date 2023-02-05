#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

// Function to find the 1's complement of an integer
int findComplement(int n) {
int bit_count = floor(log2(n))+1;
int ones = ((1 << bit_count) - 1);
return ones ^ n;
}

int main() {
int m, n;
cout << "Enter the size of the matrix (MxN): ";
cin >> m >> n;

int a[m][n];
int b[m][n];

cout << "Enter the elements of matrix A: " << endl;
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
cin >> a[i][j];
}
}

for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
b[i][j] = a[i][j];
}
}


clock_t start = clock();
for (int i = 1; i < m-1; i++) {
for (int j = 1; j < n-1; j++) {
b[i][j] = findComplement(b[i][j]);
}
}
clock_t end = clock();
double time = double(end-start)/CLOCKS_PER_SEC;

cout << "Matrix B: " << endl;
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
cout << b[i][j] << " ";
}
cout << endl;
}

cout << "\nTime taken by the program: " << time << "s" << endl;
return 0;
}

