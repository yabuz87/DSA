/*
        two pointer and sliding window
        - two pointers, one at the start and one at the end of the window
        - move the pointers based on the condition
        - return the result
        types of pattern in the sliding window
        1.constant window(for example you may asked to check  the maximum of the sub array with having 4 elements from an array having 10 elements.)
        2.variable window(for example you may asked to check the maximum of the sub array with having elements with less than k number)
        3.no of sub arrays where the condition <condition>
        4.the shortest(minimun) window of the Given array.
        note this all are use  the three methods (concepts)
        Generating all the sub-array(which we used in bruteforce algorithm)
        using while condition as we used in the second and the third merthod
         and also we may optimize our algorithms depending on the given
         problem that is it.

 */
/* this is a question asked 
what is the maximum length of the window 
in the given array with the sum
 of the window is less than the number k.
 
*/
 public class slidingWindow{

    public static void main(String[] args) {
        int[] check=new int[]{2,5,1,7,6,10};
        Window w=new Window();
        System.out.println(w.betterApproach(check,14));
        System.out.println("this one is better than others as compared to the above ones");
        System.out.println(w.optimal(check,14));
       System.out.println(w.maxSum(check, 4));
        // System.out.println(w.maxSum(check,3));

        
    }
}
class Window{
    Window()
    {

        
    }
  public  int maxLength(int[] num,int k)
    {
        //this function is using bruteforce algorithm which is 
        //generating all the subset of array(sub array)
        // and summing them up and comparing to the number k whic has given as a condition.
        //let's say the number array is num=[2,5,1,7,10]
        int size=num.length;
        int maxLen=0;
        for(int i=0;i<size-1;i++)
        {
            int sum=0;
            for(int j=i;j<size-1;j++)
            {
                sum=sum+num[j];
                if(sum<=k)
                {
                    maxLen=Math.max(maxLen, j-i+1);
                }
                else if(sum>k)
                {break;}
            }

        }
        return maxLen;
    }
    public int betterApproach(int[]num,int k)
    {
        int r=0,l=0,sum=0,maxLen=0;
        int n=num.length;
        while(r<n)
        {
            sum+=num[r];

            while(sum>k)
            {
                sum-=num[l];
                l++;
            }
            if(sum<=k)
            {
                maxLen=Math.max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
    public int  optimal(int[] num, int k)
    {
        //let's say the number array is num=[2,5,1,7,10] and k=14
        /*this window is better than the above bruteforce b/c 
        it has only O(n) time complexity{T.C} and O(1) space complexity 
        which beats the above beat in O(n) 
        {the above one has almost O(n^2)of time complexity} */
        int maxsum=0;
        int sum=0;
        int r=0,l=0;
        int len=num.length;
        while(r<len)
        {
            sum+=num[r];
            if(sum>k)
            {
               sum-=num[l];
               l++; 
            }
            if(sum<k)
            {
               maxsum=Math.max(maxsum,r-l+1);
            }
            r++;
        }
        return maxsum;
            
    }
    public int maxSum(int[] num,int k)
    {
        //here the question is to find the maximum number of card you get from the 
        //given array by just selecting the k element's either from left or from right.
        int leftSum=0,rightSum=0,sum=0;
        int n=num.length;
        for(int i=0;i<k;i++)
        {
            leftSum+=num[i];
        }
        sum=leftSum;
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--)
        {
            sum=Math.max(sum,rightSum+leftSum);
            leftSum=leftSum-num[i];
            rightSum+=num[rightIndex-1];
            rightIndex--;
            sum=Math.max(sum,rightSum+leftSum);
        }

       
       return sum;
    
    }
}


