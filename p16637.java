import java.util.ArrayList;
import java.util.Scanner;

public class p16637 {
    public static int N;
    public static int res = Integer.MIN_VALUE;
    public static ArrayList<Integer> numbers = new ArrayList<>();
    public static ArrayList<Character> operators = new ArrayList<>();
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(sc.nextLine());

        String input = sc.nextLine();
        for(int i = 0; i < N; i++){
            if(i % 2 == 0) numbers.add(input.charAt(i) - '0');
            else operators.add(input.charAt(i));
        }

        dfs(0, numbers.get(0));
        System.out.println(res);
    }

    public static void dfs(int depth, int num){
        if(depth == operators.size()){
            res = Math.max(res, num);
            return;
        }

        dfs(depth + 1, calc(num, numbers.get(depth + 1), operators.get(depth)));

        if(operators.size() - depth >= 2){
            int nextNum = calc(numbers.get(depth + 1), numbers.get(depth + 2), operators.get(depth + 1));
            dfs(depth + 2, calc(num, nextNum, operators.get(depth)));
        }
    }

    public static int calc(int a, int b, char op){
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else return a * b;
    }
}
