import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, num = 0, sdate = 3019999, edate = 0, cnt = 0;
        int [] arr;
        String s;

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        for(int i = 0; i < N; i++) {
            num = 0;
            s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            for(int j = 0; j < 4; j++) {
                num *= 100;
                num += Integer.parseInt(st.nextToken());
                
            }
            arr[i] = num;
        }
        Arrays.sort(arr);

        int i = 0;
        boolean found = false;
        while(sdate < 11310000) {
            found = false;
            while (i < N && sdate > arr[i]) {
                if (arr[i] % 10000 > edate) {
                    edate = arr[i] % 10000;
                }
                i++;
                found = true;
            }
            if (!found)
                break;
                
            sdate = edate * 10000 + 9999;
            cnt++;
        }
        if (!found) System.out.println("0");
        else System.out.println(cnt);
    }
}