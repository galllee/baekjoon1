import java.util.Scanner;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
    private static int n, m, v;
    private static int v1, v2;
    private static boolean [][] array;
    private static boolean [] visited;
    private static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();
        
        array = new boolean[n][n];
        visited = new boolean[n];

        for(int i = 0; i < m; i++){
            v1 = sc.nextInt();
            v2 = sc.nextInt();
            v1--;
            v2--;
            array[v1][v2] = true;
            array[v2][v1] = true;
            //이차원 인접 행렬을 사용하여 그래프를 나타내는 방식
        }

        dfs(v - 1);
        System.out.println();
        Arrays.fill(visited, false);
        bfs(v - 1);
    }

    private static void dfs(int idx){
        System.out.print(idx + 1 + " ");
        visited[idx] = true;
        for (int i = 0; i < n; i++){
            if (!visited[i] && array[idx][i]){
                dfs(i);
            }
        }
    }

    private static void bfs(int idx){
        if (!visited[idx]){
            System.out.print(idx + 1 + " ");
            visited[idx] = true;
        }
        for(int i = 0; i < n; i++){
            if (!visited[i] && array[idx][i]){
                System.out.print(i + 1 + " ");
                visited[i] = true;
                q.add(i);
            }
        }
        if (!q.isEmpty())
            bfs(q.poll());
    }
}
