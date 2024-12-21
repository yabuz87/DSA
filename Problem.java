public class Problem{
    public static void main(String[] args)
    {
        System.out.println(new Problem().checkLength("aabbaa", 3));
    }


    int checkLength(String s, int k) {
        int n = s.length();
        int left = 0;
        int right = k;
        int maxLength = 0;
       
    
        while (right < n) {
            int tempLength = 0;
            boolean checked = true;
            for (int i = left; i < right; i++) {
                if (s.charAt(i) != s.charAt(i + 1) && !checked) {
                    tempLength++;
                    checked = true;
                } else if (s.charAt(i) != s.charAt(i + 1) && checked) {
                    checked = false;
                }
            }
            
            maxLength = Math.max(tempLength, maxLength);
            left++;
            right++;
        }
        
        return maxLength;
    }
    
}