#include <iostream>
#include <cstring>
using namespace std;

// ---------------- PART 1: Concatenate Two Strings ----------------
void concatStrings() {
    char str1[50] = "Hello ";
    char str2[50] = "World";

    int i = 0, j = 0;
    while (str1[i] != '\0') i++;

    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';

    cout << "Concatenated String: " << str1 << endl;
}

// ---------------- PART 2: Reverse a String ----------------
void reverseString() {
    char str[50] = "HELLO";
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - 1 - i]);

    cout << "Reversed String: " << str << endl;
}

// ---------------- PART 3: Remove Vowels ----------------
bool isVowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

void removeVowels() {
    char str[] = "Beautiful Day";
    char res[50];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i]))
            res[j++] = str[i];
    }
    res[j] = '\0';

    cout << "Without Vowels: " << res << endl;
}

// ---------------- PART 4: Sort Strings Alphabetically ----------------
void sortStrings() {
    char s[5][20] = {"banana", "apple", "mango", "grape", "cherry"};

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0)
                swap(s[i], s[j]);
        }
    }

    cout << "Sorted Strings:" << endl;
    for (int i = 0; i < 5; i++)
        cout << s[i] << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    cout << "----- PART 1: Concatenation -----" << endl;
    concatStrings();

    cout << "\n----- PART 2: Reverse String -----" << endl;
    reverseString();

    cout << "\n----- PART 3: Remove Vowels -----" << endl;
    removeVowels();

    cout << "\n----- PART 4: Sort Strings -----" << endl;
    sortStrings();

    return 0;
}
