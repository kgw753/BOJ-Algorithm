import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p13244 {
    public static BufferedReader br;
    public static BufferedWriter bw;
    public static int T, N, E;
    public static boolean[] visited;
    public static List<List<Integer>> tree;
    public static void main(String[] args) throws IOException{
        init();

        while(T-- > 0){
            tree = new ArrayList<>();
            Arrays.fill(visited, false);
            N = Integer.parseInt(br.readLine());
            E = Integer.parseInt(br.readLine());

            for(int i = 0; i < N + 1; i++){
                tree.add(new ArrayList<>());
            }
            
            int a, b;
            for(int i = 0; i < E; i++){
                String[] input = br.readLine().split(" ");
                a = Integer.parseInt(input[0]);
                b = Integer.parseInt(input[1]);

                tree.get(a).add(b);
                tree.get(b).add(a);
            }

            int cnt = 0;
            for(int i = 1; i <= N; i++){
                if(visited[i]) continue;
                dfs(i);
                cnt++;
            }

            if(cnt == 1 && N == E + 1) bw.write("tree\n");
            else bw.write("graph\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        T = Integer.parseInt(br.readLine());
        visited = new boolean[1004];
    }

    public static void dfs(int node){
        visited[node] = true;

        for(int next : tree.get(node)){
            if(visited[next]) continue;
            dfs(next);
        }
    }
}