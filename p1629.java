import java.util.Scanner;

public class p1629 {
    public static long A;
    public static long B;
    public static long C;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");

        A = Long.parseLong(input[0]);
        B = Long.parseLong(input[1]);
        C = Long.parseLong(input[2]);
        
        System.out.println(go(A, B));
    }

    public static long go(long a, long b){
        if(b == 1) return a % C;

        long ret = go(a, b / 2);
        ret = ret * ret % C;
        if(b % 2 == 1) ret = ret * a % C;
        return ret;
    }
}
