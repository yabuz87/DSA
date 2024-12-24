import java.util.HashMap;

public class A2SVProblem{
    public static void main(String[] args)
    {
        System.out.println(new A2SVProblem().checkLength("aaaabaab", 4));
        System.out.println(new A2SVProblem().numberOfSub("zzzz"));
        System.out.println(new A2SVProblem().maxNumberofArray(new int[]{4,3,-2,5}));
        System.out.println(new A2SVProblem().canMakePalindrome("ivicc"));
        System.out.println(new A2SVProblem().longestSubString("pwwkew"));

    }



    int checkLength(String s, int k) {
        int n = s.length()-1;
        int left = 0;
        int right = k-1;
        int maxLength=k;
       
    
        while (right < n) {
            int tempLength = 0;
            boolean checked = false;
            for (int i = left; i < right; i++) {
                if (s.charAt(i) != s.charAt(i + 1) && checked==false) {
                    tempLength++;
                    checked = true;
                } else if (s.charAt(i) != s.charAt(i + 1) && checked==true) {
                    checked = false;
                }
            }
            
            maxLength = Math.min(tempLength, maxLength);
            left++;
            right++;
        }
        
        return maxLength;
    }
    int numberOfSub(String a){
        char[] arr = a.toCharArray();
        int count=0;
        if(arr.length==0)
        {
            return 1;
        }
        for(int i=0;i<arr.length;i++)
        {
                for(int j=i;j<arr.length;j++)
                {
                    if(arr[i]==arr[j])
                    {
                        count++;

                    }
                }

        }
        return count;
    }
    int maxNumberofArray(int[] arr)
    { 
         int max=0;
         int formerSum=0;
         int latterSum=0;
         int   n=arr.length;
         int left=0;
         while(left<n)
         {
           int  right=left;
           formerSum+=arr[left];
           while(right<n)
           {
               latterSum+=arr[right];
               right++;    
           }
              max=Math.max(formerSum,latterSum);
              latterSum=0;
              System.out.println("max:"+max);
                left++;
         }
         return max;
    }
    boolean canMakePalindrome(String s)
    {
        HashMap<Character, Integer> result=new HashMap<>();
        int oddCount=0;
        for(Character c: s.toCharArray())
        {
            result.put(c,(result.getOrDefault(c,0)+1));
        }

        for(Integer count:result.values())
        {
                if(count%2!=0)
                {
                    oddCount++;
                }
        }
        return oddCount<=1;

    }

    int longestSubString(String s)
    {
        HashMap<Character, Integer> container=new HashMap<>();
        int left=0;
        if(s.length()==0)
        {
            return 0;
        }
        else if(s.equals(" "))
        {
            return 1;
        }
        int right=0;
        int maxLength=0;
        while(right<s.length())
        {
            char current=s.charAt(right);
            if(container.containsKey(current))
            {
              left=Math.max(left,container.get(current)+1);
              maxLength=Math.max(maxLength, (right-left)+1); 
              container.replace(s.charAt(right),right); 
              

            }
            else{
                container.put(s.charAt(right),right);
                // maxLength=Math.max(maxLength, (right-left+1));
            }
            right++;
        }
        return maxLength;
    }
    int FindMaxSubArray(int[] nums,int k)
    {
        int n=nums.length;
        int left=0;
        int right=0;
        int sum=0;
        int max=0;
        for(int i=0;i<k;i++)

        {
            sum+=nums[i];
        }
        while(right<n)
        {
            sum+=nums[right];
            max=Math.max(max,sum);
            sum-=nums[left];
            left++;
            right++;
        }
        return max;
    }


    
}