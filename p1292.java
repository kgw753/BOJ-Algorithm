import java.util.Scanner;

public class p1292 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[1000];
        int start = sc.nextInt() - 1;
        int end = sc.nextInt() - 1;

        int num = 1;
        for(int i = 0, cnt = 1; i < arr.length; i++, cnt++){
            arr[i] = num;
            if(num == cnt){
                num++;
                cnt = 0;
            }
        }

        int res = 0;
        for(int i = start; i <= end; i++){
            res += arr[i];
        }
        System.out.println(res);
    }
    
}
