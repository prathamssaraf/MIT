#include <iostream>
using namespace std;

int main()
{
int a[5][5], b[5][5];
cout << "Enter the elements of matrix A: " << endl;
for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        cin >> a[i][j];
    }
}

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        if (i == j)
        {
            b[i][j] = 0;
        }
        else if (i > j)
        {
            int max = a[i][0];
            for (int k = 1; k < 5; k++)
            {
                if (a[i][k] > max)
                {
                    max = a[i][k];
                }
            }
            b[i][j] = max;
        }
        else
        {
            int min = a[i][0];
            for (int k = 1; k < 5; k++)
            {
                if (a[i][k] < min)
                {
                    min = a[i][k];
                }
            }
            b[i][j] = min;
        }
    }
}

cout << "The resultant matrix B is: " << endl;
for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        cout << b[i][j] << " ";
    }
    cout << endl;
}

return 0;
}
