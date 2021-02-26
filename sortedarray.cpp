/*Median of sorted array*/
#include<bits/stdc++.h> 
using std::cout; 
int maximum(int a, int b); 
int minimum(int a, int b); 
double findMedianSortedArrays(int *a, int n, 
							int *b, int m) 
{ 
	int min= 0, max= n, i, j, median; 
	
	while (min <= max) 
	{ 
		i = (min+ max) / 2; 
		j = ((n + m + 1) / 2) - i; 
		if (j < 0) 
		{ 
			max= i-1; 
			continue; 
		} 
	if (i < n && j > 0 && b[j - 1] > a[i])		 
			min = i + 1; 
		else if (i > 0 && j < m && b[j] < a[i - 1])		 
			max= i - 1; 
	else
		{ if (i == 0)			 
				median = b[j - 1];			 
			else if (j == 0)			 
				median = a[i - 1];			 
			else			
				median = maximum(a[i - 1], b[j - 1]);			 
			break; 
		} 
	} 
	if ((n + m) % 2 == 1) 
		return (double)median; 
	if (i == n) 
		return (median+b[j]) / 2.0; 
	if (j == m) 
		return (median + a[i]) / 2.0; 
	return (median + minimum(a[i], b[j])) / 2.0; 
} 
int maximum(int a, int b) 
{ 
	return a > b ? a : b; 
} 

int minimum(int a, int b) 
{ 
	return a < b ? a : b; 
} 
int main() 
{ 
    int a[]={1,3};
    int b[]={1};
	int n = sizeof(a) / sizeof(int); 
	int m = sizeof(b) / sizeof(int); 
	if (n < m) 
		cout << findMedianSortedArrays(a, n, b, m); 
	else
		cout << findMedianSortedArrays(b, m, a, n); 
    return 0; 
} 
