import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p2178{
    public static int N, M;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static boolean[][] map;
    public static int[][] visited;
    public static BufferedReader br;
    public static void main(String[] args)throws IOException{
        init();
        bfs();
        System.out.println(visited[N - 1][M - 1]);
    }
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] numbers = br.readLine().split(" ");
        N = Integer.parseInt(numbers[0]);
        M = Integer.parseInt(numbers[1]);
        map = new boolean[N][M];
        visited = new int[N][M];

        String input;

        for(int i = 0; i < N; i++){
            input = br.readLine();

            for(int j = 0; j < M; j++){
                if(input.charAt(j) == '1') map[i][j] = true;
            }
        }
    }

    public static void bfs(){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = 1;

        int y, x;
        while(!q.isEmpty()){
            y = q.peek()[0];
            x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(map[ny][nx] && visited[ny][nx] == 0){
                    q.add(new int[]{ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }
    }
}