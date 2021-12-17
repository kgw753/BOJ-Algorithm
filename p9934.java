import java.util.ArrayList;
import java.util.Scanner;

public class p9934 {
    public static int N, nodeCnt;
    public static int[] arr;
    public static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(sc.nextLine());
        String[] input = sc.nextLine().split(" ");
        nodeCnt = (int)Math.pow(2, N) - 1;

        arr = new int[nodeCnt];
        for(int i = 0; i < nodeCnt; i++){
            arr[i] = Integer.parseInt(input[i]);
        }
        
        for(int i = 0; i < N; i++){
            tree.add(new ArrayList<>());
        }

        traversal(nodeCnt / 2, 0, (int)Math.pow(2, N - 2));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < tree.get(i).size(); j++){
                System.out.print(tree.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public static void traversal(int idx, int depth, int nextIdx){
        if(depth == N) return;
        
        traversal(idx - nextIdx, depth + 1, nextIdx / 2);
        tree.get(depth).add(arr[idx]);
        traversal(idx + nextIdx, depth + 1, nextIdx / 2);
    }
}
