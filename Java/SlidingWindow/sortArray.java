import java.util.Arrays;

public class sortArray {

    public static void main(String[] args) {
        int[][] arr = {
            {1, 2},
            {2, 4},
            {4, 6},
            {4, 8}
        };

        sortArray sorter = new sortArray();
        sorter.sortArr(arr);
    }



    // public void Average(int[] num)
    // {
    //     int n=num.length;
    //     for(int i=0;i<n;i++)
    //     {
    //         int target=num[0][i];
    //         for(int j=i+1)
    //     }
    // }

    public void sortArr(int[][] num) {
        Arrays.sort(num, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(b[1], a[1]);
            }
        });
        for(int[] pair:num)
        {
            System.out.println(Arrays.toString(pair));
        }

    }
}
