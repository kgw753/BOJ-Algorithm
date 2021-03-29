import java.util.ArrayList;
import java.util.Scanner;

public class p1026 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];
        for(int i = 0; i < n; i++){
            A[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            B[i] = sc.nextInt();
        }

        ArrayList<Integer> Asorted = new ArrayList<>();
        ArrayList<Integer> Bsorted = new ArrayList<>();

        for(int i = 0; i < n - 1; i++){
            int maxIdx = 0, minIdx = 0;
            int max = -1;
            int min = 101;
            for(int j = 0; j < n; j++){
                if(min > A[j] && !(Asorted.contains(j))){
                    System.out.println("min : " + j);
                    min = A[j];
                    minIdx = j;
                }
                if(max < B[j] && !(Bsorted.contains(j))){
                    System.out.println("max : " + j);
                    max = B[j];
                    maxIdx = j;
                }
            }
            int tmp = A[minIdx];
            A[minIdx] = A[maxIdx];
            A[maxIdx] = tmp;
            Asorted.add(maxIdx);
            Bsorted.add(maxIdx);
        }

        for(int a: A){
            System.out.print(a + " ");
        }
        System.out.println();
        for(int a: B){
            System.out.print(a + " ");
        }
        System.out.println();


        int res = 0;
        for(int i = 0; i < n; i++){
            res += (A[i] * B[i]);
        }
        System.out.println(res);
    }
}
