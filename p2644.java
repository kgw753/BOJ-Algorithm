import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p2644 {
    public static ArrayList<ArrayList<Integer>> family;
    public static boolean[] visited;
    public static int res;

    public static void dfs(int src, int dest, int cnt) {
        for (int i = 0; i < family.get(src).size(); i++) {
            if (!visited[family.get(src).get(i)]) {
                if (dest == family.get(src).get(i)) {
                    res = cnt + 1;
                    return;
                }
                visited[family.get(src).get(i)] = true;
                dfs(family.get(src).get(i), dest, cnt + 1);
            }
        }
        return;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String srcDest = br.readLine();
        int src = Integer.parseInt(srcDest.split(" ")[0]);
        int dest = Integer.parseInt(srcDest.split(" ")[1]);
        int m = Integer.parseInt(br.readLine());
        visited = new boolean[n + 1];
        family = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            family.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            family.get(x).add(y);
            family.get(y).add(x);
        }
        res = -1;
        dfs(src, dest, 0);
        System.out.println(res);
    }
}
