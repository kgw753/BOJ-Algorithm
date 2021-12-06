import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class p4949 {
    public static String input;
    public static Stack<Character> st;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(!(input = br.readLine()).equals(".")){
            st = new Stack<Character>();

            for(int i = 0; i < input.length(); i++){
                if(!isParen(input.charAt(i))) continue;
                Character c = input.charAt(i);
                if(c.equals('(') || c.equals('[')) st.add(c);
                else if(!st.empty() && c.equals(')') && st.peek().equals('(')) st.pop();
                else if(!st.empty() && c.equals(']') && st.peek().equals('[')) st.pop();
                else{
                    st.add(c);
                    break;
                }
            }
            if(st.empty()) System.out.println("yes");
            else System.out.println("no");
        }
    }

    public static boolean isParen(Character c){
        boolean ret = false;
        if(c.equals('(') || c.equals(')')) ret = true;
        else if(c.equals('[') || c.equals(']')) ret = true;
        return ret;
    }
}
