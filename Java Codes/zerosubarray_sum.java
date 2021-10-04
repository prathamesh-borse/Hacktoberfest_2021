import java.util.HashSet;
import java.util.Set;
 
public class ZeroSumSubarray
{
    static Boolean subArray(int arr[])
    {
        
        Set<Integer> h = new HashSet<Integer>();
 
        
        int sum = 0;
 
        
        for (int i = 0; i < arr.length; i++)
        {
           
            sum += arr[i];
 
      
            if (arr[i] == 0
                || sum == 0
                || h.contains(sum))
                return true;
 
          
            h.add(sum);
        }
 
      
        return false;
    }
 

    public static void main(String arg[])
    {
        int arr[] = { 55, -2, 5, 1, -6 };
        if (subArray(arr))
            System.out.println(
                "Found a subarray with 0 sum");
        else
            System.out.println("No Such SubArray with 0 sum");
    }
}
