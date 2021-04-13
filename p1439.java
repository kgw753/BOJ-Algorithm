import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1439 {
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        int zero = 0;
        int one = 0;

        int now = input.charAt(0) - '0';
        if(now == 0){
            zero++;
        }
        else{
            one++;
        }
        
        for(int i = 1; i < input.length(); i++){
            int check = input.charAt(i) - '0';
            if(now != check){
                now = check;
                if(now == 0){
                    zero++;
                }
                else{
                    one++;
                }
            }
        }

        System.out.println(Math.min(zero, one));
    }
}
