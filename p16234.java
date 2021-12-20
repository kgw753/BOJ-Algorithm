import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class p16234 {
    public static boolean moved = true;
    public static int N, L, R, cnt;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] map;
    public static boolean[][] visited;
    public static ArrayList<int[]> pos;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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
            cnt++;
        }

        System.out.println(cnt);
    }

    public static void dfs(int y, int x){
        pos.add(new int[]{y, x});
        visited[y][x] = true;

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
            if(gapCheck(map[y][x], map[ny][nx])){
                dfs(ny, nx);
            }
        }
    }

    public static boolean gapCheck(int v1, int v2){
        int gap = Math.abs(v1 - v2);
        return gap >= L && gap <= R;
    }

    public static int getPeople(){
        int ret = 0;

        for(int[] p : pos){
            ret += map[p[0]][p[1]];
        }

        return ret / pos.size();
    }

    public static void move(int people){
        for(int[] p : pos){
            map[p[0]][p[1]] = people;
        }
    }
}