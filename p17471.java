import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class p17471 {
    public static int N, res = Integer.MAX_VALUE;
    public static int p1, p2, cnt1, cnt2;
    public static int[] people;
    public static boolean[] group;
    public static boolean[] visited;

    public static ArrayList<ArrayList<Integer>> map = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        people = new int[N + 1];
        String[] input = br.readLine().split(" ");

        for(int i = 0; i < N + 1; i++){
            map.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < N; i++){
            people[i + 1] = Integer.parseInt(input[i]);
        }

        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            int M = Integer.parseInt(input[0]);
            
            for(int j = 1; j <= M; j++){
                map.get(i + 1).add(Integer.parseInt(input[j]));
            }
        }

        for(int i = 1; i < (1 << N) - 1; i++){
            p1 = p2 = cnt1 = cnt2 = 0;
            int s1 = 0, s2 = 0;
            visited = new boolean[N + 1];
            group = new boolean[N + 1];

            for(int idx = 0; idx < N; idx++){
                
                if(((1 << idx) & i) != 0) {
                    group[idx + 1] = true;
                    s1 = idx + 1;
                }
                else{
                    s2 = idx + 1;
                }
            }

            dfs(s1, true);
            dfs(s2, false);

            if(cnt1 + cnt2 != N) continue;

            res = Math.min(res, Math.abs(p1 - p2));
        }
        
        if(res == Integer.MAX_VALUE) res = -1;
        System.out.println(res);
    }

    public static void dfs(int here, boolean groupFlag){
        visited[here] = true;

        if(groupFlag){
            cnt1++;
            p1 += people[here];
        }
        else{
            cnt2++;
            p2 += people[here];
        }

        for(int i = 0; i < map.get(here).size(); i++){
            int there = map.get(here).get(i);
            if(groupFlag == group[there] && !visited[there]) dfs(there, groupFlag);
        }
    }
}
