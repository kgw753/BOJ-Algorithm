import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1912 {
    public static int N;
    public static int[] arr;
    public static BufferedReader br;
    public static void main(String[] args)throws IOException{
        init();

        int sum = 0;
        int mx = Integer.MIN_VALUE;
        for(int i = 0; i < N; i++){
            sum += arr[i];
            mx = Math.max(mx, sum);
            if(sum < 0) sum = 0;
        }
        
        System.out.println(mx);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }
}
