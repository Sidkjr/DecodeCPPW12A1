#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[i] > 2 * arr[j]) j++;
        count += (j - (mid + 1));
    }

    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j2 = 0, k = left;
    while (i < n1 && j2 < n2) arr[k++] = (L[i] <= R[j2]) ? L[i++] : R[j2++];
    while (i < n1) arr[k++] = L[i++];
    while (j2 < n2) arr[k++] = R[j2++];

    return count;
}

int mergeSortAndCount(int arr[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int main() {
    int nums[] = {1, 3, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "Number of reverse pairs: " << mergeSortAndCount(nums, 0, n - 1) << endl;
}