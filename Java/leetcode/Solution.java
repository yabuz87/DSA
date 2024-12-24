import java.util.Arrays;
import java.util.HashMap;

public class Solution{
    public static void main(String[] args)
    {

            Solution nn=new Solution();
            // System.out.println(nn.mySqrt(7));
            System.out.println(nn.maxNumber(new int[]{100,200,150,1000}));
            System.out.println(nn.willMakePalindrome("abcc"));
    }

        public int mySqrt(int x) {
            if (x == 0 || x == 1) {
                return x;
            }
            
            int left = 1, right = x, result = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if (mid <= x / mid) {
                    left = mid + 1;
                    result = mid;
                } else {
                    right = mid - 1;
                }
            }
            
            return result;
        }
        
        public int maxNumber(int[] weight)
        {
            int maxNumber=1;
            // [100,200,150,1000]
            Arrays.sort(weight);
            int max=weight[0];
            int count=1;
            if(5000-max<0)
               return 0;
            while(5000-max>0 && count<weight.length)
            {
                max+=weight[count];
                count++;
                maxNumber++;
            }
            return maxNumber;
        }
        public boolean willMakePalindrome(String s)
        {

            HashMap<Character,Integer> container=new HashMap<>();
                
            int count=0;
            int  oddCount=0;
            while(count<s.length())
            {
                container.put(s.charAt(count),container.getOrDefault(s.charAt(count),0)+1);
            }
             count=0;
             while(count<s.length())
            {
                    int value=container.get(s.charAt(count));
                    if(value%2!=0)
                    {
                        oddCount++;
                    }
            }
             
            return oddCount<=1;
        }
    
    
}