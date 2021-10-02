// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
  int nextGreatestLetter(vector<int> &letters, int target, bool x)
  {
    int s = 0, mid, e = letters.size() - 1, ans = -1;
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
        ans = mid;
        if (x)
        {
          s = mid + 1;
        }
        else
        {
          e = mid - 1;
        }
      }
    }
    return ans;
  }

  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> ans;
    ans.push_back(nextGreatestLetter(nums, target, false));
    ans.push_back(nextGreatestLetter(nums, target, true));
    return ans;
  }
};