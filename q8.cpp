#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isNew = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isNew = false;
                break;
            }
        }

        if (isNew) count++;
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;

    cout << "Distinct Elements = " << countDistinct(arr, n);
}
