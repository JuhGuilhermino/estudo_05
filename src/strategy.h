/**
 * @file strategy.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <vector>
#include <memory>
#include <iostream>
#pragma once
#include <stdexcept>

/**
 * @brief Essa classe representa a interface do strategy.
 * 
 */
class SearchStrategy{
    public:
        virtual int search(int *first, int *last, int value) = 0;

        virtual ~SearchStrategy() = default;
};

/**
 * @brief Essa classe implementa a busca linear.
 * 
 */
class LinearSearchStrategy : public SearchStrategy{
    public:
        int search(int *first, int *last, int value);
};

/**
 * @brief Essa classe implmenta a busca binária.
 * 
 */
class BinarySearchStrategy : public SearchStrategy{
    public:
        int search(int *first, int *last, int value);
};

/**
 * @brief Essa classe implementa a classe contexto do padrão strategy.
 * 
 */
class InventorySearchContext{
    private:
        std::unique_ptr<SearchStrategy> strategy;

    public:
        void setStrategy(std::unique_ptr<SearchStrategy> new_strategy);

        int executeSearch(int *first, int *last, int value);
};
