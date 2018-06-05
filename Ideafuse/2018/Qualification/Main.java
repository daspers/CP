import java.util.*;
import java.math.BigInteger;

public class Main{
	private static BigInteger[] dp;
	private static long[] comb;
	private static BigInteger undef = BigInteger.valueOf(-1);
	private static BigInteger zero = BigInteger.valueOf(0);
	private static int n, k, c, lb, ub;
	public static long combin(long a, long b){
		b = Math.min(b, a-b);
		long r =1;
		for(long i=1;i<=b;i++){
			r *= a--;
			r /= i;
		}
		return r;
	}
	
	public static BigInteger solve(int a){
		if(a < 0)
			return BigInteger.valueOf(0);
		if(dp[a]==null){
			dp[a] = BigInteger.valueOf(0);
			for(int i=lb; i<=ub && i<=a;++i){
				dp[a] = dp[a].add(BigInteger.valueOf(comb[i]).multiply(solve(a-i)));
			}
		}
		return dp[a];
	}
	public static void main(String[] args){
		Scanner read = new Scanner(System.in);
		n = read.nextInt();
		k = read.nextInt();
		c = read.nextInt();
		if(c==1){
			if(k+1 < n || k-1>n){
				System.out.println("0.000 x 10^0");
			}
			else
				System.out.println("1.000 x 10^0");
			return;
		}
		dp = new BigInteger[1002];
		lb = (k-1)*c;
		if(lb==0)
			lb = c;
		ub = (k+1)*c;
		dp[0] = BigInteger.valueOf(1);
		for(int i=1;i<lb;++i)
			dp[i] = BigInteger.valueOf(0);
		for(int i=lb;i<=n;i++)
			dp[i] = null;
		comb = new long[300];
		for(int i=lb;i<=ub;++i){
			int tmp = Math.min(2*c - (i-lb), i-lb);
			comb[i] = combin(tmp + c-1, c-1);
			if(tmp > 2){
				comb[i] -= c*combin(tmp + c-4, c-1);
			}
			System.out.println(comb[i]);
		}
		String ans = solve(n).toString();
		// System.out.println(ans);
		if(ans.length()==1){
			System.out.println(ans+".000 x 10^0");
		}
		else if(ans.length() == 2){
			System.out.println(ans.charAt(0)+"."+ans.charAt(1)+"00 x 10^1");
		}
		else if(ans.length() == 3){
			System.out.println(ans.charAt(0)+"."+ans.charAt(1)+ans.charAt(2)+"0 x 10^2");
		}
		else{
			char a = ans.charAt(0);
			char b = ans.charAt(1);
			char c = ans.charAt(2);
			char d = ans.charAt(3);
			int e = ans.length()-1;
			if(ans.charAt(4) >= '5'){
				d++;
				if(d>'9'){
					d = '0';
					c++;
					if(c>'9'){
						c = '0';
						b++;
						if(b>'9'){
							b = '0';
							a++;
							if(a>'9'){
								a = '1';
								e++;
							}
						}
					}
				}
			}
			System.out.println(a+"."+b+c+d+" x 10^"+e);
		}
	}
}