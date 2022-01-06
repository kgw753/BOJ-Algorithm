import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class p14469 {
    public static int N;
    public static PriorityQueue<int[]> pq;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();

        int time = 0;
        int[] cowInfo;
        while(!pq.isEmpty()){
            cowInfo = pq.poll();

            time = Math.max(time, cowInfo[0]) + cowInfo[1];
        }

        System.out.println(time);
    }

    public static void init() throws IOException{
        pq = new PriorityQueue<>(new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                return arr1[0] - arr2[0];
            }
        });

        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        int a, b;
        String[] input;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);

            pq.add(new int[]{a, b});
        }
    }
}
