import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p2828 {
    public static int N;
    public static int M;
    public static int J;
    public static int ans = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        J = Integer.parseInt(br.readLine());
        int l = 1;
        int r = M;
        int pos;
        for(int i = 0; i < J; i++){
            pos = Integer.parseInt(br.readLine());
            if(l > pos){
                ans += l - pos;
                r -= l - pos;
                l = pos;
            }
            else if(r < pos){
                ans += pos - r;
                l += pos - r;
                r = pos;
            }
        }
        
        System.out.println(ans);
    }
}
