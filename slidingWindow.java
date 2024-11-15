/* this is a question asked 
what is the maximum length of the window 
in the given array with the sum
 of the window is less than the number k.
 
*/
 public class slidingWindow{

    public static void main(String[] args) {
        int[] check=new int[]{2,5,1,7,10};
        Window w=new Window();
        System.out.println(w.maxLength(check,14));
        
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
}

