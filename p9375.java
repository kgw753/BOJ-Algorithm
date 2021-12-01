import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class p9375 {
    public static int N;
    public static int M;
    public static Map<String, Integer> mp = new HashMap<>();
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < N; i++){
            int res = 1;
            M = Integer.parseInt(br.readLine());
            mp.clear();
            for(int j = 0; j < M; j++){
                st = new StringTokenizer(br.readLine());
                st.nextToken();
                String kind = st.nextToken();
                if(mp.containsKey(kind)) {
                    mp.put(kind, mp.get(kind) + 1);
                }
                else {
                    mp.put(kind, 1);
                }
                
            }
            for(Integer val : mp.values()){
                res *= (val + 1);
            }
            System.out.println(res - 1);
        }
    }
}