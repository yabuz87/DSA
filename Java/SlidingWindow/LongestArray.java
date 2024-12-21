package SlidingWindow;
import java.util.*;
public class LongestArray{


  public  int longestSubArr(String s) {
        int r = 0;
        int l = 0;
        int max = 0;
        HashMap<Character, Integer> check = new HashMap<>();

        while (r < s.length()) {
            char ch = s.charAt(r);

            if (check.containsKey(ch)) {
                l = Math.max(check.get(ch) + 1, l);
            }

            check.put(ch, r);
            max = Math.max(max, r - l + 1);
            r++;
        }

        return max;
    }


    
    public static void main(String[] args) {
        LongestArray la = new LongestArray();
        System.out.println(la.longestSubArr("abcabcbb")); // Output should be 3 for "abc"
    }
}
