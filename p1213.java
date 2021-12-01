import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1213 {
    static String str;
    static char[] chars = new char['Z' - 'A' + 1];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        for(int i = 0; i < str.length(); i++){
            chars[str.charAt(i) - 'A']++;
        }
        StringBuffer sb = new StringBuffer();

        int centerIdx = -1;
        for(int i = 0; i < chars.length; i++){
            if(chars[i] % 2 == 1){
                if(centerIdx != -1){
                    centerIdx = -100;
                    break;
                }
                centerIdx = i;
            }
            for(int j = 0; j < chars[i] / 2; j++){
                sb.append((char)('A' + i));
            }
        }
        String ans = sb.toString();
        if(centerIdx >= 0) ans += (char)('A' + centerIdx);
        ans += sb.reverse().toString();
        if(centerIdx == -100) System.out.println("I'm Sorry Hansoo");
        else System.out.println(ans);
    }
}
