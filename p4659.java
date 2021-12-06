import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p4659 {
    public static String input = "";
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(!(input = br.readLine()).equals("end")){
            System.out.format("<%s> is", input);
            if(check(input)) System.out.println(" acceptable.");
            else System.out.println(" not acceptable.");
        }
    }
    
    public static boolean check(String str){
        boolean t1 = false;
        boolean t2 = true;
        boolean t3 = true;
        boolean prevMoum = false;
        int k = 0;
        char prev = '.';
        for(int i = 0; i < str.length(); i++){
            if(isMoum(str.charAt(i))){
                t1 = true;
                if(prevMoum) k++;
                else k = 1;
                prevMoum = true;
            }
            else{
                if(!prevMoum) k++;
                else k = 1;
                prevMoum = false;
            }

            if(k == 3) t2 = false;

            if(prev == str.charAt(i)){
                if(prev != 'o' && prev != 'e') t3 = false;
            }
            prev = str.charAt(i);
        }
        return t1 && t2 && t3;
    }

    public static boolean isMoum(char c){
        return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
    }
}
