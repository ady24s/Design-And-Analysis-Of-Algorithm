#include <iostream>
#include <cmath>

using namespace std;

// calc min swaps required and display the swaps
int minSwapsToEqualSums(char num[], int len, int N) {
    if (2 * N > len) {
        return -1; // Not enough digits to compare
    }

    // sum of the first N digits
    int sumFirstN = 0;
    for (int i = 0; i < N; i++) {
        sumFirstN += num[i] - '0';
    }

    // sum of the last N digits
    int sumLastN = 0;
    for (int i = len - N; i < len; i++) {
        sumLastN += num[i] - '0';
    }

    // If the sums are already equal, no swaps needed
    if (sumFirstN == sumLastN) {
        cout << "No swaps needed as sums are already equal." << endl;
        return 0;
    }

    int swaps = 0;
    int i = 0, j = len - 1;

    // swap till sums are equal
    while (sumFirstN != sumLastN && i < N && j >= len - N) {
        int firstDigit = num[i] - '0';
        int lastDigit = num[j] - '0';

        // Swap digits if it helps in reducing the difference
        if ((sumFirstN > sumLastN && firstDigit > lastDigit) || (sumFirstN < sumLastN && lastDigit > firstDigit)) {
            cout << "Swapping " << num[i] << " and " << num[j] << endl;
            swap(num[i], num[j]);
            sumFirstN = sumFirstN - firstDigit + lastDigit;
            sumLastN = sumLastN - lastDigit + firstDigit;
            swaps++;
            cout << "Number after swap: ";
            for (int k = 0; k < len; k++) {
                cout << num[k];
            }
            cout << endl;
            cout << "Sum of first " << N << " digits: " << sumFirstN << endl;
            cout << "Sum of last " << N << " digits: " << sumLastN << endl;
        }

        i++;
        j--;
    }

    // Display the final sums
    cout << "Final number: ";
    for (int k = 0; k < len; k++) {
        cout << num[k];
    }
    cout << endl;
    cout << "Final sum of first " << N << " digits: " << sumFirstN << endl;
    cout << "Final sum of last " << N << " digits: " << sumLastN << endl;

    return swaps;
}

int main() {
    char num[100];
    int N;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the value of N: ";
    cin >> N;

    int len = 0;
    while (num[len] != '\0') len++;

    int result = minSwapsToEqualSums(num, len, N);

    if (result == -1) {
        cout << "Not enough digits to compare" << endl;
    } else {
        cout << "Minimum swaps required: " << result << endl;
    }

    return 0;
}
