import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class p16637 {
    public static int N, res = Integer.MIN_VALUE;
    public static List<Integer> numbers = new ArrayList<>();
    public static List<Character> operators = new ArrayList<>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        String input = br.readLine();

        for(int i = 0; i < N; i++){
            char c = input.charAt(i);

            if(i % 2 == 0) numbers.add(c - '0');
            else operators.add(c);
        }
        
        dfs(numbers.get(0), 0);

        System.out.println(res);
    }

    public static void dfs(int val, int idx){
        if(idx == N / 2){
            res = Math.max(res, val);
            return;
        }

        int nVal = calc(val, numbers.get(idx + 1), operators.get(idx));
        dfs(nVal, idx + 1);

        if(idx + 1 < N / 2){
            nVal = calc(numbers.get(idx + 1), numbers.get(idx + 2), operators.get(idx + 1));
            nVal = calc(val, nVal, operators.get(idx));
            dfs(nVal, idx + 2);
        }
    }

    public static int calc(int a, int b, char op){
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else return a * b;
    }
}