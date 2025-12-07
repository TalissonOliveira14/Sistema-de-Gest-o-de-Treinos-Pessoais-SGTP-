#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ctime>
#include <iostream>
#include <limits>

namespace Utils {
    void limparTela();
    void pausar();
    std::string getDataAtual();
    double lerDouble(const std::string& mensagem);
    int lerInt(const std::string& mensagem);
    std::string lerString(const std::string& mensagem);
}

#endif
