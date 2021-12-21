import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class p19942 {
    public static int N;
    public static int mp, mf, ms, mv;
    public static int[][] info;
    public static Map<Integer, String> map = new HashMap<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        mp = Integer.parseInt(input[0]);
        mf = Integer.parseInt(input[1]);
        ms = Integer.parseInt(input[2]);
        mv = Integer.parseInt(input[3]);

        info = new int[N][5];
        for(int i = 0; i < N; i++){
            input = br.readLine().split(" ");

            for(int j = 0; j < 5; j++){
                info[i][j] = Integer.parseInt(input[j]);
            }
        }
        
        int mnCost = Integer.MAX_VALUE;
        for(int i = 1; i < (1 << N); i++){
            
            int p = 0;
            int f = 0;
            int s = 0;
            int v = 0;
            int c = 0;

            for(int j = 0; j < N; j++){
                if((i & (1 << j)) == 0) continue;

                p += info[j][0];
                f += info[j][1];
                s += info[j][2];
                v += info[j][3];
                c += info[j][4];
            }

            if(check(p, f, s, v)){
                mnCost = Math.min(mnCost, c);

                String now = getIdxString(i);

                if(isValid(c, now)) {
                    map.put(c, now);
                }                
            }
        }

        if(mnCost == Integer.MAX_VALUE) System.out.println(-1);
        else{
            System.out.println(mnCost);
            System.out.println(map.get(mnCost));
        }
    }

    public static boolean check(int p, int f, int s, int v){
        return p >= mp && f >= mf && s >= ms && v >= mv;
    }

    public static String getIdxString(int bm){
        StringBuffer sb = new StringBuffer();

        for(int i = 0; i < N; i++){
            if((bm & (1 << i)) == 0) continue;

            sb.append(Integer.toString(i + 1) + " ");
        }

        return sb.toString();
    }

    public static boolean isValid(int c, String str){
        if(!map.containsKey(c)) return true;
        else{
            str = str.strip();
            String cmp = map.get(c).strip();
            return str.compareTo(cmp) < 0;
        }
    }
}
