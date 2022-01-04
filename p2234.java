import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p2234 {
    public static int cnt, mx, mx2;
    public static int N, M, tmp;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[] dir = {4, 8, 1, 2};
    public static int[][] map;
    public static boolean[][] visited;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);
        map = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");

            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j]){
                    cnt++;
                    dfs(i, j);
                    mx = Math.max(mx, tmp);
                    tmp = 0;
                }
            }
        }

        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){

                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                    if((dir[i] & map[y][x]) == 0) continue;
                    visited = new boolean[N][M];

                    map[y][x] -= dir[i];

                    dfs(y, x);
                    mx2 = Math.max(mx2, tmp);
                    tmp = 0;

                    map[y][x] += dir[i];
                }
            }
        }

        System.out.println(cnt);
        System.out.println(mx);
        System.out.println(mx2);
    }

    public static void dfs(int y, int x){
        visited[y][x] = true;
        tmp++;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
            if(noBarrier(dir[i], map[y][x])){
                dfs(ny, nx);
            }
        }
    }

    public static boolean noBarrier(int d, int room){
        return (d & room) == 0;
    }


}
