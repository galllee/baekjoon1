import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        StringTokenizer st;
        int N, M, i, j, cnt = 0;
        ArrayList<Integer> crane = new ArrayList<>();
        ArrayList<Integer> box = new ArrayList<>();

        N = Integer.parseInt(br.readLine());
        s = br.readLine();
        st = new StringTokenizer(s);
        for(i = 0; i < N; i++) {
            crane.add(Integer.parseInt(st.nextToken()));
        }

        M = Integer.parseInt(br.readLine());
        s = br.readLine();
        st = new StringTokenizer(s);
        for(i = 0; i < M; i++) {
            box.add(Integer.parseInt((st.nextToken())));
        }

        Collections.sort(crane);
        Collections.sort(box);
        
        i = M - 1;
        j = N - 1;

        if (crane.get(j) < box.get(i)) {
            System.out.println("-1");
            return ;
        }
        
        while (!box.isEmpty()) {
            i = box.size() - 1;
            j = N - 1;
            
            while (j >= 0) { 
                if (i < 0) break;
                else if (crane.get(j) >= box.get(i)){
                    box.remove(i);
                    j--;
                    i--;
                }
                else {
                    i--;
                }
            }
            cnt++;
        }

        System.out.println(cnt);
    }
}