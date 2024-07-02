import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int n, m, max, sum;
    private static int [][] array;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        max = 0;
        array = new int[n][m];

        for(int i = 0; i < n; i++){
            s = br.readLine();
            st = new StringTokenizer(s);
            
            for(int j = 0; j < m; j++){
                array[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        check_four();
        check_three();
        check_two();
        System.out.print(max);
        
    }

    private static void check_four(){
        for(int i = 0; i < n; i++){
            for(int j = 3; j < m; j++){
                sum = array[i][j - 3] + array[i][j - 2] + array[i][j - 1] + array[i][j];
                if (sum > max)
                    max = sum;
            }
        }
        for(int i = 0; i < m; i++){
            for (int j = 3; j < n; j++){
                sum = array[j - 3][i] + array[j - 2][i] + array[j - 1][i] + array[j][i];
                if (sum > max)
                    max = sum;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                sum = array[i - 1][j - 1] + array[i][j - 1] + array[i - 1][j] + array[i][j];
                if (sum > max)
                    max = sum;
            }
        }
    }
    
    private static void check_three(){
        for(int i = 0; i < n - 1; i++){
            for(int j = 2; j < m; j++){
                sum = array[i][j - 2] + array[i][j - 1] + array[i][j];
                for(int k = 2; k >= 0; k--){
                    sum = sum + array[i + 1][j - k];
                    if (sum > max)
                        max = sum;
                    sum = sum - array[i + 1][j - k];
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 2; j < m; j++){
                sum = array[i][j - 2] + array[i][j - 1] + array[i][j];
                for(int k = 2; k >= 0; k--){
                    sum = sum + array[i - 1][j - k];
                    if (sum > max)
                        max = sum;
                    sum = sum - array[i - 1][j - k];
                }
            }
        }
                
        for(int i = 0; i < m - 1; i++){
            for(int j = 2; j < n; j++){
                sum = array[j - 2][i] + array[j - 1][i] + array[j][i];
                for(int k = 2; k >= 0; k--){
                    sum = sum + array[j - k][i + 1];
                    if (sum > max)
                        max = sum;
                    sum = sum - array[j - k][i + 1];
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 2; j < n; j++){
                sum = array[j - 2][i] + array[j - 1][i] + array[j][i];
                for(int k = 2; k >= 0; k--){
                    sum = sum + array[j - k][i - 1];
                    if (sum > max)
                        max = sum;
                    sum = sum - array[j - k][i - 1];
                }
            }
        }
    }

    private static void check_two(){
        for(int i = 0; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                sum = array[i][j - 1] + array[i][j] + array[i + 1][j] + array[i + 1][j + 1];
                if (sum > max)
                    max = sum;
            }
        }
        for(int i = 1; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                sum = array[j][i] + array[j][i + 1] + array[j + 1][i - 1] + array[j + 1][i];
                if (sum > max)
                    max = sum;
            }
        }

        for(int i = 0; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                sum = array[j - 1][i] + array[j][i] + array[j][i + 1] + array[j + 1][i + 1];
                if (sum > max)
                    max = sum;
            }
        }
        for(int i = 1; i < n - 1; i++){
            for(int j = 0; j < m - 1; j++){
                sum = array[i][j] + array[i + 1][j] + array[i - 1][j + 1] + array[i][j + 1];
                if (sum > max)
                    max = sum;
            }
        }
    }
}
