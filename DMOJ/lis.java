import java.io.*;
import java.util.*;

public class b
{
    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int nums[] = new int[n];
        for (int x = 0; x < n; x++)
            nums[x] = in.nextInt();
        int[] dp = new int[n];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        System.out.println(len);
    }
}
