#include <iostream>
#include <string>  
#include <ctime>
using namespace std;

int main()
{
    string a;
    cout<<"Enter the string: ";
    getline(cin, a);

    clock_t begin = clock();

    for (int i = 0; i < a.length(); i++) {
        if (isupper(a[i])) {
            a[i] = tolower(a[i]);
        } else if (islower(a[i])) {
            a[i] = toupper(a[i]);
        }
    }

    clock_t end = clock();
    double elapsed_time = double(end - begin) / CLOCKS_PER_SEC * 1000;

    cout << "Toggled string: " << a << endl;
    cout << "Elapsed time: " << elapsed_time << "ms" << endl;
    return 0;
}
