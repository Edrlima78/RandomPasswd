#include <iostream>
#include <random>

using namespace std;

/**
    Gera um password aleatorio
    @param n tamanho do password
    @return password
*/
string randomPasswd(int n) {
    string passwd = "";
    string tokens = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	string numbers = "0123456789";
	string special = "+-*/?!@#$%&";
	int len = tokens.length();
	random_device rd{}; // Usado para gerar um seed pra randon engine
	default_random_engine randomEng{rd()};       // Inicializa a random engine c/ seed
	uniform_int_distribution dist_tok{0, len-1}; // Distribuicao de ints entre [0, len-1]
	uniform_int_distribution dist_num{0, 9};
    uniform_int_distribution dist_spec{0, 10};
    uniform_int_distribution dist_pass{0, n-1};
    char num = numbers[dist_num(randomEng)]; // digito aleatorio [0,9]
	int pos_num = dist_pass(randomEng); // Posicao aleatoria em que o numero vai ser inserido
	char spec = special[dist_spec(randomEng)]; // Caracter especial aleatorio
	int pos_spec = pos_num;         // Posicao aleatoria em que o caractere vai ser inserido
    while (pos_spec == pos_num) {       // While garante que pos2 != pos1
        pos_spec = dist_pass(randomEng); 
    } 
	for (int i = 0; i < n; i++) {
	    if (i == pos_num) {
	        passwd += num;
	    } else if (i == pos_spec) {
	        passwd += spec;
	    } else {
	        passwd += tokens[dist_tok(randomEng)];    
	    }
	}
	return passwd;
}

int main(void) 
{	
	cout << randomPasswd(30) << endl;

    return 0;
}


