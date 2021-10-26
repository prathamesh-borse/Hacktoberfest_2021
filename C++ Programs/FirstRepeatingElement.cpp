// Problem Link
// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/?category%5B%5D=Arrays&category%5B%5D=Arrays&difficulty%5B%5D=0&page=2&query=category%5B%5DArraysdifficulty%5B%5D0page2category%5B%5DArrays

//Solution

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        int max=n;int k=0;
        
        //find the max to get two array of index max
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        //initialize two arrays with zero
        int a[max+1]={};
        int b[max+1]={};
        
        //assign values to a and b
        
        for(int i=0;i<n;i++){
            if(a[arr[i]]){
              b[arr[i]]=1;
              k=1;
            }
            else{
                a[arr[i]]=i+1;
            }
        }
        
        if(k==0){
            
         return -1;
        }
        else{
        int min=max+1;
            for(int i=0;i<max+1;i++){
                if(a[i] && b[i] && min>a[i]){
                    min=a[i];
                }
            } 
            return min; 
        }
    }
};

// { Driver Code Starts.
int main() {

    int t;
  // } Driver Code Ends
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

