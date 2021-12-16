import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p14497 {
    public static int N;
    public static int M;
    public static int[] jnPos = new int[2];
    public static int[] targetPos = new int[2];
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static char[][] map;
    public static boolean[][] visited;

    public static Queue<int[]> q = new LinkedList<>();

    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new char[N][M];
        visited = new boolean[N][M];

        input = br.readLine().split(" ");
        jnPos[0] = Integer.parseInt(input[0]) - 1;
        jnPos[1] = Integer.parseInt(input[1]) - 1;
        q.add(jnPos);

        visited[jnPos[0]][jnPos[1]] = true;

        targetPos[0] = Integer.parseInt(input[2]) - 1;
        targetPos[1] = Integer.parseInt(input[3]) - 1;

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
        }
        int cnt = 0;
        while(!visited[targetPos[0]][targetPos[1]]){
            bfs();
            cnt++;
        }

        System.out.println(cnt);
    }

    public static void bfs(){
        Queue<int[]> tmp = new LinkedList<>();

        while(!q.isEmpty()){
            int y = q.peek()[0];
            int x = q.peek()[1];
            q.poll();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;

                visited[ny][nx] = true;

                if(map[ny][nx] == '0') q.add(new int[]{ny, nx});
                else if(map[ny][nx] == '1') tmp.add(new int[]{ny, nx});
                else if(map[ny][nx] == '#') return;
            }
        }

        q = tmp;
    }
}
