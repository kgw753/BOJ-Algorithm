import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p12851 {
    public static final int SIZE = 100004;
    public static int N, K, cnt, minTime = Integer.MAX_VALUE;
    public static boolean[] visited = new boolean[SIZE];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        if(N > K){
            System.out.format("%d\n%d\n", N - K, 1);
        }
        else{
            bfs();
            System.out.format("%d\n%d\n", minTime, cnt);
        }
    }

    public static void bfs(){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{N, 0});
        int pos, time;

        while(!q.isEmpty()){
            pos = q.peek()[0];
            time = q.peek()[1];
            q.poll();

            visited[pos] = true;
            
            if(pos == K){
                minTime = Math.min(minTime, time);
                if(minTime == time) cnt++;
                continue;
            }

            for(int i = 0; i < 3; i++){
                int nPos = getPos(pos, i);

                if(!posCheck(nPos) || visited[nPos]) continue;
                q.add(new int[]{nPos, time + 1});
            }
        }
    }

    public static int getPos(int pos, int i){
        if(i == 0) return pos - 1;
        else if(i == 1) return pos + 1;
        else return pos * 2;
    }

    public static boolean posCheck(int pos){
        return pos >= 0 && pos <= 100000;
    }
}