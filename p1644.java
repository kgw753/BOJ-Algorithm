import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p1644 {
    public static BufferedReader br;
    public static int N;
    public static boolean[] che;
    public static List<Integer> arr;
    public static void main(String[] args) throws IOException{
        init();

        make_che();

        int cnt = 0;

        for(int i = 0; i < arr.size(); i++){
            int sum = 0;
            int idx = i;
            while(idx < arr.size() && sum < N){
                sum += arr.get(idx++);
            }
            if(sum == N) cnt++;
        }

        System.out.println(cnt);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
    }
    
    public static void make_che(){
        che = new boolean[N + 1];
        arr = new ArrayList<>();

        Arrays.fill(che, true);
        
        for(int i = 2; i <= Math.sqrt(N); i++){
            if(!che[i]) continue;
            for(int j = i + i; j <= N; j += i){
                che[j] = false;
            }
        }

        for(int i = 2; i <= N; i++){
            if(che[i]) arr.add(i);
        }
    }
}
