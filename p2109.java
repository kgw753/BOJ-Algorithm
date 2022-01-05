import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class p2109 {
    public static BufferedReader br;
    public static int N;
    public static boolean[] visited;
    public static PriorityQueue<int[]> pq;
    public static void main(String[] args) throws IOException{
        init();

        int amount = 0;
        while(!pq.isEmpty()){
            int[] now = pq.poll();

            if(!canGo(now[1])) continue;
            else{
                amount += now[0];
            }
        }

        System.out.println(amount);
    }
    
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pq = new PriorityQueue<>(new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                if(arr1[0] == arr2[0]) return arr1[1] - arr2[1];
                else return arr2[0] - arr1[0];
            }
        });
        N = Integer.parseInt(br.readLine());
        visited = new boolean[10004];

        int p, d;
        String[] input;
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");
            p = Integer.parseInt(input[0]);
            d = Integer.parseInt(input[1]);

            pq.add(new int[]{p, d});
        }
    }

    public static boolean canGo(int day){

        for(int i = day; i > 0; i--){
            if(!visited[i]){
                visited[i] = true;
                return true;
            }
        }
        return false;
    }
}
