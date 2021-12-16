import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class p1987 {
    public static int N;
    public static int M;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static char[][] map;
    public static Map<Character, Integer> mp = new HashMap<>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
        }

        System.out.println(dfs(0, 0, 0));
    }

    public static int dfs(int y, int x, int depth){        
        if(mp.containsKey(map[y][x])) return depth;
        mp.put(map[y][x], 1);
        int ret = 0;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            
            ret = Math.max(ret, dfs(ny, nx, depth + 1));
        }
        
        mp.remove(map[y][x]);
        return ret;
    }
}
