import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p13244 {
    public static int T, N, M;
    public static boolean[] visited;
    public static List<Integer> map[];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            N = Integer.parseInt(br.readLine());
            M = Integer.parseInt(br.readLine());

            map = new ArrayList[N + 1];
            visited = new boolean[N + 1];
            Arrays.fill(map, new ArrayList<>());

            String[] input;
            int from, to;
            for(int i = 0; i < M; i++){
                input = br.readLine().split(" ");
                from = Integer.parseInt(input[0]);
                to = Integer.parseInt(input[1]);

                map[from].add(to);
                map[to].add(from);
            }
            
            int cnt = 0;

            for(int i = 1; i <= N; i++){
                if(!visited[i]) {
                    dfs(i);
                    cnt++;
                }
                
            }

            if(cnt == 1 && N - 1 == M) {
                bw.write("tree\n");
            } else {
                bw.write("graph\n");
            }
        }


        bw.flush();

        br.close();
        bw.close();
    }

    public static void dfs(int node){
        visited[node] = true;

        for(int next : map[node]){
            if(!visited[next]) dfs(next);
        }
    }
}
