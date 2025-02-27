#include "nth_prime.h"

namespace nth_prime {
    


    bool is_prime(long int n){
        if(n==0){
            throw std::domain_error("Error: 0 is not consider prime");

        }else{
            for(int i{2}; i<=sqrt(n); i ++){ 
                if(n % i == 0){
                    return false; // No es primo
                }
            }
        }

        return true;
    }

    long int nth(long int n){
        
        int aux{2};
        int number_count{0};
        int last_prime_numb{0};

        if(n <= 0){
            throw std::domain_error("No existe un numero primo numero 0");
        }

        while(number_count != n){
            
            while(true){
                if(is_prime(aux)){
                    last_prime_numb = aux;
                    aux++;
                    break;
                }
                aux++;
            }

            number_count ++;
        }

        return last_prime_numb;

    }

}  // namespace nth_prime
