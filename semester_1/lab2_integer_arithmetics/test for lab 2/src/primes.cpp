#include <vector>
#include <cmath>

std::vector<int> FindPrimesInRange(int a, int b) {
    std::vector<int> primes;
    
    if (a > b) {
        return primes;  
    }
    
    for (int i = std::max(2, a); i <= b; ++i) {
        
        bool isPrime = true;
        
        for (int k = 2; k * k <= i; ++k) {
            if (i % k == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

