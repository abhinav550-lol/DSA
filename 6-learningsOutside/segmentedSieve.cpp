#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//used to calculate primes

//Simple Sieve
int countPrimes(int u){ // u inclusive sieve
	if(u <= 1) return 0;
	vector<bool> isPrime(u + 1, 1);
	int count = 0;
	isPrime[0] = isPrime[1] = 0;

	for(int i = 2 ; i <= u ; i++){
		if(isPrime[i]){
		count++;
		int j = 2 * i;
		for (; j <= u; j+=i){
			isPrime[j] = 0;
		}
		}
	}
	
	return count;
}

vector<int> allPrimes(int n){
	if(n <= 1) return {};

	vector<bool> isPrime(n , 1);
	vector<int> res;

	for(int i = 2 ;  i <= n; i++){
		if(isPrime[i]){
			res.push_back(i);
			for(int j = 2 * i ; j <= n; j+=i){
				isPrime[j] = false;
			}
		}
	}
	return res;
}


//Segemented Sieve 
/*
Usage : To calulated primes in a range of [l , r] or to calculate primes till a very large number. like 10^9. On most coding platforms, the maximum memory usage for an array is 10^8.
so , normal sieve will not work.	
*/
/*
	Algorithm for Segemented Sieve:
	1. First, for the upper bound R, we will calculate normal sieve till the sqrt(n).
		Reason -> For any number, the highest prime that will result in calculation is limited to the sqrt(n)
	2. Now, we will use a dummy array of size l - r + 1 to calculate primes between l to r. 
		Reason -> We will using the first index as l (0 + l) and last index as r (0 + r)
	3. Now, for the primes below sqrt(n) in the vector we calculated, we will find the first multiple in range of l to r and start marking them as not prime.
		Reason -> this is the same intiution as sieve
	4. At last, PRINT all the numbers which are marked as PRIME.	
*/

void segementedSieve(int l  ,int r){
	int limit = sqrt(r) + 1;
	vector<int> multipliers = allPrimes(limit);

	int size = r - l + 1;
	vector<int> isPrime(size , true);

	for(auto &pr : multipliers){
		int firstMultiple =( l / pr ) * pr;
		if(firstMultiple < l) firstMultiple += pr;

		for(int i = max(pr * pr , firstMultiple) ; i <= r ; i+= pr){
			isPrime[i  - l] = 0;
		}
	}

 
	for(int i = 0 ; i < size ; i++){
		if(isPrime[i]){
			cout << i + l << ' ';
		}
	}
}




int main() {r
	//cout << countPrimes(7);
	 segementedSieve(110 , 127);
	return 0;
}
