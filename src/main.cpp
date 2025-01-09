#include "strategy.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector <int> arr = {10, 11, 12, 13, 14};

    int *first = std::data(arr);
    int *last = first + arr.size();

    InventorySearchContext a;

    int value1 = 10;
    int value2 = 9;

    // Busca Linear
    a.setStrategy(std::make_unique<LinearSearchStrategy>());
    std::cout << "BUSCA LINEAR\n";
    for (int value : {value1, value2}) {
        int index = a.executeSearch(first, last, value);
        if (index != -1) {
            std::cout << "Buscar: " << value << " -> Encontrou no índice " << index
                      << " com valor " << arr[index] << ".\n";
        } else {
            std::cout << "Buscar: " << value << " -> Não encontrado.\n";
        }
    }

    // Ordena o vetor antes da busca binária
    std::vector<int> sorted_arr = arr; // Copia para preservar a ordem original
    std::sort(sorted_arr.begin(), sorted_arr.end());

    first = std::data(sorted_arr);
    last = first + sorted_arr.size();

    // Busca Binária
    a.setStrategy(std::make_unique<BinarySearchStrategy>());
    std::cout << "\nBUSCA BINÁRIA\n";
    for (int value : {value1, value2}) {
        int index = a.executeSearch(first, last, value);
        if (index != -1) {
            std::cout << "Buscar: " << value << " -> Encontrou no índice " << index
                      << " com valor " << sorted_arr[index] << ".\n";
        } else {
            std::cout << "Buscar: " << value << " -> Não encontrado.\n";
        }
    }

    return 0;
}
