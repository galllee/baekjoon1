import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, max = 0, sum = 0, min = 50, idx = -1, a, b, c;
        int [] dice = new int[6];

        N = Integer.parseInt(br.readLine());
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);
        for(int i = 0; i < 6; i++) {
            dice[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < 6; i++) {
            if (min > dice[i]) {
                idx = i;
                min = dice[i];
            }
            if (max < dice[i]) {
                max = dice[i];
            }
        }
        a = min;

        if (N == 1) {
            for(int i = 0; i < 6; i++) {
                sum += dice[i];
            }
            sum -= max;
            System.out.println(sum);
            return ;
        }

        min = 50;
        for(int i = 0; i < 6; i++) {
            if (idx + i == 5 || i == idx) {
                continue;
            }
            if (min > dice[i]) {
                min = dice[i];
            }
        }
        b = a + min;

        min = 150;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    if (i + j == 5 || i + k == 5 || k + j == 5 || i == j || i == k || k == j) {
                        continue;
                    }
                    if (min > dice[i] + dice[j] + dice[k]) {
                        min = dice[i] + dice[j] + dice[k];
                    }
                }
            }
        }
        c = min;

        //ans = (c) * 4 + (b) * ((2 * N - 3) * 4) + a * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));

        BigInteger bigN = BigInteger.valueOf(N);
        BigInteger bigA = BigInteger.valueOf(a);
        BigInteger bigB = BigInteger.valueOf(b);
        BigInteger bigC = BigInteger.valueOf(c);

        BigInteger term1 = bigC.multiply(BigInteger.valueOf(4));
        BigInteger term2 = bigB.multiply(bigN.multiply(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(3)).multiply(BigInteger.valueOf(4)));
        BigInteger term3 = bigA.multiply(bigN.subtract(BigInteger.valueOf(1)).multiply(bigN.subtract(BigInteger.valueOf(2))).multiply(BigInteger.valueOf(4))
            .add(bigN.subtract(BigInteger.valueOf(2)).multiply(bigN.subtract(BigInteger.valueOf(2)))));

        BigInteger ans = term1.add(term2).add(term3);
        System.out.println(ans);
    }
}