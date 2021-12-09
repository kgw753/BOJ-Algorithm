import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class p1325 {
    public static int N;
    public static int M;
    public static ArrayList<Integer> []tree;
    public static int[] cnt;
    public static boolean[] visited;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        tree = new ArrayList[N + 1];

        for(int i = 1; i <= N; i++){
            tree[i] = new ArrayList<Integer>();
        }

        int A, B;
        for(int i = 0; i < M; i++){
            input = br.readLine().split(" ");
            A = Integer.parseInt(input[0]);
            B = Integer.parseInt(input[1]);
            tree[B].add(A);
        }
        
        cnt = new int[N + 1];
        for(int i = 1; i <= N; i++){
            visited = new boolean[N + 1];
            // dfs(i);
            cnt[i] = bfs(i);
        }
        
        int mx = -1;
        for(int i = 1; i <= N; i++){
            mx = Math.max(mx, cnt[i]);
        }

        StringBuffer sb = new StringBuffer();
        for(int i = 1; i <= N; i++){
            if(cnt[i] == mx) bw.write(i + " ");
        }
        bw.flush();
        bw.close();
    }

    public static void dfs(int idx){
        visited[idx] = true;
        for(int there : tree[idx]){
            if(visited[there]) continue;
            cnt[there]++;
            dfs(there);
        }
    }
    public static int bfs(int start){
        Queue<Integer> q = new LinkedList<>();
        visited = new boolean[N + 1];
        visited[start] = true;
        int ret = 1;
        q.add(start);
        while(!q.isEmpty()){
            int node = q.poll();
            
            for(int there : tree[node]){
                if(!visited[there]){
                    visited[there] = true;
                    ret++;
                    q.add(there);
                }
            }
        }
        return ret;
    }
}
