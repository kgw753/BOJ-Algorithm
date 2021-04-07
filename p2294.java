import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class p2294 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String firstLine = br.readLine();
        int n = Integer.parseInt(firstLine.split(" ")[0]);
        int m = Integer.parseInt(firstLine.split(" ")[1]);

        int[] money = new int[n];
        int[] dp = new int[m + 1];
        for (int i = 0; i < n; i++) {
            money[i] = Integer.parseInt(br.readLine());
        }

        Arrays.fill(dp, 10001);
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = money[i]; j < m + 1; j++){
                if(j % money[i] != 10001){
                    dp[j] = Math.min(dp[j], dp[j - money[i]] + 1);
                }
            }
        }

        if (dp[m] == 10001) {
            dp[m] = -1;
        }
        System.out.println(dp[m]);
    }
}
