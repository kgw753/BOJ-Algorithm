import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p2636 {
    public static int N;
    public static int M;
    public static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};
    public static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
    public static int[][] cheese;
    public static int[][] nextCheese;
    public static boolean[][] visited;
    public static int cnt;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        cheese = new int[N][M];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                cheese[i][j] = Integer.parseInt(st.nextToken());
                if(cheese[i][j] == 1) cnt++;
            }
        }
        int lastCnt = 0;
        int time = 0;
        while(cnt > 0){
            lastCnt = cnt;
            melt();
            time++;
        }
        System.out.format("%d\n%d\n", time, lastCnt);
    }

    public static void melt(){
        ArrayList<int[]> startPos = getStartPos();

        for(int i = 0; i < startPos.size(); i++){
            int y = startPos.get(i)[0];
            int x = startPos.get(i)[1];
            nextCheese = cloning(cheese);
            go(y, x, 0);
            cheese = cloning(nextCheese);
        }
    }
    
    public static ArrayList<int[]> getStartPos(){
        ArrayList<int[]> ret = new ArrayList<>();
        visited = new boolean[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j] && cheese[i][j] == 1){
                    ret.add(new int[]{i, j});
                    dfs(i, j);
                }
            }
        }
        return ret;
    }

    public static void dfs(int y, int x){
        visited[y][x] = true;

        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(posCheck(ny, nx) && !visited[ny][nx] && cheese[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
    }

    public static void go(int sy, int sx, int dir){
        int y = sy;
        int x = sx;
        int ny = -1;
        int nx = -1;
        while(true){
            if(nextCheese[y][x] == 1) cnt--;
            nextCheese[y][x] = 0;
            dir = (dir + 6) % 8;
            for(int i = 0; i < 8; i++){
                ny = y + dy[dir];
                nx = x + dx[dir];
                if(posCheck(ny, nx) && cheese[ny][nx] == 1) break;
                dir = (dir + 1) % 8;
            }
            y = ny;
            x = nx;
            if(sx == x && sy == y) break;
        }
    }

    public static boolean posCheck(int y, int x){
        return (y >= 0 && x >= 0 && y < N && x < M);
    }

    public static int[][] cloning(int[][] arr){
        int[][] ret = new int[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                ret[i][j] = arr[i][j];
            }
        }
        return ret;
    }
}
