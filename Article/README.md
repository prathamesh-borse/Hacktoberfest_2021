# Suffix Array - O(N log N) using the map.

A suffix array is a sorted array of all suffixes of a given string.

For more detail please check:  [Suffix Array | Set 2 (nLogn Algorithm)](https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/#:~:text=A%20suffix%20array%20is%20a,suffixes%20of%20a%20given%20string.&text=We%20have%20discussed%20Naive%20algorithm,while%20sorting%2C%20maintain%20original%20indexes.).

This is a simple way to solve this problem.

```
 Example:

0     banana                                                             5      a 

1     anana               Sort the Suffixes                              3      ana

2     nana                     ---------------->                         1      anana  

3     ana                    alphabetically                              0       banana  

4     na                                                                 4       na  

5     a                                                                  2       nana
```
The suffix array for "banana" is {5, 3, 1, 0, 4, 2}

In this section, we are discussing how to create a suffix array in O(N log N) time complexity.

We use the concept of map. 

```
Algorithm is:

1) Create a map with a key string and its value is integer.

2) Iterate over the string in reverse order and create a new string(i.e from i = n - 1, 0).

3) Map new string  with the last  index  position  of i.

4) Create an array and assign all values of the map in the array.
```

The time complexity of the algorithm is O(N log N) because insertion in map takes O(log N) time and we are performing insertion n time so, the total time is O(N logN) where N is the length of the string.

```C++
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
```
```
Output

Suffix array for banana is
5 3 1 0 4 2 
```

### [Demo Link](https://replit.com/@Siddharthsing13/Suffix-arry#main.cpp).