import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
// Accepted!

public class Main {
    public static boolean Judge(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s = bf.readLine();
        int cnt = 0;
        while (!Judge(s)) {
            StringBuilder sb = new StringBuilder(s);
            sb.reverse();
            BigInteger b = new BigInteger(sb.toString());
            BigInteger a = new BigInteger(s);
            BigInteger sum = a.add(b);
            cnt++;
            s = sum.toString();
            System.out.printf("%s + %s = %s\n", a, b, s);
            if (cnt >= 10) {
                break;
            }
        }
        if (cnt >= 10) {
            System.out.println("Not found in 10 iterations.");
        }
        else {
            System.out.printf("%s is a palindromic number.\n", s);
        }

    }
}
