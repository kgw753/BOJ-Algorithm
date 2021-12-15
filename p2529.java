import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class p2529 {
    public static int N;
    public static char[] op = new char[10];
    public static boolean[] visited = new boolean[10];
    public static ArrayList<String> answer = new ArrayList<>();
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(sc.nextLine());
        String[] input = sc.nextLine().split(" ");
        for(int i = 0; i < N; i++){
            op[i] = input[i].charAt(0);
        }

        dfs("", 0);

        Collections.sort(answer);
        System.out.println(answer.get(answer.size() - 1));
        System.out.println(answer.get(0));
    }

    public static void dfs(String res, int depth){
        if(depth == N + 1){
            answer.add(res);
            return;
        }
        
        for(char c = '0'; c <= '9'; c++){
            int idx = c - '0';

            if(visited[idx]) continue;
            if(res.length() == 0 || isValid(op[res.length() - 1], res.charAt(res.length() - 1) - '0', idx)){
                visited[idx] = true;
                dfs(res + c, depth + 1);
                visited[idx] = false;
            }
        }
    }

    public static boolean isValid(char op, int a, int b){
        if(op == '<' && a < b) return true;
        else if(op == '>' && a > b) return true;
        return false;
    }
}
