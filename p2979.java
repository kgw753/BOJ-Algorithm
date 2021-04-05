import java.util.Arrays;
import java.util.Scanner;

public class p2979 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] cost = new int[3];
        cost[0] = sc.nextInt();
        cost[1] = sc.nextInt() * 2;
        cost[2] = sc.nextInt() * 3;
        
        int[] time = new int[101];
        int min = 101, max = 0;
        for(int i = 0; i < 3; i++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            min = Math.min(min, start);
            max = Math.max(max, end);
            for(int j = start; j < end; j++){
                time[j]++;
            }
        }

        int sum = 0;
        for(int i = min; i < max; i++){
            if(time[i] == 1){
                sum += cost[0];
            }
            if(time[i] == 2){
                sum += cost[1];
            }
            if(time[i] == 3){
                sum += cost[2];
            }
        }
        System.out.println(sum);
    }
}
