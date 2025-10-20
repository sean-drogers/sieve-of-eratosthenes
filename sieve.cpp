/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Sean Rogers
 * Date        : 9/19/2025
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
    cout << "Number of primes found: " << num_primes_ << endl;
    cout << "Primes up to " << limit_ << ":" << endl;

    /*
        Determine number of digits in the largest prime
        Use that to calculate the number of primes per line
        have a block for primes that can fit on one line
        Loop through the array and print the primes
        have a secondary block for bigger primes
        loop through the array and print the primes
        Print a newline every time you reach the number of primes per line
        Use setw() to format the output  
        end with endl to go onto a new line
    */     

    const int max_prime_width = num_digits(max_prime_),
    primes_per_row = 80 / (max_prime_width + 1);
    int count = 0;

    // All primes can fit in one line
    if(num_primes_ <= primes_per_row){
        for(int i = 2; i <= limit_; i++){
            if(is_prime_[i]){
                cout << i;
                count++;
                if (count < num_primes_){
                    cout << " ";
                }
            }
        }
    } else { //All primes cannot fit in one line so must format and wrap around
        for(int i = 2;i <= limit_;i++){
            if(is_prime_[i]){
                cout << setw(max_prime_width) << i;
                count++;
                if(count % primes_per_row == 0){
                    cout << endl;
                } else if (count < num_primes_){
                    cout << " ";
                }
            } 
        }
    }
    cout << endl;
}

void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    // All instance variables must be initialized by the end of this method.

    // Sets all entries is is_prime to true
    for(int t = 2; t <= limit_; t++){
        is_prime_[t] = true;
    }

    /*
        inialize all entries of is_prime_ to true
        for i = 2,3,4.... while i <= sqrt(limit_)
        if is_prime_[i] is true 
            for j = i*i, i*i+i, i*i + 2i... while j <= limit_
                then set is_prime_[j] to false
    */

        for(int i = 2; i <= sqrt(limit_); i++){
            if(is_prime_[i]){
                for(int j = i*i; j <= limit_; j += i){
                    is_prime_[j] = false;
                }
            }
        }
        
        num_primes_ = 0;
        max_prime_ = 0;

        for(int k = 2; k <= limit_; k++){
            if(is_prime_[k]){
                num_primes_++;
                max_prime_ = k;
            }
        }
}

int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.

    /*
        count = 1;
        while num <= 10
            num = num/10
            count number of divisions
        return count of divisions
    */
    int count = 1;
    while(num >= 10){
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    //Skip to the next newline after Search for Primes up to
    cout << endl;
    PrimesSieve sieve(limit);default
    
    sieve.display_primes();
    return 0;
}
