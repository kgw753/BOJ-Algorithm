import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1987 {
    public static int N, M, res;
    public static boolean[] visited = new boolean['Z' - 'A' + 1];
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static char[][] map;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
        }

        dfs(0, 0, 1);

        System.out.println(res);
    }

    public static void dfs(int y, int x, int depth){
        char c = map[y][x];
        if(visited[c - 'A']) return;
        visited[c - 'A'] = true;
        res = Math.max(res, depth);

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            dfs(ny, nx, depth + 1);
        }
        visited[c - 'A'] = false;
    }
}