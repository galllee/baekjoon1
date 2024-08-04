import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, sum = 0;
        Integer [] arr;

        N = Integer.parseInt(br.readLine());
        
        arr = new Integer[N];

        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr, Collections.reverseOrder());

        int i = 0;
        while (i < N && arr[i] > 0) {
            if (i + 1 < N && arr[i + 1] > 0){
                if (arr[i] == 1 || arr[i + 1] == 1) {
                    sum += arr[i];
                    sum += arr[i + 1];
                }
                else {
                    sum += arr[i] * arr[i + 1];
                }
                i += 2;
            }
            else {
                sum += arr[i];
                i++;
            }
        }

        int j = N - 1;
        while (j >= 0 && arr[j] <= 0) {
            if (j - 1 >= 0 && arr[j - 1] <= 0) {
                sum += arr[j] * arr[j - 1];
                j -= 2;
            }
            else {
                sum += arr[j];
                j--;
            }
    }

        System.out.println(sum);
    }
}