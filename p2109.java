import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class p2109 {
    public static BufferedReader br;
    public static int N;
    public static boolean[] visited;
    public static PriorityQueue<Integer> pq;
    public static List<int[]> list;
    public static void main(String[] args) throws IOException{
        init();

        Collections.sort(list, new Comparator<int[]>(){
            @Override
            public int compare(int[] a1, int[] a2){
                if(a1[1] == a2[1]) return a2[0] - a1[0];
                else return a1[1] - a2[1];
            }
        });

        for(int[] arr : list){
            int p = arr[0];
            int d = arr[1];
            
            pq.add(p);
            if(pq.size() > d){
                pq.poll();
            }
        }
        
        int amount = 0;

        while(!pq.isEmpty()){
            amount += pq.poll();
        }

        System.out.println(amount);
    }
    
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        list = new ArrayList<>();
        pq = new PriorityQueue<>();
        N = Integer.parseInt(br.readLine());
        visited = new boolean[10004];

        int p, d;
        String[] input;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            p = Integer.parseInt(input[0]);
            d = Integer.parseInt(input[1]);

            list.add(new int[]{p, d});
        }
    }
}
