#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string a, b, c;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;

    clock_t start = clock();
    
    for (int i = 0; i < a.length(); i++)
    {
        c = c + a[i] + b[i];
    }
    cout << c << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
    return 0;
}
