import java.util.Scanner;

public class p1085{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int w = sc.nextInt();
        int h = sc.nextInt();
        sc.nextLine();
        
        int t1 = Math.min(x, y);
        int t2 = Math.min(w - x, h - y);
        
        System.out.println(Math.min(t1, t2));
    }
}