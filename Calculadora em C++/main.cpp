#include <iostream>
#include <iomanip>
#include <stdexcept> // Para exceções
#include <cmath>

using namespace std;

// Função para converter um número decimal para binário
long long decimalParaBinario(double decimal) {
    long long binario = 0;
    int resto, i = 1;

    while (decimal != 0) {
        resto = int(decimal) % 2;
        decimal /= 2;
        binario += resto * i;
        i *= 10;
    }

    return binario;
}

int main() {
    // Não é possível usar "Portuguese" como argumento
    // Alterado para "" para usar a localidade padrão
    setlocale(LC_ALL, "");

    char operador;
    double num1, num2;

    cout << "Digite o primeiro número: ";
    cin >> num1;

    cout << "Digite o operador (+, -, *, /, ^, sqrt, bin): ";
    cin >> operador;

    switch (operador) {
        case '+':
            cout << "Digite o segundo número: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 + num2;
            break;
        case '-':
            cout << "Digite o segundo número: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 - num2;
            break;
        case '*':
            cout << "Digite o segundo número: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 * num2;
            break;
        case '/':
            cout << "Digite o segundo número: ";
            cin >> num2;
            if (num2 != 0)
                cout << "Resultado: " << fixed << setprecision(2) << num1 / num2;
            else
                throw invalid_argument("Erro! Divisão por zero!");
            break;
        case '^':
            cout << "Digite o segundo número (expoente): ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << pow(num1, num2);
            break;
        case 's': // Corrigido para 'sqrt'
            cout << "Resultado: " << fixed << setprecision(2) << sqrt(num1);
            break;
        case 'b': // Corrigido para 'bin'
            cout << "Resultado binário: " << decimalParaBinario(num1);
            break;
        default:
            throw invalid_argument("Operador inválido!");
            break;
    }

    return 0;
}

