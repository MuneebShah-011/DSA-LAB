#include <iostream>
using namespace std;

int maxvalue(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 7, 2, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value: " << maxvalue(arr, n) << endl;
    return 0;
}

