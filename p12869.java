import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p12869 {
    public static int N;
    public static int[] scv = new int[3];
    public static ArrayList<int[]> dmgs = new ArrayList<>();
    public static int[][][] dp = new int[61][61][61];

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for(int i = 0; i < N; i++){
            scv[i] = sc.nextInt();
        }

        dmgs = new ArrayList<>();
        makePermutation(new int[]{9, 3, 1}, 0);

        System.out.println(go());
    }

    public static void makePermutation(int[] dmg, int depth){
        if(depth == 3){
            dmgs.add(dmg.clone());
            return;
        }

        for(int i = depth; i < 3; i++){
            swap(dmg, depth, i);
            makePermutation(dmg, depth + 1);
            swap(dmg, depth, i);
        }
    }

    public static void swap(int[] dmg, int depth, int idx){
        int tmp = dmg[depth];
        dmg[depth] = dmg[idx];
        dmg[idx] = tmp;
    }

    public static int go(){
        Queue<int[]> q = new LinkedList<>();
        int ret = Integer.MAX_VALUE;
        q.add(new int[]{scv[0], scv[1], scv[2]});
        dp[scv[0]][scv[1]][scv[2]] = 1;

        while(!q.isEmpty()){
            int s1 = q.peek()[0];
            int s2 = q.peek()[1];
            int s3 = q.peek()[2];
            q.poll();
            
            for(int i = 0; i < dmgs.size(); i++){
                int ns1 = Math.max(0, s1 - dmgs.get(i)[0]);
                int ns2 = Math.max(0, s2 - dmgs.get(i)[1]);
                int ns3 = Math.max(0, s3 - dmgs.get(i)[2]);
                if(dp[ns1][ns2][ns3] != 0) continue;
                dp[ns1][ns2][ns3] = dp[s1][s2][s3] + 1;
                if(ns1 == 0 && ns2 == 0 && ns3 == 0) ret = Math.min(ret, dp[0][0][0]);
                q.add(new int[]{ns1, ns2, ns3});
            }
        }

        return dp[0][0][0] - 1;
    }
}
