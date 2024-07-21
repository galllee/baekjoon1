import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main
{
    private static int N, max = 0;
    private static long sum = 0;
    private static String[] sarr;
    private static long[] alp = new long[26];
    

    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        sarr = new String[N];

        for(int i = 0; i < N; i++)
        {
            sarr[i] = br.readLine();
            if (max < sarr[i].length())
                max = sarr[i].length();
        }
        
        for(int i = 0; i < N; i++)
        {
            String spaces = " ".repeat(max - sarr[i].length());
            sarr[i] = spaces + sarr[i];
            
            for(int j = 0; j < max; j++)
            {
                if (sarr[i].charAt(j) != ' ')
                {
                    alp[sarr[i].charAt(j) - 'A' + 0] += Math.pow(10, max - j - 1);
                }
            }
        }

        Long[] longArray = Arrays.stream(alp).boxed().toArray(Long[]::new);
        Arrays.sort(longArray, Collections.reverseOrder());
        alp = Arrays.stream(longArray).mapToLong(Long::longValue).toArray();
        
        for(int i = 0; i < 10; i++)
        {
            sum += alp[i] * (9 - i);
        }

        System.out.println(sum);
    }
}