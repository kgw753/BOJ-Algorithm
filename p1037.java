import java.util.Scanner;
import java.util.StringTokenizer;

public class p1037 {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int cnt = Integer.parseInt(sc.nextLine());
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        int input;
        
        int max = -1;
        int min = 1000001;

        for(int i = 0; i < cnt; i++){
            input = Integer.parseInt(st.nextToken());
            max = Math.max(max, input);
            min = Math.min(min, input);
        }

        System.out.println(min * max);
        
    }
}
