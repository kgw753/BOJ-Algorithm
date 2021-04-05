import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p11659 {
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int N =Integer.parseInt(input.split(" ")[0]);
        int M =Integer.parseInt(input.split(" ")[1]);

        int []arr = new int[N];
        int []sums = new int[N];
        int []ans = new int[M];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());

            if(i == 0){
                sums[i] = arr[i];
            }
            else{
                sums[i] = arr[i] + sums[i - 1];
            }
        }
        
        for(int i = 0; i < M; i++){
            String idxs = br.readLine();
            int start = Integer.parseInt(idxs.split(" ")[0]) - 1;
            int end = Integer.parseInt(idxs.split(" ")[1]) - 1;
            if(start == 0){
                ans[i] = sums[end];
            }
            else{
                ans[i] = sums[end] - sums[start - 1];
            }
        }

        for(int a: ans){
            System.out.println(a);
        }
    }
}
