import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class p1003 {
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int tc = Integer.parseInt(br.readLine());
        int[][] dp = new int[41][2];
        ArrayList<int[]> ans = new ArrayList<>();

        dp[0][0] = 1;
        dp[0][1] = 0;

        dp[1][0] = 0;
        dp[1][1] = 1;

        for(int i = 2; i < 41; i++){
            dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }

        for(int i = 0; i < tc; i++){
            int n = Integer.parseInt(br.readLine());
            ans.add(new int[]{dp[n][0], dp[n][1]});
        }

        for(int a[] : ans){
            bw.write(a[0] + " " + a[1] + "\n");
        }
        bw.flush();
        bw.close();
    }
}
