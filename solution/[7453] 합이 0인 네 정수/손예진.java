import java.util.*;

public class test_7453 {
    static int N, MAX;
    static int a[], b[], c[], d[], ab[], cd[];
    
    static long BinarySearch(){ //가지수가 최대 256000000000000개 나올 수 있음
        int left = 0, right = MAX - 1;
        long ans = 0;
        while(left < MAX && right>= 0){
            int sum = ab[left] + cd[right];
            if(sum == 0){    //합이 0인 경우
                long cnt1 = 1, cnt2 = 1;
                for(left++; left < MAX; left++){
                    if(ab[left] == ab[left - 1])
                        cnt1++;
                    else
                    	break;
                }
                for(right--; right >= 0; right--){
                    if(cd[right] == cd[right + 1])
                        cnt2++;
                    else
                    	break;
                }
                ans += cnt1  * cnt2;
            }
            else if(sum < 0){    //0보다 작으면 left를 키워야됨
                left++;
            }
            else{    //0보다 크면 right를 줄여야됨
                right--;
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        ab = new int[N * N];	//크기가 1 큰 상태로 sort 하면 0이 다른 값으로 하나 대체가 안됨
        cd = new int[N * N];
        a = new int[N];
        b = new int[N];
        c = new int[N];
        d = new int[N];
        MAX = N * N;
        for(int i = 0; i < N; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }
        int idx = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ab[idx] = a[i] + b[j];
                cd[idx] = c[i] + d[j];
                idx++;
            }
        }
        Arrays.sort(ab);
        Arrays.sort(cd);
        System.out.println(BinarySearch());
    }
}
