import java.util.Scanner;

public class p1526 {
    public static int input;
    public static int DFS(int n){
        int tmp = n;
        if(n * 10 + 4 <= input){
            tmp = DFS(n * 10 + 4);
        }
        if(n * 10 + 7 <= input){
            tmp = Math.max(tmp, DFS(n * 10 + 7));
        }
        return tmp;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        input = sc.nextInt();
        System.out.println(DFS(0));
    }
    
}
