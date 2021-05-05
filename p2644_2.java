import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class p2644_2 {

    public static ArrayList<ArrayList<Integer>> family;
    public static boolean[] visited;
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String input = br.readLine();
        int source = Integer.parseInt(input.split(" ")[0]);
        int dest = Integer.parseInt(input.split(" ")[1]);
        int M = Integer.parseInt(br.readLine());
        family = new ArrayList<ArrayList<Integer>>();
        visited = new boolean[N + 1];

        for(int i = 0; i <= N; i++){
            family.add(new ArrayList<Integer>());
        }
        
        for(int i = 0; i < M; i++){
            input = br.readLine();
            int x = Integer.parseInt(input.split(" ")[0]);
            int y = Integer.parseInt(input.split(" ")[1]);
            family.get(x).add(y);
            family.get(y).add(x);
        }

    }

}
