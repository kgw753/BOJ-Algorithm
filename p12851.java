import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p12851 {
    public static int MAX = Integer.MAX_VALUE;
    public static int N;
    public static int K;
    public static int[] visited;
    public static int res;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        visited = new int[100004];
        Arrays.fill(visited, MAX);

        bfs(N);

        System.out.println(visited[K]);
        System.out.println(res);
    }

    public static void bfs(int pos){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{pos, 0});
        int cnt;

        while(!q.isEmpty()){
            pos = q.peek()[0];
            cnt = q.peek()[1];
            q.poll();

            if(visited[pos] == MAX) visited[pos] = cnt;
            if(pos == K && cnt == visited[pos]) res++;

            if(pos - 1 >= 0 && visited[pos - 1] >= cnt) q.add(new int[]{pos - 1, cnt + 1});
            if(pos + 1 < 100001 && visited[pos + 1] >= cnt) q.add(new int[]{pos + 1, cnt + 1});
            if(pos * 2 < 100001 && visited[pos * 2] >= cnt) q.add(new int[]{pos * 2, cnt + 1});
        }
    }

}
