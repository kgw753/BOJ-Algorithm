import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class p2529 {
    public static int N;
    public static List<Character> op = new ArrayList<>();
    public static List<String> res = new ArrayList<>();
    public static boolean[] visited = new boolean[10];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        for(int i = 0; i < N; i++){
            op.add(input[i].charAt(0));
        }
        
        go("", 0);

        Collections.sort(res);

        System.out.println(res.get(res.size() - 1));
        System.out.println(res.get(0));
    }

    public static void go(String nums, int depth){
        if(depth == N + 1){
            res.add(nums);
            return;
        }
        
        for(int i = 0; i < 10; i++){
            char now = (char)(i + '0');
            if(visited[i]) continue;
            if(nums.length() == 0 || isValid((int)(nums.charAt(depth - 1) - '0'), i, op.get(depth - 1))){
                visited[i] = true;
                go(nums + now, depth + 1);
                visited[i] = false;
            }
        }
    }

    public static boolean isValid(int a, int b, char o){
        if(o == '<') return a < b;
        else return a > b;
    }
    
}