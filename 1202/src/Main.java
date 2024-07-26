import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, K;
        long ans = 0;
        
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Jewelry[] jewelries = new Jewelry[N];
        int [] bag = new int[K];

        for(int i = 0; i < N; i++) {
            s = br.readLine();
            st = new StringTokenizer(s);
            int weight = Integer.parseInt(st.nextToken());
            int price = Integer.parseInt(st.nextToken());
            jewelries[i] = new Jewelry(weight, price);
        }

        for(int i = 0; i < K; i++) {
            bag[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(jewelries, (j1, j2) -> Integer.compare(j1.weight, j2.weight));
        Arrays.sort(bag);

        PriorityQueue<Jewelry> pq = new PriorityQueue<>((j1, j2) -> Integer.compare(j2.price, j1.price));

        int idx = 0;
        for(int i = 0; i < K; i++) {
            while (idx < N && jewelries[idx].weight <= bag[i]) {
                pq.add(jewelries[idx]);
                idx++;
            }
            if (!pq.isEmpty()) {
                ans += pq.poll().price;
            }
        }

        System.out.println(ans);
    }

}

class Jewelry{
    int weight;
    int price;

    public Jewelry(int weight, int price) {
        this.weight = weight;
        this.price = price;
    }
}