import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p2138 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        String input1 = br.readLine();
        String input2 = br.readLine();
        boolean[] now1 = new boolean[N];
        boolean[] now2 = new boolean[N];
        boolean[] want = new boolean[N];

        for(int i = 0; i < N; i++){
            now1[i] = input1.charAt(i) == '0' ? false : true;
            now2[i] = input1.charAt(i) == '0' ? false : true;
            want[i] = input2.charAt(i) == '0' ? false : true;
        }

        int cnt1 = 1;
        int cnt2 = 0;
        now1[0] = !now1[0];
        now1[1] = !now1[1];

        for(int i = 1; i < N - 1; i++){
            if(now1[i - 1] != want[i - 1]){
                now1[i - 1] = !now1[i - 1]; 
                now1[i] = !now1[i];
                now1[i + 1] = !now1[i + 1];
                cnt1++;
            }
            if(now2[i - 1] != want[i - 1]){
                now2[i - 1] = !now2[i - 1]; 
                now2[i] = !now2[i];
                now2[i + 1] = !now2[i + 1];
                cnt2++;
            }
        }

        if(now1[N - 2] != want[N - 2]){
            now1[N - 2] = !now1[N - 2];
            now1[N - 1] = !now1[N - 1];
            cnt1++;
        }

        if(now2[N - 2] != want[N - 2]){
            now2[N - 2] = !now2[N - 2];
            now2[N - 1] = !now2[N - 1];
            cnt2++;
        }

        int INF = (int)1e9;
        for(int i = 0; i < N; i++){
            if(now1[i] != want[i]) cnt1 = INF;
            if(now2[i] != want[i]) cnt2 = INF;
        }

        if(cnt1 == INF && cnt2 == INF) System.out.println(-1);
        else System.out.println(Math.min(cnt1, cnt2));
    }
    
}
