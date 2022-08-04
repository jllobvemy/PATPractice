import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] data;
        try {
            data = bf.readLine().split(" ");
        } catch (IOException e) {
            data = new String[3];
            e.printStackTrace();
        }
        int N = Integer.parseInt(data[0]);
        BigDecimal num1 = new BigDecimal(data[1]);
        BigDecimal num2 = new BigDecimal(data[2]);
        String sn1 = num1.toEngineeringString();
        String sn2 = num2.toEngineeringString();

        System.out.println(sn1);
        System.out.println(sn2);
    }
}
