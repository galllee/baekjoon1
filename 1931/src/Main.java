import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Comparator;


public class Main {
    private static int n, num = 0;
    private static int [][] array;
    private static int [] last;
    
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        
        n = Integer.parseInt(br.readLine());
        array = new int [n][2];
        last = new int[2];
        for(int i = 0; i < n; i++){
            s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            array[i][0] = Integer.parseInt(st.nextToken());
            array[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[1] != b[1]) {
                    return Integer.compare(a[1], b[1]);
                } else {
                    return Integer.compare(a[0], b[0]);
                }
            }
        });

        for(int i = 0; i < n; i++){
            if (last[1] <= array[i][0]){
                last[0] = array[i][0];
                last[1] = array[i][1];
                num++;
            }
        }
        System.out.println(num);
    }
}