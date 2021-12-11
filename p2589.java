import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class p2589 {
    public static int N;
    public static int M;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static char[][] map;
    public static ArrayList<int[]> lPos = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < M; j++){
                map[i][j] = str.charAt(j);
                if(map[i][j] == 'L') lPos.add(new int[]{i, j});
            }
        }

        int res = 0;
        for(int[] pos : lPos){
            res = Math.max(res, getDist(pos[0], pos[1]));
        }

        System.out.println(res);
    }

    public static int getDist(int y, int x){
        Queue<int[]> q = new LinkedList<>();
        int[][] visited = new int[N][M];
        visited[y][x] = 1;
        q.add(new int[]{y, x});
        int ret = 0;

        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();
            ret = Math.max(visited[y][x], ret);
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(visited[ny][nx] == 0 && map[ny][nx] == 'L'){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.add(new int[]{ny, nx});
                }
            }
        }
        
        return ret - 1;
    }
}
