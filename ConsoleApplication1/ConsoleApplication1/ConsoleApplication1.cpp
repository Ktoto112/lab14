#include <iostream>
#include <vector>
using namespace std;


bool isPerfect(int n) {
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return (n != 1 && sum == n);
}


int interpolationSearch(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (arr[high] == arr[low]) break;

        int pos = low + ((double)(x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1; 
}

int main() {
    int N;
    cout << "Enter the number N: ";
    cin >> N;

    
    vector<int> perfectNumbers;
    for (int i = 2; i < N; i++) {
        if (isPerfect(i))
            perfectNumbers.push_back(i);
    }

    
    cout << "Perfect numbers are less than " << N << ": ";
    for (int num : perfectNumbers)
        cout << num << " ";
    cout << endl;

    
    int target;
    cout << "Enter a number to search for: ";
    cin >> target;

    int index = interpolationSearch(perfectNumbers, target);

    if (index != -1)
        cout << "Number found at position " << index << endl;
    else
        cout << "Number not found." << endl;

    return 0;
}
