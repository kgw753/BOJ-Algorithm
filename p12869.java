import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p12869 {
    public static int N;
    public static int[] scv = new int[3];
    public static int[][][] dp = new int[61][61][61];
    public static ArrayList<int []> seq = new ArrayList<>();

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(sc.nextLine());

        String[] input = sc.nextLine().split(" ");
        for(int i = 0; i < N; i++) {
            scv[i] = Integer.parseInt(input[i]);
        }
        
        makePermutation(new int[]{9, 3, 1}, 0);

        bfs(scv[0], scv[1], scv[2]);

        System.out.println(dp[0][0][0]);
    }

    public static void makePermutation(int[] dmg, int depth){
        if(depth == 3){
            seq.add(dmg.clone());
            return;
        }

        for(int i = depth; i < 3; i++){
            swap(dmg, depth, i);
            makePermutation(dmg, depth + 1);
            swap(dmg, depth, i);
        }
    }

    public static void swap(int[] dmg, int i1, int i2){
        int tmp = dmg[i1];
        dmg[i1] = dmg[i2];
        dmg[i2] = tmp;
    }

    public static void bfs(int s1, int s2, int s3){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{s1, s2, s3});

        while(!q.isEmpty()){
            s1 = q.peek()[0];
            s2 = q.peek()[1];
            s3 = q.peek()[2];
            q.poll();

            for(int[] dmg : seq){
                int ns1 = Math.max(0, s1 - dmg[0]);
                int ns2 = Math.max(0, s2 - dmg[1]);
                int ns3 = Math.max(0, s3 - dmg[2]);

                if(dp[ns1][ns2][ns3] != 0) continue;
                dp[ns1][ns2][ns3] = dp[s1][s2][s3] + 1;
                q.add(new int[]{ns1, ns2, ns3});
            }
        }
    }
}
