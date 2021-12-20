import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p13913 {
    public static int N, K, res;
    public static int[] visited = new int[100004];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        Arrays.fill(visited, Integer.MAX_VALUE);

        bfs();

        System.out.println(visited[K]);
        print(K);
    }

    public static void bfs(){
        int pos, cnt;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{N, 0});

        while(!q.isEmpty()){
            pos = q.peek()[0];
            cnt = q.peek()[1];
            q.poll();

            if(visited[pos] == Integer.MAX_VALUE){
                visited[pos] = cnt;
            }
            if(pos == K && visited[pos] == cnt){
                res++;
            }

            if(pos - 1 >= 0 && visited[pos] >= cnt) q.add(new int[]{pos - 1, cnt + 1});
            if(pos + 1 <= 100000 && visited[pos] >= cnt) q.add(new int[]{pos + 1, cnt + 1});
            if(pos * 2 <= 100000 && visited[pos] >= cnt) q.add(new int[]{pos * 2, cnt + 1});
        }
    }

    public static void print(int idx){
        if(visited[idx] == 0){
            System.out.print(idx + " ");
            return;
        }
        else {
            if(idx - 1 >= 0 && visited[idx - 1] == visited[idx] - 1) print(idx - 1);
            else if(idx + 1 <= 100000 && visited[idx + 1] == visited[idx] - 1) print(idx + 1);
            else if(visited[idx / 2] == visited[idx] - 1) print(idx / 2);
        }
        System.out.print(idx + " ");
    }
}
