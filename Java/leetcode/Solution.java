public class Solution{
    public static void main(String[] args)
    {

            Solution nn=new Solution();
            System.out.println(nn.mySqrt(7));
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
    
    
}