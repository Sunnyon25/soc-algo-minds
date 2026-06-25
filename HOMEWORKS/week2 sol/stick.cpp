#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long median = arr[n / 2];
    long long cost = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > median)
            cost += arr[i] - median;
        else
            cost += median - arr[i];
    }

    cout << cost;

    return 0;
}