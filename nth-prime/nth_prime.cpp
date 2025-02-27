#include "nth_prime.h"

namespace nth_prime {
    


    bool is_prime(long int n){
        
        if (n < 2) return false; // Los números menores que 2 no son primos
        if (n == 2 || n == 3) return true; // 2 y 3 son primos
        if (n % 2 == 0 || n % 3 == 0) return false; // Eliminamos múltiplos de 2 y 3
        
        //Raiz cuadrada fuera para evitar recalcularla con cada iteracion
        int limite = std::sqrt(n); // Solo iteramos hasta la raíz cuadrada
        
        for (int i = 5; i <= limite; i += 2) { // Probamos solo impares (evitamos pares)
            if (n % i == 0) return false;
        }

        return true;

        
    }

    long int nth(long int n){
        
        int aux{2};
        int number_count{0};
        int last_prime_numb{0};

        if(n <= 0){
            throw std::domain_error("No existe un numero primo numero 0, ni negativo");
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
