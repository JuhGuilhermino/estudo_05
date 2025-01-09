#include "strategy.h"

int LinearSearchStrategy::search(int *first, int *last, int value){
    for (int* current = first; current < last; ++current){
        if (*first == value) {
            return current - first;
        }
    }
    return -1;
}

int BinarySearchStrategy::search(int *first, int *last, int value){
    while (first < last){
        int* meio = first + (last - first) / 2;

        if (*meio == value) {
            return meio - first; // Retorna o índice do valor encontrado
        } else if (*meio < value) {
            first = meio + 1; // Ajusta a busca para a metade direita
        } else {
            last = meio - 1; // Ajusta a busca para a metade esquerda
        }
    }

    return -1; // Valor não encontrado
}

void InventorySearchContext::setStrategy(std::unique_ptr<SearchStrategy> new_strategy){
    strategy = std::move(new_strategy);
}

int InventorySearchContext::executeSearch(int *first, int *last, int value){
    if (!strategy){
       throw std::logic_error("Nenhuma estratégia definida");
    }
    return strategy->search(first, last, value);
}