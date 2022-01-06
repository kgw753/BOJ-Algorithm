import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p9935 {
    public static String str, bomb;
    public static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        bomb = br.readLine();

        for(int i = 0; i < str.length(); i++){
            sb.append(str.charAt(i));
            if(sb.length() < bomb.length()) continue;
            if(sb.substring(sb.length() - bomb.length()).equals(bomb)){
                sb.delete(sb.length() - bomb.length(), sb.length());
            }
        }

        if(sb.length() == 0) sb.append("FRULA");
        System.out.println(sb.toString());
    }
    
}
