import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class p3474 {
    public static int tc;
    public static ArrayList<Integer> ans;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ans = new ArrayList<>();
        tc = Integer.parseInt(br.readLine());
        int input;
        while(tc-- > 0){
            input = Integer.parseInt(br.readLine());
            int cnt = 0;

            for(int i = input; i > 0; i /= 5){
                cnt += i / 5;
            }

            ans.add(cnt);
        }

        for(Integer a : ans) System.out.println(a);
    }
}
