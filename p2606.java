import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p2606 {
    public static int N;
    public static int cnt;
    public static boolean [][] graph;
    public static boolean [] searched;
    public static void DFS(int idx){
        searched[idx] = true;
        for(int i = 0; i < N; i++){
            if(graph[idx][i] && !searched[i]){
                cnt++;
                DFS(i);
            }
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int conn = Integer.parseInt(br.readLine());
        graph = new boolean[N][N];
        searched = new boolean[N];
        cnt = 0;
        for(int i = 0; i < conn; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            graph[from][to] = true;
            graph[to][from] = true;
        }
        DFS(0);
        System.out.println(cnt);
    }
}
