import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class p1946new {
     public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        for(int i = 0; i < tc; i++){
            int N = Integer.parseInt(br.readLine());
            int [][] applicant = new int[N][2];
            for(int j = 0; j < N; j++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                applicant[j][0] = Integer.parseInt(st.nextToken());
                applicant[j][1] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(applicant, new Comparator<int []>(){
                @Override
                public int compare(int[] arr1, int arr2[]){
                    return arr1[0] - arr2[0];
                }
            });

            int res = 1;
            int min = applicant[0][1];
            for(int j = 1; j < N; j++){
                if(min > applicant[j][1]){
                    min = applicant[j][1];
                    res++;
                }
            }
            System.out.println(res);
        }
    }
}
