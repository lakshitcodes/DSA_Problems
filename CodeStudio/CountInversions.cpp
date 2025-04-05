#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.naukri.com/code360/problems/count-inversions_615

#include <bits/stdc++.h> 
using namespace std;

long long merge(long long *arr, int low, int mid, int high) {
    int left = low, right = mid + 1, k = 0;
    long long temp[high - low + 1];
    long long count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            count += (mid - left + 1);  
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }

    return count;
}

long long mergeSort(long long *arr, int i, int j) {
    if (i >= j) return 0;  

    long long count = 0;
    int mid = i + (j - i) / 2;

    count += mergeSort(arr, i, mid);
    count += mergeSort(arr, mid + 1, j);
    count += merge(arr, i, mid, j);

    return count;
}

long long getInversions(long long *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}