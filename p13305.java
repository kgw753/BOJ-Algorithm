import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class City{
    int len;
    int oilCost;

    public City(int l){
        len = l;
    }

    public void setCost(int c){
        oilCost = c;
    }
}

public class p13305 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<City> cities = new ArrayList<>();
        
        StringTokenizer stLen = new StringTokenizer(br.readLine());
        for(int i = 0; i < N - 1; i++){
            cities.add(new City(Integer.parseInt(stLen.nextToken())));
        }

        StringTokenizer stCost = new StringTokenizer(br.readLine());
        for(int i = 0; i < N - 1; i++){
            cities.get(i).setCost(Integer.parseInt(stCost.nextToken()));
        }

        long res = 0;
        int min = cities.get(0).oilCost;
        res += cities.get(0).len * min;
        for(int i = 1; i < N - 1; i++){
            City ct = cities.get(i);
            min = Math.min(min, ct.oilCost);
            res += (min * ct.len);
        }
        System.out.println(res);
    }
}
