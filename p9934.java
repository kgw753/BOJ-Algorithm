import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p9934 {
    public static int N;
    public static int[] arr;

    public static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        arr = new int[(int)Math.pow(2, N) - 1];
        for(int i = 0; i < N; i++) tree.add(new ArrayList<Integer>());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < arr.length; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        traversal(arr.length / 2, (int)Math.pow(2, N - 2), 0);

        for(ArrayList<Integer> a : tree){

            for(Integer i : a){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static void traversal(int idx, int interval, int depth){
        if(depth == N) return;

        traversal(idx - interval, interval / 2, depth + 1);
        tree.get(depth).add(arr[idx]);
        traversal(idx + interval, interval / 2, depth + 1);
    }
}