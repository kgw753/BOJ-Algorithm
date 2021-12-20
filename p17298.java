import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Stack;

public class p17298 {
    public static int N;
    public static Stack<int[]> st = new Stack<>();
    public static int[] ans;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());
        ans = new int[N];
        Arrays.fill(ans, -1);

        String[] input = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            int now = Integer.parseInt(input[i]);
            
            
            while(!st.isEmpty() && st.peek()[0] < now){
                int idx = st.pop()[1];
                
                ans[idx] = now;
            }

            st.add(new int[]{now, i});
        }

        for(int a : ans){
            bw.write(a + " ");
        }
        bw.write("\n");
        bw.flush();
    }
}