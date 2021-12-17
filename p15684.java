import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p15684 {
    public static int N, M, H;
    public static int res = Integer.MAX_VALUE;
    public static int[][] map;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        H = Integer.parseInt(input[2]);
        map = new int[H][N];
        
        int a, b;
        for(int i = 0; i < M; i++){
            input = br.readLine().split(" ");
            a = Integer.parseInt(input[0]) - 1;
            b = Integer.parseInt(input[1]) - 1;
            map[a][b] = 1;
            map[a][b + 1] = -1;
        }

        dfs(0, 0);

        if(res == Integer.MAX_VALUE) res = -1;
        System.out.println(res);
    }

    public static void dfs(int here, int cnt){
        if(cnt > 3 || cnt >= res) return;
        if(check()){
            res = cnt;
            return;
        }
        
        for(int i = here; i < N - 1; i++){
            
            for(int j = 0; j < H; j++){
                if(map[j][i] != 0 || map[j][i + 1] != 0) continue;
                
                map[j][i] = 1;
                map[j][i + 1] = -1;

                dfs(i, cnt + 1);

                map[j][i] = map[j][i + 1] = 0;
            }
        }
    }

    public static boolean check(){

        for(int i = 0; i < N; i++){
            
            int start = i;

            for(int j = 0; j < H; j++){
                start += map[j][start];
            }

            if(start != i) return false;
        }

        return true;
    }
}
