import java.util.Scanner;

public class p14405 {
    public static boolean flag = false;
    public static String input;
    public static String[] pika = {
        "pi", "ka", "chu"
    };
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        input = sc.nextLine();
        dfs("");

        if(flag) System.out.println("YES");
        else System.out.println("NO");
    }

    public static void dfs(String str){
        if(str.equals(input)) {
            flag = true;
            return;
        }

        for(int i = 0; i < 3; i++){
            int nlen = str.length() + pika[i].length();
            if(nlen > input.length()) continue;
            if(input.substring(0, nlen).equals(str + pika[i])) dfs(str + pika[i]);
        }
    }
    
}
