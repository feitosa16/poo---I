#include <iostream>
#include <vector>
#include <algorithm> // Inclui as funções de algoritmos, como std::remove_if

struct Entry {
    int id;
    double amount;
    // Outros campos como data, descrição, etc.
};

class AbstractEntryDAO {
public:
    virtual ~AbstractEntryDAO() {}

    virtual void incluir(const Entry& entry) = 0;
    virtual std::vector<Entry> consultar() = 0;
    virtual void apagar(int entryId) = 0;
};

class EntryDAOMemory : public AbstractEntryDAO {
private:
    std::vector<Entry> entries;

public:
    void incluir(const Entry& entry) override {
        entries.push_back(entry);
    }

    std::vector<Entry> consultar() override {
        return entries;
    }

    void apagar(int entryId) override {
        entries.erase(
            std::remove_if(entries.begin(), entries.end(), [entryId](const Entry& entry) {
                return entry.id == entryId;
            }),
            entries.end()
        );
    }
};

int main() {
    EntryDAOMemory dao; // Instância da classe concreta

    dao.incluir({1, 100.50});
    dao.incluir({2, 200.00});

    std::vector<Entry> entries = dao.consultar();
    std::cout << "Lançamentos:" << std::endl;
    for (const auto& entry : entries) {
        std::cout << "ID: " << entry.id << ", Valor: " << entry.amount << std::endl;
    }

    dao.apagar(1);

    entries = dao.consultar();
    std::cout << "Lançamentos após exclusão:" << std::endl;
    for (const auto& entry : entries) {
        std::cout << "ID: " << entry.id << ", Valor: " << entry.amount << std::endl;
    }

    return 0;
}
