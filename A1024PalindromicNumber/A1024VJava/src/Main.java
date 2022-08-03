import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
// Accepted!


public class Main {
    static Boolean isPalindromic(String s) {
        var chararray = s.toCharArray();
        int len = s.length();
        int first = 0;
        int last = len - 1;
        while (true) {
            if (chararray[first] != chararray[last]) {
                return false;
            }
            first++;
            last--;
            if (first >= last) return true;
        }
    }
    static String Reverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return sb.toString();
    }
    public static void main(String[] args) {
        String N = "";
        int Step = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] tmp = br.readLine().split(" ");
            N = tmp[0];
            Step = Integer.parseInt(tmp[1]);
        } catch (IOException e) {
            e.printStackTrace();
        }
        int i = 0;
        while (i < Step && !isPalindromic(N)) {
            BigInteger b1 = new BigInteger(N);
            BigInteger b2 = new BigInteger(Reverse(N));
            BigInteger sum = b1.add(b2);
            N = sum.toString();
            i++;
        }
        System.out.println(N);
        System.out.println(i);
    }
}
