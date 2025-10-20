# Sieve of Eratosthenes

**Language:** C++  
**Purpose:** Finds all prime numbers up to a user-defined limit using the classic Sieve of Eratosthenes algorithm.

---

##  How It Works
- Dynamically allocates an array of booleans to track primality.  
- Marks multiples of each prime as non-prime.  
- Uses an object-oriented design with a `PrimesSieve` class.  
- Outputs all primes neatly formatted within an 80-character width limit.

---

##  Build & Run
```bash
g++ -O2 -std=c++17 -o sieve src/sieve.cpp
./sieve
