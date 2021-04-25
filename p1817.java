import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class p1817 {
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int N = Integer.parseInt(input.split(" ")[0]);
        int M = Integer.parseInt(input.split(" ")[1]);

        Stack<Integer> stack = new Stack<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        
        for(int i = 0; i < N; i++){
            stack.push(Integer.parseInt(st.nextToken()));
        }
        int weight = 0;
        int cnt = 0;

        while(!stack.empty()){
            if(weight + stack.peek() > M){
                weight = stack.pop();
                cnt++;
            }
            else{
                weight += stack.pop();
            }
        }

        if(weight > 0) cnt++;

        System.out.println(cnt);
    }
}
