// // 744. Find Smallest Letter Greater Than Target - Easy

// #include <bits/stdc++.h>
// using namespace std;
// #define f(x) for (int i = 0; i < x; i++)
// #define fe(x) for (int i = 0; i <= x; i++)
// #define vi vector<int>
// #define ll long long int

// // char nextGreatestLetter(vector<char> &letters, char target)
// // {
// //   int len = letters.size();
// //   int s = 0, e = len - 1, mid, ans;

// //   if (target >= letters[len - 1])
// //     return letters[0];
// //   while (s < e)
// //   {
// //     mid = (s + e - 1) / 2;
// //     if (target == letters[mid])
// //     {
// //       if (target == letters[mid - 1])
// //       {
// //         s = mid + 1;
// //       }
// //       else
// //       {
// //         return letters[mid + 1];
// //       }
// //       // ----------
// //       // ans = mid + 1;
// //       // break;
// //     }
// //     else if (target < letters[mid])
// //     {
// //       e = mid - 1;
// //     }
// //     else if (target > letters[mid])
// //     {
// //       s = mid + 1;
// //     }
// //   }
// //   return letters[s];
// //   // -------------
// //   // ans = s;
// //   // while (letters[ans] == target)
// //   // {
// //   //   ans++;
// //   //   if (ans >= len - 1)
// //   //     ans = 0;
// //   // }
// //   // return letters[ans];
// // }

// char nextGreatestLetter(vector<char> &letters, char target)
// {
//   int s = 0, mid, e = letters.size() - 1, ans, found = 0;

//   while (s <= e)
//   {
//     mid = s + (e - s) / 2;
//     if (target < letters[mid])
//     {
//       e = mid - 1;
//     }
//     else if (target > letters[mid])
//     {
//       s = mid + 1;
//     }
//     else
//     {
//       found = 1;
//       ans = mid;
//       s = mid + 1;
//     }
//   }
//   if (!found)
//   {
//     return letters[s];
//   }
//   else
//   {
//     if (ans >= letters.size() - 1)
//     {
//       ans = -1;
//     }
//     return letters[ans + 1];
//   }
// }

// int main()
// {
//   vector<char> vec;
//   vec.push_back('e');
//   vec.push_back('e');
//   vec.push_back('e');
//   vec.push_back('e');
//   vec.push_back('e');
//   vec.push_back('n');
//   vec.push_back('n');
//   vec.push_back('n');
//   char target = 'e';
//   cout << nextGreatestLetter(vec, target) << endl;
//   target = 'f';
//   cout << nextGreatestLetter(vec, target) << endl;
//   // vec.push_back('a');
//   // vec.push_back('f');
//   // vec.push_back('j');
//   // char target = 'a';
//   // cout << nextGreatestLetter(vec, target) << endl;
//   // target = 'c';
//   // cout << nextGreatestLetter(vec, target) << endl;
//   // target = 'd';
//   // cout << nextGreatestLetter(vec, target) << endl;
//   // target = 'g';
//   // cout << nextGreatestLetter(vec, target) << endl;
//   // target = 'j';
//   // cout << nextGreatestLetter(vec, target) << endl;
//   return 0;
// }

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int s = 0, mid, e = letters.size() - 1, ans, found = 0;
    if (target > letters[e])
      return letters[s];
    while (s <= e)
    {
      mid = s + (e - s) / 2;
      if (target < letters[mid])
      {
        e = mid - 1;
      }
      else if (target > letters[mid])
      {
        s = mid + 1;
      }
      else
      {
        found = 1;
        ans = mid;
        s = mid + 1;
      }
    }
    if (!found)
    {
      return letters[s];
    }
    else
    {
      if (ans >= letters.size() - 1)
      {
        ans = -1;
      }
      return letters[ans + 1];
    }
  }
};