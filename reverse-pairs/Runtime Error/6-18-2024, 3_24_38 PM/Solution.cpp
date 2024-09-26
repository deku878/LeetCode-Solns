// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    void merge(vector<int> &arr,long long int low,long long int mid, long long int high) {
    vector<long long int> temp; // temporary array
    long long int left = low;      // starting index of left half of arr
    long long int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (long long int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

long long int countPairs(vector<int> &arr,long long  int low,long long int mid, long long int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

long long int mergeSort(vector<int> &arr, long long int low,long long int high) {
    long long int cnt = 0;
    if (low >= high) return cnt;
    long long int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
    long long int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};