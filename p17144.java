import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class p17144 {
    public static int N, M, T;
    public static int airCleaner;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};
    public static int[][] map, nmap;
    public static BufferedReader br;

    public static void main(String[] args) throws IOException{
        init();

        while(T-- > 0){
            goDust();
            cycleAir();
        }

        int sum = getSum();
        System.out.println(sum);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        map = new int[N][M];

        airCleaner = -1;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(airCleaner == -1 && map[i][j] == -1) airCleaner = i;
            }
        }
    }

    public static void goDust(){
        nmap = new int[N][M];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == -1) {
                    nmap[i][j] = -1;
                }
                else if(map[i][j] > 0){
                    int cnt = getCnt(i, j);
                    nmap[i][j] += map[i][j] - (map[i][j] / 5) * cnt;
                }
            }
        }

        map = nmap;
    }

    public static int getCnt(int y, int x){
        int ret = 0;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == -1) continue;
            nmap[ny][nx] += map[y][x] / 5; 
            ret++;
        }
        return ret;
    }

    public static void cycleAir(){

        int prev = 0;
        int now;

        for(int i = 1; i < M; i++){
            now = map[airCleaner][i];
            map[airCleaner][i] = prev;
            prev = now;
        }

        for(int i = airCleaner - 1; i >= 0; i--){
            now = map[i][M - 1];
            map[i][M - 1] = prev;
            prev = now;
        }

        for(int i = M - 2; i >= 0; i--){
            now = map[0][i];
            map[0][i] = prev;
            prev = now;
        }

        for(int i = 1; i < airCleaner; i++){    //
            now = map[i][0];
            map[i][0] = prev;
            prev = now;
        }

        prev = 0;

        // down
        for(int i = 1; i < M; i++){
            now = map[airCleaner + 1][i];
            map[airCleaner + 1][i] = prev;
            prev = now;
        }

        for(int i = airCleaner + 2; i < N; i++){
            now = map[i][M - 1];
            map[i][M - 1] = prev;
            prev = now;
        }

        for(int i = M - 2; i >= 0; i--){
            now = map[N - 1][i];
            map[N - 1][i] = prev;
            prev = now;
        }

        for(int i = N - 2; i > airCleaner + 1; i--){
            now = map[i][0];
            map[i][0] = prev;
            prev = now;
        }

    }

    public static int getSum(){
        int ret = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == -1) continue;
                ret += map[i][j];
            }
        }
        return ret;
    }
}