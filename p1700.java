import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class p1700 {
    public static int N, K;
    public static int[] arr;
    public static boolean[] visited;
    public static List<Integer> socket;
    public static BufferedReader br;

    public static void main(String[] args) throws IOException{
        init();

        int res = 0;
        for(int i = 0; i < K; i++){
            if(visited[arr[i]]) continue;

            if(socket.size() == N){
                int idx = 0, target = -1;
                for(int item : socket){
                    int itemIdx = Integer.MAX_VALUE;

                    for(int j = i + 1; j < K; j++){
                        if(item == arr[j]){
                            itemIdx = j;
                            break;
                        }
                    }

                    if(itemIdx > idx){
                        idx = itemIdx;
                        target = item;
                    }
                }

                socket.remove(socket.indexOf(target));
                visited[target] = false;
                res++;
            }

            socket.add(arr[i]);
            visited[arr[i]] = true;
        }
        
        System.out.println(res);
    }

    public static void init() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        arr = new int[K];
        visited = new boolean[K + 1];
        socket = new ArrayList<>();

        input = br.readLine().split(" ");
        for(int i = 0; i < K; i++){
            arr[i] = Integer.parseInt(input[i]);
        }
    }
}