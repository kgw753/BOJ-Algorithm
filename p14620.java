import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p14620 {
    public static int N;
    public static int res = Integer.MAX_VALUE;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] cost;
    public static boolean[][] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        cost = new int[N][N];
        visited = new boolean[N][N];

        for(int i = 0; i < N; i++){
            String[] input = br.readLine().split(" ");

            for(int j = 0; j < N; j++){
                cost[i][j] = Integer.parseInt(input[j]);
            }
        }

        go(0, 0);

        System.out.println(res);
    }

    public static void go(int depth, int sum){
        if(depth == 3) {
            res = Math.min(res, sum);
            return;
        }

        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < N - 1; j++){
                if(isValid(i, j)){
                    setVisited(i, j);
                    go(depth + 1, sum + getCost(i, j));
                    setVisited(i, j);
                }
            }
        }
    }

    public static int getCost(int y, int x){
        int ret = cost[y][x];

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) return -1;

            ret += cost[ny][nx];
        }

        return ret;
    }

    public static void setVisited(int y, int x){
        visited[y][x] = !visited[y][x];
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            visited[ny][nx] = !visited[ny][nx];
        }
    }

    public static boolean isValid(int y, int x){
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(visited[ny][nx]) return false;
        }
                
        return !visited[y][x];
    }
}
