// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include <bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[], int N, int k)
{
	// To store final answer
	int sum = 0;

	// Find all subarray
	for (int i = 0; i < N; i++) {
		// To store length of subarray
		int length = 0;
		for (int j = i; j < N; j++) {
			// Increment the length
			length++;

			// When there is subarray of size k
			if (length == k) {
				// To store maximum and minimum element
				int maxi = INT_MIN;
				int mini = INT_MAX;

				for (int m = i; m <= j; m++) {
					// Find maximum and minimum element
					maxi = max(maxi, arr[m]);
					mini = min(mini, arr[m]);
				}

				// Add maximum and minimum element in sum
				sum += maxi + mini;
			}
		}
	}
	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = { 2, 5, -1, 7, -3, -1, -2 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, N, k);
	return 0;
}

// Time Complexity: O(N2*k), because two loops to find all subarray and one loop to find the maximum and minimum elements in the subarray of size k
// Auxiliary Space: O(1), because no extra space has been used