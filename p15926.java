import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class p15926 {
    public static int N, res;
    public static int[] arr;
    public static String input;
    public static Stack<Integer> st = new Stack<>();
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        input = br.readLine();
        arr = new int[N];

        for(int i = 0; i < N; i++){
            char c = input.charAt(i);

            if(c == '(') {
                st.add(i);
            } else if(c == ')' && !st.isEmpty()) {
                arr[st.pop()] = arr[i] = 1;
            }
        }

        int tmp = 0;
        for(int i : arr){
            if(i == 0){
                res = Math.max(res, tmp);
                tmp = 0;
            }
            else{
                tmp += i;
            }
        }
        
        System.out.println(Math.max(res, tmp));
    }
}
