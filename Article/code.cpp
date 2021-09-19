/*
 * @Author: Siddharth Singh Chouhan.
 * Git hub: Sid672.
 */

// C++ program to build a suffix array in O(nlogn) time;
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "banana";
    int n = s.length();
    map<string, int> Map;
    int suffix[n];

    // Maping string with its index of
    // it's last letter.
    string sub = "";
    for (int i = n - 1; i >= 0; i--) {
        sub = s[i] + sub;
        Map[sub] = i;
    }

    // Storing all values of map
    // in suffix array.
    int j = 0;
    for (auto x : Map) {
        suffix[j] = x.second;
        j++;
    }

    // printing suffix array.
    cout << "Suffix array for banana is" << endl;
    for (int i = 0; i < n; i++) {
        cout << suffix[i] << " ";
    }
    cout << endl;
    return 0;
}

// Output

// Suffix array for banana is
// 5 3 1 0 4 2 