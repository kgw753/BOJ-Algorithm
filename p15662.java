import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class p15662 {
    public static int N, K;
    public static boolean[] visited;
    public static int[][] wheels;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();

        K = Integer.parseInt(br.readLine());
        String[] input;
        int idx, dir;
        while(K-- > 0){
            input = br.readLine().split(" ");
            idx = Integer.parseInt(input[0]);
            dir = Integer.parseInt(input[1]);

            rotate(idx - 1, dir);
            Arrays.fill(visited, false);
        }

        int ans = 0;

        for(int[] wheel : wheels){
            if(wheel[0] == 1) ans++;
        }
        System.out.println(ans);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        wheels = new int[N][8];
        visited = new boolean[N];

        String wheel;
        for(int i = 0; i < N; i++){
            wheel = br.readLine();

            for(int j = 0; j < 8; j++){
                wheels[i][j] = wheel.charAt(j) - '0';
            }
        }
    }

    public static void rotate(int here, int dir){

        int[] tmp = new int[8];
        int idx;

        int left = wheels[here][6];
        int right = wheels[here][2];

        for(int i = 0; i < 8; i++){
            idx = (i + dir + 8) % 8;
            tmp[idx] = wheels[here][i];
        }
        wheels[here] = tmp;
        visited[here] = true;

        if(here != 0 && !visited[here - 1] && wheels[here - 1][2] != left){
            rotate(here - 1, dir * -1);
        }
        if(here != N - 1 && !visited[here + 1] && right != wheels[here + 1][6]){
            rotate(here + 1, dir * -1);
        }
    }
}
