import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main
{
    private static int n, m;
    private static long sum = 0;
    private static long[] arr;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new long[n];

        s = br.readLine();
        st = new StringTokenizer(s);

        for(int i = 0; i < n; i++)
        {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        for(int i = 0; i < m; i++)
        {
            arr[0] = arr[0] + arr[1];
            arr[1] = arr[0];
            Arrays.sort(arr);
        }

        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        System.out.println(sum);
    }
}