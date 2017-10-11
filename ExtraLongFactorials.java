import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {
    public static BigInteger f(int N) {
        BigInteger result = new BigInteger("1");
        for(int i = 1; i <= N; ++i) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(f(n));
    }
}
