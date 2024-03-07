#include <iostream>
#include <iomanip>
#include <stdexcept> // Para exce��es
#include <cmath>

using namespace std;

// Fun��o para converter um n�mero decimal para bin�rio
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
    // N�o � poss�vel usar "Portuguese" como argumento
    // Alterado para "" para usar a localidade padr�o
    setlocale(LC_ALL, "");

    char operador;
    double num1, num2;

    cout << "Digite o primeiro n�mero: ";
    cin >> num1;

    cout << "Digite o operador (+, -, *, /, ^, sqrt, bin): ";
    cin >> operador;

    switch (operador) {
        case '+':
            cout << "Digite o segundo n�mero: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 + num2;
            break;
        case '-':
            cout << "Digite o segundo n�mero: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 - num2;
            break;
        case '*':
            cout << "Digite o segundo n�mero: ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << num1 * num2;
            break;
        case '/':
            cout << "Digite o segundo n�mero: ";
            cin >> num2;
            if (num2 != 0)
                cout << "Resultado: " << fixed << setprecision(2) << num1 / num2;
            else
                throw invalid_argument("Erro! Divis�o por zero!");
            break;
        case '^':
            cout << "Digite o segundo n�mero (expoente): ";
            cin >> num2;
            cout << "Resultado: " << fixed << setprecision(2) << pow(num1, num2);
            break;
        case 's': // Corrigido para 'sqrt'
            cout << "Resultado: " << fixed << setprecision(2) << sqrt(num1);
            break;
        case 'b': // Corrigido para 'bin'
            cout << "Resultado bin�rio: " << decimalParaBinario(num1);
            break;
        default:
            throw invalid_argument("Operador inv�lido!");
            break;
    }

    return 0;
}

