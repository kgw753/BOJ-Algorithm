import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class p2529 {
    public static int N;
    public static char[] op;
    public static boolean[] visited = new boolean[10];
    public static List<String> res = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        op = br.readLine().replace(" ", "").toCharArray();

        combi(-1, "");

        Collections.sort(res);
        System.out.println(res.get(res.size() - 1));
        System.out.println(res.get(0));
    }

    public static void combi(int depth, String num){
        if(depth == N){
            res.add(num);
            return;
        }
        for(int i = 0; i < 10; i++){
            if(visited[i]) continue;
            if(depth == -1 || checkOp(num.charAt(depth) - '0', i, op[depth])){
                visited[i] = true;
                combi(depth + 1, num + (char)(i + '0'));
                visited[i] = false;
            }
        }
    }

    public static boolean checkOp(int a, int b, char o){
        if(o == '<') return a < b;
        else return a > b;
    }
}