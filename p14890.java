import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p14890 {
    public static int N, L, res;
    public static int[][] map1, map2;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        map1 = new int[N][N];
        map2 = new int[N][N];

        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            
            for(int j = 0; j < N; j++){
                map1[i][j] = Integer.parseInt(input[j]);
                map2[j][i] = map1[i][j];
            }
        }

        go(map1);
        go(map2);

        System.out.println(res);
    }

    public static void go(int[][] map){
        for(int[] road : map){
            int cnt = 1;
            int i;
            for(i = 0; i < N - 1; i++){
                if(road[i] == road[i + 1]) cnt++;
                else if(road[i] + 1 == road[i + 1] && cnt >= L) cnt = 1;
                else if(road[i] - 1 == road[i + 1] && cnt >= 0) cnt = -L + 1;
                else break;
            }
            
            if(i == N - 1 && cnt >= 0) res++;
        }
    }
}
