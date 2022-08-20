import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());

        for (int i = 0; i < N; i++) {
            String line = bf.readLine();
            var s = line.split(" ");
            BigInteger a = new BigInteger(s[0]);
            BigInteger b = new BigInteger(s[1]);
            BigInteger c = new BigInteger(s[2]);
            var res = a.add(b).compareTo(c);

            System.out.printf("Case #%d: %s\n", i + 1, res > 0? "true": "false");
        }

    }
}
