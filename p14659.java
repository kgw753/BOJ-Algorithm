import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p14659 {
    public static int N;
    public static int ans;
    public static void main(String[] args) throws IOException{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int mx = -1;
        int cnt = 0;
        int h;
        for(int i = 0; i < N; i++){
            h = Integer.parseInt(st.nextToken());
            if(mx < h){
                mx = h;
                cnt = 0;
            } 
            else{
                ans = Math.max(ans, ++cnt);
            }
        }
        System.out.println(ans);
    }
}
