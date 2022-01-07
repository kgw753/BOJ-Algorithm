import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class p16234 {
    public static BufferedReader br;
    public static boolean moved;
    public static int N, L, R;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] map;
    public static boolean[][] visited;
    public static List<int[]> pos;
    public static void main(String[] args) throws IOException{
        init();
        int res = 0;

        while(true){
            visited = new boolean[N][N];
            moved = false;

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(visited[i][j]) continue;
                    pos = new ArrayList<>();
                    dfs(i, j);
                    int people = getPeople();
                    move(people);
                    if(pos.size() > 1) moved = true;
                }
            }

            if(!moved) break;
            res++;
        }
        System.out.println(res);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        R = Integer.parseInt(input[2]);
        map = new int[N][N];

        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");

            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
    }

    public static void dfs(int y, int x){
        pos.add(new int[]{y, x});
        visited[y][x] = true;

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
            int gap = Math.abs(map[y][x] - map[ny][nx]);
            if(gap >= L && gap <= R) dfs(ny, nx);
        }
    }

    public static int getPeople(){
        int sum = 0;
        for(int[] p : pos){
            sum += map[p[0]][p[1]];
        }
        return sum / pos.size();
    }

    public static void move(int people){
        for(int[] p : pos){
            map[p[0]][p[1]] = people;
        }
    }
}