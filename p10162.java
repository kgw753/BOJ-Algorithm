import java.util.Scanner;

public class p10162 {
    public static void main(String[] args){
        Scanner sc = new Scanner (System.in);
        int A = 300, B = 60, C = 10;
        int a = 0, b = 0, c = 0;
        int T = sc.nextInt();
        int remain = T;

        a = remain / A;
        if(a != 0) {
            remain %= A;
        }

        b = remain / B;
        if(b != 0) {
            remain %= B;
        }
        
        c = remain / C;
        if(c != 0) {
            remain %= C;
        }
        if((a * A + b * B + c * C) == T) {
            System.out.println(a + " " + b + " " + c);
        }
        else{
            System.out.println(-1);
        }
    }
}
