import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static int n, sum = 0;
    private static int [] array;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;

        n = Integer.parseInt(br.readLine());

        array = new int[n];

        s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        for(int i = 0; i < n; i++){
            array[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(array);

        for(int i = 0; i < n; i++){
            sum += (n - i) * array[i];
        }

        System.out.println(sum);
    }
}