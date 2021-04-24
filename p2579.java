import java.util.Scanner;

public class p2579 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cnt = sc.nextInt();
        int[] score = new int[cnt + 1];
        int[] dp = new int[cnt + 1];

        for(int i = 1; i <= cnt; i++){
            score[i] = sc.nextInt();
        }

        dp[0] = 0;
        dp[1] = score[1];

        if(cnt >= 2){
            dp[2] = score[1] + score[2];
        }
        
        for(int i = 3; i <= cnt; i++){
            dp[i] = Math.max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
        }

        System.out.println(dp[cnt]);
    }    
}
