import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p15686{
    public static int N;
    public static int M;
    public static int[][] map;
    public static ArrayList<int[]> chicken;
    public static ArrayList<int[]> home;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new int[N][N];

        home = new ArrayList<>();
        chicken = new ArrayList<>();

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1) home.add(new int[]{i, j});
                else if(map[i][j] == 2) chicken.add(new int[]{i, j});
            }
        }
        
        int ans = Integer.MAX_VALUE;
        for(int i = 1; i < (1 << chicken.size()); i++){
            if(overCnt(i)) continue;
            ans = Math.min(ans, getDist(i));
        }
        System.out.println(ans);
    }

    public static boolean overCnt(int bm){
        int cnt = 0;
        while(bm > 0){
            if(bm % 2 == 1) cnt++;
            bm /= 2;
        }
        return cnt > M;
    }

    public static int getDist(int bm){
        int ret = 0;
        for(int i = 0; i < home.size(); i++){
            int dist = Integer.MAX_VALUE;
            for(int j = 0; j < chicken.size(); j++){
                if((bm & (1 << j)) == 0) continue;
                int yDist = Math.abs(chicken.get(j)[0] - home.get(i)[0]);
                int xDist = Math.abs(chicken.get(j)[1] - home.get(i)[1]);
                int nowDist = yDist + xDist;
                dist = Math.min(dist, nowDist);
            }
            ret += dist;
        }
        return ret;
    }
}