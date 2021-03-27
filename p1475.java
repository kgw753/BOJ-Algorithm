import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1475 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[] input = new int[10];
        
        for(int i = 0; i < str.length(); i++){
            input[str.charAt(i) - '0']++;
        }
        input[6] += input[9];
        if(input[6] % 2 == 1){
            input[6] /= 2;
            input[6]++;
        }
        else{
            input[6] /= 2;
        }
        input[9] = input[6];

        int max = 0;
        for(int i = 0; i < input.length - 1; i++){
            max = Math.max(max, input[i]);
        }
        System.out.println(max);
    }
}
