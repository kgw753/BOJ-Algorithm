import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1189 {
    public static int R;
    public static int C;
    public static int K;
    public static int res;
    public static int dy[] = {0, 1, 0, -1};
    public static int dx[] = {1, 0, -1, 0};
    public static char[][] map;
    public static int[][] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);    

        map = new char[R][C];
        visited = new int[R][C];
        
        for(int i = 0; i < R; i++){
            map[i] = br.readLine().toCharArray();
        }

        visited[R - 1][0] = 1;
        System.out.println(go(R - 1, 0));
    }

    public static int go(int y, int x){
        if(visited[y][x] == K){
            if(y == 0 && x == C - 1) return 1;
            else return 0;
        }
        
        int ret = 0;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= R || nx >= C ||
                visited[ny][nx] != 0 || map[ny][nx] == 'T') continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            ret += go(ny, nx);
            visited[ny][nx] = 0;
        }

        return ret;
    }
}
