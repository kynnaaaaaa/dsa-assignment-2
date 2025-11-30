#include <iostream>
using namespace std;

// ---------------- PART 1: Linear Search for Missing Number ----------------
int findMissingLinear(int arr[], int n) { // n = total numbers including missing one
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n; 
}

// ---------------- PART 2: Binary Search for Missing Number ----------------
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    cout << "Linear Search → Missing number = " << findMissingLinear(arr, n) << endl;
    cout << "Binary Search → Missing number = " << findMissingBinary(arr, n) << endl;

    return 0;
}
