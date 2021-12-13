import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class p16234 {
    public static int N;
    public static int L;
    public static int R;
    public static int sum;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] map;
    public static boolean[][] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        R = Integer.parseInt(input[2]);
        map = new int[N][N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;
        while(go()){
            ans++;
        }

        System.out.println(ans);
    }

    public static boolean go(){
        boolean ret = false;
        visited = new boolean[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]) {
                    ArrayList<int []> pos = bfs(i, j);
                    if(pos.size() == 1) continue;
                    ret = true;
                    for(int[] p : pos){
                        map[p[0]][p[1]] = sum / pos.size();
                    }
                }
            }
        }

        return ret;
    }

    public static ArrayList<int[]> bfs(int y, int x){
        ArrayList<int[]> ret = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        ret.add(new int[]{y, x});
        q.add(new int[]{y, x});
        visited[y][x] = true;
        sum = map[y][x];

        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
                if(gapCheck(map[ny][nx], map[y][x])){
                    visited[ny][nx] = true;
                    ret.add(new int[]{ny, nx});
                    q.add(new int[]{ny, nx});
                    sum += map[ny][nx];
                }
            }
        }
        return ret;
    }

    public static boolean gapCheck(int a, int b){
        int gap = Math.abs(a - b);
        return (gap >= L) && (gap <= R);
    }
}
