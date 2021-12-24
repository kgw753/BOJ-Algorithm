import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Stack;

public class p17298 {
    public static int N;
    public static int[] arr;
    public static Stack<int[]> st = new Stack<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());

        arr = new int[N];
        Arrays.fill(arr, -1);

        String[] input = br.readLine().split(" ");

        for(int i = 0; i < N; i++){
            int now = Integer.parseInt(input[i]);
            while(!st.isEmpty() && st.peek()[0] < now) {
                arr[st.pop()[1]] = now;
            }

            st.add(new int[]{now, i});
        }

        for(Integer i : arr) bw.append(i + " ");
        bw.append("\n");
        bw.flush();
        bw.close();
        br.close();
    }
}