import java.util.ArrayList;
import java.util.Scanner;

public class p1934 {

    public static int gcd(int a, int b){
        while(b != 0){
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        int [] res = new int[tc];

        for(int i= 0; i < tc; i++){
            int A = sc.nextInt();
            int B = sc.nextInt();
            int C = gcd(A, B);
            res[i] = A * B / C;
        }

        for(int n : res){
            System.out.println(n);
        }
    }
}
