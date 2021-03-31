import java.util.Scanner;

public class p1924 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int [] day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] res = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        int x = sc.nextInt();
        int y = sc.nextInt();
        int sum = 0;

        for(int i = 0; i < x - 1; i++){
            sum += day[i];
        }
        sum += y;

        System.out.println(res[sum % 7]);
    }
}
