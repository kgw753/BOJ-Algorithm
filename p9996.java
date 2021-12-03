import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p9996 {
    public static int N;

    public static String cmp;
    public static String pre;
    public static String post;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        String input = br.readLine();
        pre = input.split("\\*")[0];
        post = input.split("\\*")[1];


        for(int i = 0; i < N; i++){
            input = br.readLine();
            if(pre.length() + post.length() > input.length()) System.out.println("NE");
            else if(checkStr(input)) System.out.println("DA");
            else System.out.println("NE");
        }
    }

    public static boolean checkStr(String str){
        if(!str.substring(0, pre.length()).equals(pre)) return false;
        if(!str.substring(str.length() - post.length()).equals(post)) return false;
        return true;
    }
}
