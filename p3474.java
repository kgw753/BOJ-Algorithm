import java.util.Scanner;

public class p3474 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for(int i = 0; i < N; i++){
            int num = sc.nextInt();
            int cnt = 0;
            while(num > 0){
                num /= 5;
                cnt += num;
            }
            System.out.println(cnt);
        }
    }
}
