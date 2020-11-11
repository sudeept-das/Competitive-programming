/*Given an array of n positive integers. 
Write a program to find the 
sum of maximum sum subsequence of the given array such that 
the integers in the subsequence are sorted in increasing order. 
For example, 
if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and 
if the input array is {10, 5, 4, 3}, then output should be 10
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll maxSumIS(ll arr[], ll n)
{
	ll i,j, max=0;
	ll msis[n];
	
	for(i=0;i<n;i++)
		msis[i]= arr[i];
		
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
				msis[i]= msis[j] + arr[i];
				
	for(i=0;i<n;i++)
		if(max<msis[i])
			max=msis[i];
			
	return max;
}

int main()
{
	ll arr[]= {1, 101, 2, 3, 100, 4, 5};
	ll n=sizeof(arr)/sizeof(arr[0]);
	cout<< "Sum of maximum sum increasing sequence is "<<maxSunIS(arr, n)<<"\n";
	return 0;
}
