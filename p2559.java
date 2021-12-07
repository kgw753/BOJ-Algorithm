import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class p2559 {
    public static int N;
    public static int K;
    public static int l;
    public static int r;
    public static int res;

    public static ArrayList<Integer> arr;
    public static void main(String[] args){
        arr = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        for(int i = 0; i < N; i++){
            arr.add(Integer.parseInt(st.nextToken()));
        }
        l = 0;
        r = K;
        for(int i = 0; i < K; i++){
            res += arr.get(i);
        }

        int now = res;
        while(r < N){
            now = now - arr.get(l++) + arr.get(r++);
            res = Math.max(res, now);
        }

        System.out.println(res);
    }
}
