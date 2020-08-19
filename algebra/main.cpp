#include "include_algebra.h"

int main () {

	Matriz_2f matriz_1;
	Matriz_2f matriz_2;
    
    Vec_2f vetor;
    
	matriz_1 << 1.0f, 2.0f
	          , 3.0f, 4.0f;
	matriz_2 = matriz_1;
	
	vetor << 1.0f, 1.0f;

	std::cout << matriz_1 + matriz_2
	          << matriz_1 - matriz_2
	          << matriz_1 * matriz_2
	          << matriz_1 + 0.5f
	          << matriz_1 - 0.5f
	          << matriz_1 * 0.5f
	          << matriz_1 / 0.5f
	          << 0.5f + matriz_1
	          << 0.5f - matriz_1
	          << 0.5f * matriz_1
	          << std::endl
	          << matriz_1 * vetor
	          << std::endl;

	return 0;
}
