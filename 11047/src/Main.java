import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    private static int n, k, num = 0;
    private static int[] array;

    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        array = new int[n];

        for (int i = 0; i < n; i++){
            array[i] = Integer.parseInt(br.readLine());
        }

        while(k > 0){
            for(int i = n - 1; i >= 0; i--){
                while (k >= array[i]){
                    k -= array[i];
                    num++;
                }
            }
        }
        System.out.println(num);
    }
}