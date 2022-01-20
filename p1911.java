import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class p1911 {
    public static int N, L;
    public static List<int[]> holes;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();

        Collections.sort(holes, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                if(a[0] == b[0]) return a[1] - b[1];
                return a[0] - b[0];
            }
        });

        int cnt = 0;
        int mx = 0;
        int ans = 0;

        for(int[] hole : holes){
            if(mx >= hole[1]) continue;
            if(mx < hole[0]){
                cnt = (hole[1] - hole[0]) / L;
                if((hole[1] - hole[0]) % L > 0) cnt++;
                mx = hole[0] + cnt * L;
            }
            else{
                cnt = (hole[1] - mx) / L;
                if((hole[1] - mx) % L > 0) cnt++;
                mx = mx + cnt * L;
            }
            ans += cnt;
        }

        System.out.println(ans);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        holes = new ArrayList<>();
        
        int s, e;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");

            s = Integer.parseInt(input[0]);
            e = Integer.parseInt(input[1]);
            holes.add(new int[]{s, e});
        }
    }
}
