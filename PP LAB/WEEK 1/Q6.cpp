#include <iostream>
#include <ctime>
using namespace std;

int main()
{
int rows, columns;
cout << "Enter the number of rows and columns in the matrix: ";
cin >> rows >> columns;
int matrix[rows][columns];
cout << "Enter the elements of the matrix: " << endl;
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < columns; j++)
{
cin >> matrix[i][j];
}
}
int vector[columns];
cout << "Enter the elements of the vector: " << endl;
for (int i = 0; i < columns; i++)
{
cin >> vector[i];
}
int result[rows];
for (int i = 0; i < rows; i++)
{
result[i] = 0;
}
clock_t start = clock();
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < columns; j++)
{
result[i] += matrix[i][j] * vector[j];
}
}
clock_t end = clock();
cout << "The result of the matrix times vector product is: " << endl;
for (int i = 0; i < rows; i++)
{
cout << result[i] << endl;
}
cout << "The operation took " << (end - start) / (double)CLOCKS_PER_SEC << " seconds to complete." << endl;
return 0;
}
