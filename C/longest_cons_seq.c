/*
 * Given an unsorted array X[] consisting of n integers, write a program 
 * to find the length of the longest consecutive sequence of integers in the array. 
 * The consecutive numbers can be in any order.
 * Input: X[] = [40, 4, 50, 1, 2, 13, 9, 3, 29], Output: 4
 * Explanation: The longest consecutive sequence is 1,2,3 and 4.
 */

#include <stdio.h>

int linearsearch(int x[], int n, int item) {
	int i = 0;
	for (i = 0; i < n; i++) {
		if (x[i] == item)
			return 1;
	}
	return 0;
}

int long_consq(int x[], int n) {
	int i, longest_len = 0, cur_element, cur_len;

	for (i = 0; i < n; i++) {
		cur_element = x[i];
		cur_len = 1;
		while (linearsearch(x, n, cur_element + 1)) {
			cur_element += 1; 
			cur_len += 1;
		}
		if (longest_len < cur_len) {
			longest_len = cur_len;
		} 
	}
	return longest_len;
}

int main() {
	//int x[] = {40, 4, 50, 1, 2, 13, 9, 3, 29};
	int x[] = {0, -3, 5, -1, -2, 1};
	int len = 0;

	//length of the array
	len = sizeof(x) / sizeof(x[0]);
//	printf("Array length = %d", len);

	//brute force approach
	printf("%d", long_consq(x, len));

	return 0;
}
 
