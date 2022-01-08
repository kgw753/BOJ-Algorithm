import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class p1931 {
    public static BufferedReader br;
    public static int N;
    public static PriorityQueue<int[]> pq;
    public static void main(String[] args) throws IOException{
        init();

        int e, cnt;
        e = cnt = 0;
        while(!pq.isEmpty()){
            int ns = pq.peek()[0];
            int ne = pq.peek()[1];
            pq.poll();
            
            if(ns < e) continue;
            e = ne;
            cnt++;
        }

        System.out.println(cnt);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        pq = new PriorityQueue<int[]>(new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                if(a[1] == b[1]) return a[0] - b[0];
                else return a[1] - b[1];
            }
        });

        String[] input;
        int s, e;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            s = Integer.parseInt(input[0]);
            e = Integer.parseInt(input[1]);

            pq.add(new int[]{s, e});
        }
    }
}
