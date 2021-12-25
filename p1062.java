import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1062 {
    public static int N, M, res;
    public static String[] input;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        
        input = new String[N];
        for(int i = 0; i < N; i++){
            input[i] = br.readLine();
        }
        
        if(M < 5){
            System.out.println(0);
            return;
        } else if(M == 26) {
            System.out.println(N);
            return;
        } else{
            int bm = 0;
            bm = turnOnBit(bm, getBitIdx('a'));
            bm = turnOnBit(bm, getBitIdx('n'));
            bm = turnOnBit(bm, getBitIdx('t'));
            bm = turnOnBit(bm, getBitIdx('i'));
            bm = turnOnBit(bm, getBitIdx('c'));

            combi(0, bm, 5);

            System.out.println(res);
        }
    }

    public static int getBitIdx(char c){
        return c - 'a';
    }

    public static int turnOnBit(int num, int idx){
        return num | (1 << idx);
    }

    public static int turnOffBit(int num, int idx){
        return num & ~(1 << idx);
    }

    public static void combi(int start, int bm, int depth){
        if(depth == M){
            res = Math.max(res, getCnt(bm));
            return;
        }

        for(int i = start; i <= 'z' - 'a'; i++){
            if((bm & (1 << i))!= 0) continue;
            bm = turnOnBit(bm, i);
            combi(i + 1, bm, depth + 1);
            bm = turnOffBit(bm, i);

        }
    }

    public static int getCnt(int bm){
        int ret = 0;

        for(int i = 0; i < input.length; i++){
            if(canLearn(input[i], bm)) ret++;
        }

        return ret;
    }

    public static boolean canLearn(String word, int bm){
        
        for(char c : word.toCharArray()){
            
            if(((1 << getBitIdx(c)) & bm) == 0) return false;
        }

        return true;
    }
}
