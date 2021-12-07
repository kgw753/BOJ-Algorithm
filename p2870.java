import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

public class p2870 {
    public static int N;
    public static HashMap<String, Integer> hm;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        hm = new HashMap<>();
        for(int i = 0; i < N; i++){
            String input = br.readLine();
            String num = "";
            for(int j = 0; j < input.length(); j++){
                if(isNum(input.charAt(j))){
                    num += input.charAt(j);
                }
                else if(!num.isEmpty()){
                    num = carvString(num);
                    if(hm.containsKey(num)) hm.put(num, hm.get(num) + 1);
                    else hm.put(num, 1);
                    num = "";
                }
                
                if(!num.isEmpty() && j == input.length() - 1){
                    num = carvString(num);
                    if(hm.containsKey(num)) hm.put(num, hm.get(num) + 1);
                    else hm.put(num, 1);
                }
            }
        }

        String[] keys = new String[hm.size()];
        keys = (String[])hm.keySet().toArray(keys);

        Arrays.sort(keys, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                if(s1.length() == s2.length()) return s1.compareTo(s2);
                return s1.length() - s2.length();
            }
        });
        for(Object key : keys){
            for(int i = 0; i < hm.get(key); i++){
                System.out.println(key);
            }
        }
    }

    public static boolean isNum(char c){
        return c >= '0' && c <= '9';
    }

    public static String carvString(String input){
        int idx = 0;
        while(idx < input.length() - 1 && input.charAt(idx) == '0') idx++;
        return input.substring(idx);
    }
}
