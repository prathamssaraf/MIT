#include <iostream>
#include <ctime>
using namespace std;

void reverseDigits(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int number = arr[i];
        int reverse = 0;
        while (number != 0) {
            reverse = reverse * 10 + number % 10;
            number /= 10;
        }
        arr[i] = reverse;
    }
}

int main() {
    int arr[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int size = 9;

    clock_t start = clock();

    reverseDigits(arr, size);

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC*1000;

    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Time taken by function: " << time_taken << " seconds" << endl;

    return 0;
}
