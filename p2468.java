import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class p2468{
    public static final int[] dx = {1, 0, -1, 0};
    public static final int[] dy = {0, 1, 0, -1};

    public static int N;
    public static int mx;
    public static int ans;
    public static int [][] map;
    public static boolean [][] visited;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                mx = Math.max(mx, map[i][j]);
            }
        }
        
        for(int i = 0; i < mx; i++){
            ans = Math.max(ans, count(i));
        }

        System.out.println(ans);
    }

    public static int count(int h){
        int ret = 0;
        visited = new boolean[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && map[i][j] > h){
                    bfs(i, j, h);
                    ret++;
                }
            }
        }
        return ret;
    }

    public static void bfs(int y, int x, int h){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{y, x});
        visited[y][x] = true;

        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(!visited[ny][nx] && map[ny][nx] > h){
                    visited[ny][nx] = true;
                    q.add(new int[]{ny, nx});
                }
            }
        }
    }
}