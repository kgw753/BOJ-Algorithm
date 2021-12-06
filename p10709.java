import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p10709 {
    public static int N;
    public static int M;
    public static int[][] map;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] idx = br.readLine().split(" ");
        N = Integer.parseInt(idx[0]);
        M = Integer.parseInt(idx[1]);
        map = new int[N][M];

        for(int i = 0; i < N; i++){
            String input = br.readLine();
            for(int j = 0; j < M; j++){
                if(input.charAt(j) == 'c') map[i][j] = 0;
                else map[i][j] = -1;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M - 1; j++){
                if(map[i][j] == -1) continue;
                else if(map[i][j + 1] == -1) map[i][j + 1] = map[i][j] + 1;
                else map[i][j + 1] = Math.min(map[i][j] + 1, map[i][j + 1]);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}
