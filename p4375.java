import java.util.Scanner;

public class p4375 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num;
        while(sc.hasNextInt()){
            num = sc.nextInt();
            int ans = 1;
            int one = 1;
            while((one % num) != 0){
                one = (one * 10 + 1) % num;
                ans++;
            }
            System.out.println(ans);
        }
    }
}
