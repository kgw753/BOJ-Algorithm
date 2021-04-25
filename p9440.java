import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

public class p9440 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> answer = new ArrayList<>();
        while(n != 0){
            int[] arr = new int[n];
            int zero = 0;
            for(int i = 0; i < n; i++){
                arr[i] = sc.nextInt();
                if(arr[i] == 0) zero++;
            }
            Arrays.sort(arr);

            for(int i = 0; i < Math.min(2, zero); i++){
                int tmp = arr[i];
                arr[i] = arr[zero + i];
                arr[zero + i] = tmp;
            }
            
            int num1 = 0;
            int num2 = 0;

            for(int i = 0; i < n; i++){
                if(zero == 1 && arr[i] == 0){
                    num1 = num1 * 10 + arr[i];
                    continue;
                }
                if(num1 > num2){
                    num2 = num2 * 10 + arr[i];
                }
                else{
                    num1 = num1 * 10 + arr[i];
                }
            }

            answer.add(num1 + num2);
            n = sc.nextInt();
        }

        for(Integer ans : answer)
            System.out.println(ans);
    }
}
