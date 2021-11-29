const int mxn = 2e7;
int spf[mxn + 1];
vector<int> primes;
void pre()
{
	spf[0] = spf[1] = 1;
	for (int i = 2; i <= mxn; i++)
	{
		if (!spf[i])
			spf[i] = i, primes.push_back(i);
		for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] <= mxn; j++)
			spf[i * primes[j]] = primes[j];
	}
}
vector<pair<int,int>> prime_factorize(int n)
{
	vector<pair<int,int>> res; 
	if(n <= mxn){
		while(n!=1){
			int p = spf[n],exponent = 0;
			do{
				n /= p, exponent++;
			} while(spf[n] == p); 
			res.emplace_back(p,exponent);
		}
		return res;
	}
	for(int p : primes){
		if(p*p > n)
			break;
		if(n % p == 0){
			int exponent = 0;
			do{
				n /= p, exponent++;
			}while(n % p == 0);
			res.emplace_back(p,exponent);
		}
	}
	if(n != 1)
		res.emplace_back(n,1);
	return res;
}
