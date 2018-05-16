import java.util.*;
import java.math.BigInteger;

public class g{
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
		dp = new BigInteger[n+2];
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
		comb[lb] = 1;
		comb[ub] = 1;
		for(int i=lb+1;i<ub;++i){
			comb[i] = combin(i-lb+c-1, c-1);
			if(i>2+lb){
				comb[i] -= combin(i-lb+c-3, c-1);
			}
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
			System.out.println(ans.charAt(0)+"."+ans.charAt(1)+ans.charAt(2)+ans.charAt(3)+" x 10^"+(ans.length()-1));
		}
	}
}