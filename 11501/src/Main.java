import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Comparator;

public class Main
{
    private static int T, N, num = 0;
    private static long sum = 0;
    private static int[] array;

    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++)
        {
            int k = 0;
            int sell = 0;
            sum = 0;
            num = 0;
            N = Integer.parseInt(br.readLine());
            array = new int[N];
            Integer[] idx = new Integer[N];
            for(int j = 0; j < N; j++)
            {
                idx[j] = j;
            }
            
            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            for(int j = 0; j < N; j++)
            {
                array[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(idx, new Comparator<Integer>()
            {
                public int compare(Integer i1, Integer i2)
                {
                    return Integer.compare(array[i2], array[i1]);
                }
            });

            for(int j = 0; j < N; j++)
            {
                if (j == idx[k]) 
                {
                    sell = idx[k];
                    sum += num * array[j];
                    num = 0;
                    while(idx[k] <= sell && k < N - 1)
                    {
                        k++;
                    }
                }
                else 
                {
                    num++; 
                    sum -= array[j];
                }
            }
            
            System.out.println(sum);
        }
    }

}