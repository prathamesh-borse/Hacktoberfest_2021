/*
Question : 852.Peak Index in a Mountain Array 

Link : https://leetcode.com/problems/peak-index-in-a-mountain-array

Let's call an array arr a mountain if the following properties hold:

1) arr.length >= 3
2) There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... arr[i-1] < arr[i]
    arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[i] is the peak element.

Sample Testcases : 

Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [24,69,100,99,79,78,67,36,26,19]
Output: 2

Constraints:

1)  3 <= arr.length <= 104
2)  0 <= arr[i] <= 106
3)  arr is guaranteed to be a mountain array.

Language Used : Java
Approach Used : Binary Search
Runtime : 0 ms

*/

class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start=0,end = arr.length-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return mid;
            
            else if(arr[mid]<arr[mid+1])
                start=mid+1;
            
            else end= mid-1;
        }
        return 0;
    }
}