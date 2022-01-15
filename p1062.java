import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1062 {
    public static int N, K;
    public static int[] words;
    public static BufferedReader br;
    public static void main(String[] args) throws IOException{
        init();
        System.out.println(go(0, K, 0));    //index, canLearn, mask;
    }
    
    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        words = new int[N];

        for(int i = 0; i < N; i++){
            input[0] = br.readLine();

            for(char c : input[0].toCharArray()){
                words[i] |= (1 << (c - 'a'));
            }
        }
    }

    public static int go(int idx, int canLearn, int mask){
        if(canLearn < 0) return 0;
        if(idx == 26) return count(mask);
        int ret = go(idx + 1, canLearn - 1, mask | (1 << idx));

        if(anticCheck(idx)){
            ret = Math.max(ret, go(idx + 1, canLearn, mask));
        }
        return ret;
    }

    public static int count(int mask){
        int ret = 0;
        for(int wordMask : words){
            if((mask & wordMask) == wordMask) ret++;
        }
        return ret;
    }

    public static boolean anticCheck(int idx){
        if(idx == 'a' - 'a' || idx == 'n' - 'a' || idx == 't' - 'a' || idx == 'i' - 'a' || idx == 'c' - 'a') return false;
        return true;
    }
}