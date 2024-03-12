#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Bank {
private:
    struct Account {
        string name;
        double balance;
        int id;
    };

    map<int, Account> accounts;
    int nextId;

    void loadAccounts() {
        ifstream in("accounts.txt");
        if (in.is_open()) {
            Account acc;
            while (in >> acc.id >> acc.name >> acc.balance) {
                if (acc.id != 0) {
                    accounts[acc.id] = acc;
                }
            }
            nextId = *max_element(accounts.begin(), accounts.end(),
                [](const auto &a, const auto &b) { return a.first < b.first; })->second.id + 1;
            in.close();
        }
    }

    void saveAccounts() {
        ofstream out("accounts.txt", ios_base::trunc);
        for (const auto &acc : accounts) {
            out << acc.second.id << ' ' << acc.second.name << ' ' << acc.second.balance << '\n';
        }
        out << 0 << ' ';
        out.close();
    }

public:
    Bank() {
        loadAccounts();
    }

    ~Bank() {
        saveAccounts();
    }

    void createAccount(const string &name) {
        if (accounts.find(nextId) == accounts.end()) {
            accounts[nextId] = {name, 0.0, nextId};
        } else {
            nextId++;
            createAccount(name);
        }
    }

    bool authenticate(int id, const string &password) {
        if (accounts.find(id) != accounts.end()) {
            return accounts[id].name == password;
        }
        return false;
    }

    void deposit(int id, double amount) {
        if (accounts.find(id) != accounts.end()) {
            accounts[id].balance += amount;
        }
    }

    bool withdraw(int id, double amount) {
        if (accounts.find(id) != accounts.end()) {
            if (accounts[id].balance >= amount) {
                accounts[id].balance -= amount;
                return true;
            }
        }
        return false;
    }

    void transfer(int fromId, int toId, double amount) {
        if (withdraw(fromId, amount)) {
            deposit(toId, amount);
        }
    }

    void generateStatement(int id) {
        if (accounts.find(id) != accounts.end()) {
            cout << "Statement for account " << id << ":\n";
            cout << "Name: " << accounts[id].name << '\n';
            cout << "Balance: " << accounts[id].balance << '\n';
        }
    }

    void calculateInterest(int id) {
        if (accounts.find(id) != accounts.end()) {
            accounts[id].balance += accounts[id].balance * 0.05;
        }
    }
};

int main() {
    Bank bank;

    bank.createAccount("John Doe");
    bank.deposit(bank.nextId - 1, 1000);

    bank.createAccount("Jane Doe");
    bank.deposit(bank.nextId - 1, 2000);

    bank.transfer(bank.nextId - 2, bank.nextId - 1, 500);

    bank.generateStatement(bank.nextId - 1);

    bank.calculateInterest(bank.nextId - 1);

    return 0;
