import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class p14889 {
    public static int N, mn = Integer.MAX_VALUE;
    public static int[][] stat;
    public static BufferedReader br;
    public static List<Integer> team1, team2;
    public static void main(String[] args) throws IOException{
        init();

        int[] scr = new int[2];
        for(int i = 1; i < (1 << N); i++){

            getTeam(i);
            if(team1.size() != N / 2) continue;
            scr = getScr(i);
            mn = Math.min(mn, Math.abs(scr[0] - scr[1]));
        }

        System.out.println(mn);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        stat = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++){
                stat[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void getTeam(int bm){
        team1 = new ArrayList<>();
        team2 = new ArrayList<>();

        for(int i = 0; i < N; i++){
            if((bm & (1 << i)) == 0) team1.add(i);
            else team2.add(i);
        }
    }
    public static int[] getScr(int bm){
        int[] scr = new int[2];

        for(int i = 0; i < N / 2; i++){
            for(int j = 0; j < N / 2; j++){
                scr[0] += stat[team1.get(i)][team1.get(j)];
                scr[1] += stat[team2.get(i)][team2.get(j)];
            }
        }
        
        return scr;
    }
}
