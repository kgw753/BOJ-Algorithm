import java.util.Scanner;

public class p1094 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        System.out.println(getCnt(N));
    }

    public static int getCnt(int N){
        int ret = 0;
        
        while(N > 0){
            if((N & 1) == 1) ret++;
            N /= 2;
        }

        return ret;
    }
}
