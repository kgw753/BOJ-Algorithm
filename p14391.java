import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class p14391 {
    public static BufferedReader br;
    public static Scanner sc;
    public static int N, M, sum, now, idx;
    public static int[][] map;
    public static void main(String[] args) throws IOException{
        init();

        int ans = 0;
        for(int k = 0; k < (1 << (N * M)); k++){
            sum = 0;

            for(int i = 0; i < N; i++){
                now = 0;
                for(int j = 0; j < M; j++){
                    idx = i * M + j;
                    if((k & (1 << idx)) == 0){
                        now = now * 10 + map[i][j];
                    }
                    else{
                        sum += now;
                        now = 0;
                    }
                }
                sum += now;
            }

            for(int i = 0; i < M; i++){
                now = 0;
                for(int j = 0; j < N; j++){
                    idx = j * M + i;
                    if((k & (1 << idx)) != 0){
                        now = now * 10 + map[j][i];
                    }
                    else{
                        sum += now;
                        now = 0;
                    }
                }
                sum += now;
            }

            ans = Math.max(ans, sum);
        }

        System.out.println(ans);
    }

    public static void init(){
        sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        sc.nextLine();
        map = new int[N][M];

        for(int i = 0; i < N; i++){
            String input = sc.nextLine();

            for(int j = 0; j < M; j++){
                map[i][j] = input.charAt(j) - '0';
            }
        }
    }
}
