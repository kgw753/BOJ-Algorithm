import java.util.Scanner;

public class p1526_2 {    
    public static int max =0;
    public static int N;
    public static void DFS(int num){
        if(num * 10 + 4 <= N){
            DFS(num * 10 + 4);
            max = Math.max(max, num * 10 + 4);
        }
        if(num * 10 + 7 <= N){
            DFS(num * 10 + 7);
            max = Math.max(max, num * 10 + 7);
        }
    }
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        N = sc.nextInt();
        DFS(0);
        System.out.println(max);
    }
}