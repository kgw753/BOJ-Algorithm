import java.util.Scanner;

public class p1436 {
    public static String target = "666";
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cnt = sc.nextInt();
        int num = 666;
        while(cnt > 0){
            if(Integer.toString(num).contains(target)) cnt--;
            num++;
        }
        System.out.println(num - 1);
    }
}
