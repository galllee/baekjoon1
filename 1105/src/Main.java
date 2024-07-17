import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    private static String L, R;
    private static int num = 0;

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
    
        StringTokenizer st = new StringTokenizer(s);
        L = st.nextToken();
        R = st.nextToken();
        
        if (L.length() == R.length()){
            for(int i = 0; i < L.length(); i++){
                if (L.charAt(i) == R.charAt(i)){
                    if (L.charAt(i) == '8')
                        num++;
                }
                else
                    break;
            }
        }
        System.out.println(num);
    }
}