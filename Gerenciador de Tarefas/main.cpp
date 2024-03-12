#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Tarefa adicionada com sucesso!\n";
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Tarefa removida com sucesso!\n";
        } else {
            cout << "�ndice inv�lido!\n";
        }
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Tarefa marcada como conclu�da!\n";
        } else {
            cout << "�ndice inv�lido!\n";
        }
    }

    void listTasks() {
        cout << "Lista de Tarefas:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[Conclu�do] ";
            cout << tasks[i].description << endl;
        }
        cout << endl;
    }
};

int main() {
	setlocale (LC_ALL, "portuguese");
    TaskManager taskManager;
    int choice;
    string description;
    int index;

    do {
        cout << "=== Gerenciador de Tarefas ===\n";
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Remover Tarefa\n";
        cout << "3. Marcar Tarefa como Conclu�da\n";
        cout << "4. Listar Tarefas\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Descri��o da Tarefa: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                cout << "�ndice da Tarefa a ser removida: ";
                cin >> index;
                taskManager.removeTask(index - 1); // Adjusting for 0-based indexing
                break;
            case 3:
                cout << "�ndice da Tarefa conclu�da: ";
                cin >> index;
                taskManager.completeTask(index - 1); // Adjusting for 0-based indexing
                break;
            case 4:
                taskManager.listTasks();
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Op��o inv�lida!\n";
        }
    } while (choice != 0);

    return 0;
}

