import java.util.Scanner;

public class p18406 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        
        int sum = 0;

        for(int i = 0; i < input.length() / 2; i++){
            sum += input.charAt(i) - '0';
        }

        for(int i = input.length() / 2; i < input.length(); i++){
            sum -= input.charAt(i) - '0';
        }

        if(sum == 0){
            System.out.println("LUCKY");
        }
        else{
            System.out.println("READY");
        }
    }
}
