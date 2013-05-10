#ifndef PRIME_H_
#define PRIME_H_

#include <vector>

int sieve(std::vector<int>& p, int l);
int sieve_below(std::vector<int>& p, int limit);
int mod_math_pow(int base, int power, int mod);
int mrpt(int n, int i);

#endif /* PRIME_H_ */
