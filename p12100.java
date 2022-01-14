import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class p12100 {
    public static int N, mx;
    public static int[][] board;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();

        go(board, 0);

        System.out.println(mx);
    }
    
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                mx = Math.max(mx, board[i][j]);
            }
        }
    }

    public static void go(int[][] map, int depth){
        if(depth == 5) return;
        int[][] next;

        go(push(map), depth + 1);
        next = rotate(map);
        go(push(next), depth + 1);
        next = rotate(next);
        go(push(next), depth + 1);
        next = rotate(next);
        go(push(next), depth + 1);
    }

    public static int[][] rotate(int[][] map){
        int[][] ret = new int[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ret[N - j - 1][i] = map[i][j];
            }
        }

        return ret;
    }

    public static int[][] push(int[][] map){
        int[][] ret = new int[N][N];

        for(int i = 0; i < N; i++){
            Queue<Integer> q = new LinkedList<>();
            List<Integer> arr = new ArrayList<>();

            for(int n : map[i]){
                if(n != 0) q.add(n);
            }

            int prev = 0;
            while(!q.isEmpty()){
                if(prev == q.peek()){
                    mx = Math.max(mx, prev * 2);
                    arr.remove(arr.size() - 1);
                    arr.add(prev * 2);
                    prev = 0;
                }
                else{
                    arr.add(q.peek());
                    prev = q.peek();
                }
                q.poll();
            }

            while(arr.size() < N){
                arr.add(0);
            }
            
            for(int j = 0; j < N; j++){
                ret[i][j] = arr.get(j);
            }
        }

        return ret;
    }

    public static void print(int[][] map){
        System.out.println();
        for(int[] arr : map){
            for(int a : arr){
                System.out.print(a + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
