/* You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i=0;i<flowerbed.length;i++) {
            if (i == 0 && flowerbed.length > 1) {
                if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (flowerbed[i] == 0 && flowerbed.length > 2 && flowerbed[i-1] == 0 && i+1 < flowerbed.length && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            else if (i == flowerbed.length-1 && flowerbed.length > 1) {
                if (flowerbed[i-1] == 0 && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (flowerbed.length == 1 && flowerbed[0] == 0) {
                n--;
            }
            
            if (n <= 0) break;
        }
        return n<=0;
    }
}
