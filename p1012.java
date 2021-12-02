import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1012 {
    public static int tc;
    public static int N;
    public static int M;
    public static int count;
    public static int[][] map;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            int res = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            count = Integer.parseInt(st.nextToken());
            map = new int[N][M];
            int x, y;
            for(int i = 0; i < count; i++){
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                map[y][x] = 1;
            }
            
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(map[i][j] == 1) {
                        dfs(i, j);
                        res++;
                    }
                }
            }
            System.out.println(res);
        }
    }
    public static void dfs(int y, int x){
        map[y][x]++;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 1) continue;
            dfs(ny, nx);
        }
    }
}
