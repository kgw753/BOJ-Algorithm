import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class p18352 {
    public static final int INF = (int)1e9;
    public static int n, m, k, x;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    public static int[] d;

    public static void dfs(int idx, int cnt){
        if(cnt > k) return;
        for(int i = 0; i < graph.get(idx).size(); i++){
            if(cnt < d[graph.get(idx).get(i)]){
                d[graph.get(idx).get(i)] = cnt;
                dfs(graph.get(idx).get(i), cnt + 1);
            }
        }
    }

    public static void bfs(int start){
        d[start] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);

        while(!q.isEmpty()){
            int now = q.poll();
            for(int i = 0; i < graph.get(now).size(); i++){
                int next = graph.get(now).get(i);
                if(d[next] == INF){
                    q.offer(graph.get(now).get(i));
                    d[graph.get(now).get(i)] = d[now] + 1;
                }
            }
        }
    }
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String input = br.readLine();
        n = Integer.parseInt(input.split(" ")[0]);
        m = Integer.parseInt(input.split(" ")[1]);
        k = Integer.parseInt(input.split(" ")[2]);
        x = Integer.parseInt(input.split(" ")[3]);
        
        d = new int[n + 1];

        for(int i = 1; i <= n; i++){
            d[i] = INF;
        }

        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++){
            input = br.readLine();
            int a = Integer.parseInt(input.split(" ")[0]);
            int b = Integer.parseInt(input.split(" ")[1]);
            graph.get(a).add(b);
        }

        bfs(x);

        ArrayList<Integer> answer = new ArrayList<>();

        for(int i = 1; i <= n; i++){
            if(d[i] == k){
                answer.add(i);
            }
        }

        if(answer.isEmpty()){
            bw.write(-1 + "\n");
        }
        else{
            Collections.sort(answer);
            for(int a: answer){
                bw.write(a + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
