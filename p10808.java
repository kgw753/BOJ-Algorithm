import java.util.Scanner;

public class p10808 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        char[] ans = new char['z' - 'a' + 1];
        
        for(int i = 0; i < input.length(); i++){
            ans[input.charAt(i) - 'a']++;
        }
        
        for(int a: ans){
            System.out.print(a + " ");
        }
        System.out.println();
    }
}
