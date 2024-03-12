#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

// Fun��o para gerar uma palavra aleat�ria
std::string getRandomWord(const std::vector<std::string> &words) {
    return words[rand() % words.size()];
}

// Fun��o para verificar se a letra j� foi digitada
bool isLetterAlreadyGuessed(const std::string &guessed_letters, char letter) {
    return guessed_letters.find(letter) != std::string::npos;
}

// Fun��o para verificar se a letra est� na palavra
bool isLetterInWord(const std::string &word, char letter) {
    return word.find(letter) != std::string::npos;
}

// Fun��o para exibir a palavra com as letras corretas j� reveladas
void printWord(const std::string &word, const std::string &guessed_letters) {
    for (const char &c : word) {
        if (guessed_letters.find(c) != std::string::npos) {
            std::cout << c << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

// Fun��o principal do jogo
int main() {
    // Lista de palavras
    std::vector<std::string> words = {"casa", "arvore", "carro", "aviao", "computador"};

    // Inicializa o gerador de n�meros aleat�rios
    srand(time(NULL));

    // Escolhe uma palavra aleat�ria
    std::string word = getRandomWord(words);

    // Lista de letras j� digitadas
    std::string guessed_letters = "";

    // Quantidade de vidas
    int lives = 7;

    // Loop principal do jogo
    while (lives > 0 && word.find("_") != std::string::npos) {
        printWord(word, guessed_letters);
        std::cout << "Lives: " << lives << std::endl;
        std::cout << "Enter a letter: ";

        char guess;
        std::cin >> guess;

        if (isLetterAlreadyGuessed(guessed_letters, guess)) {
            std::cout << "You already guessed this letter." << std::endl;
        } else {
            guessed_letters += guess;
            if (isLetterInWord(word, guess)) {
                std::cout << "Correct guess!" << std::endl;
            } else {
                lives--;
                std::cout << "Incorrect guess, you lose a life." << std::endl;
            }
        }
    }

    if (lives > 0) {
        std::cout << "Congratulations, you've won! The word was: " << word << std::endl;
    } else {
        std::cout << "Game over, you lose. The word was: " << word << std::endl;
    }

    return 0;
}
