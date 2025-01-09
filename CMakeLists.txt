cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(SearchStrategy)

# Define o padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona o executável e os arquivos de origem
add_executable(main
    src/main.cpp
    src/strategy.cpp
)