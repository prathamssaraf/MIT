#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string a, b, c;
    cout << "Enter the string: ";
    cin >> a;

    clock_t start = clock();
    
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            b = b + a[i];
        }
    }
    cout << b << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
    return 0;
}


