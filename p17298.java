import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class p17298 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        String[] inputStr = br.readLine().split(" ");
        int[] input = Arrays.stream(inputStr).mapToInt(Integer::parseInt).toArray();
        int[] ans = new int[N];

        Arrays.fill(ans, -1);
        Stack<Integer> stack = new Stack<>();
        
        for(int i = 0; i < N; i++){
            while(!stack.isEmpty() && input[stack.peek()] < input[i]){
                ans[stack.pop()] = input[i];
            } 
            stack.add(i);
        }
    
        for(int a : ans) bw.write(a + " ");
        bw.flush();
        
        br.close();
        bw.close();
    }
}
