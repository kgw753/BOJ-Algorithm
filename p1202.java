import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class p1202 {
    public static BufferedReader br;
    public static int N, K;
    public static List<Integer> bag;
    public static List<int[]> jw;
    public static void main(String[] args) throws IOException{
        init();

        Collections.sort(bag);
        Collections.sort(jw, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                if(a[0] == b[0]) return b[1] - a[1];
                return a[0] - b[0];
            }
        });

        int jwIdx = 0;
        long sum = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int weight : bag){
            while(jwIdx < N && weight >= jw.get(jwIdx)[0]){
                pq.add(jw.get(jwIdx++)[1]);
            }

            if(!pq.isEmpty()){
                sum += pq.poll();
            }
        }

        System.out.println(sum);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);

        bag = new ArrayList<>();
        jw = new ArrayList<>();

        int m, v;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            m = Integer.parseInt(input[0]);
            v = Integer.parseInt(input[1]);

            jw.add(new int[]{m, v});
        }

        for(int i = 0; i < K; i++){
            bag.add(Integer.parseInt(br.readLine()));
        }
    }
}
