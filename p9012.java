import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class p9012 {
    public static int tc;
    public static String input;
    public static Stack<Character> st;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            st = new Stack<>();
            input = br.readLine();
            String res = "YES";
            for(int i = 0; i < input.length(); i++){
                if(input.charAt(i) == ')') {
                    if(!st.empty() && st.peek() == '('){
                        st.pop();
                    }
                    else{
                        res = "NO";
                        break;
                    }
                }
                else st.push(input.charAt(i));
            }
            if(!st.empty()) res = "NO";
            System.out.println(res);
        }
    }
}
