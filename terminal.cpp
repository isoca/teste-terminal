#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string comando;

    while (true) { 
        std::cout << "$ "; 
        std::getline(std::cin, comando);

        if (comando == "exit") {
            std::cout << "Saindo...\n";
            break;
        }
        //ele vai criar um arquivo se começar com touch.
        else if (comando.find("touch ") == 0) {
            std::string nome_arquivo = comando.substr(6); 
            
            std::ofstream arquivo(nome_arquivo);
            if (arquivo) {
                std::cout << "Arquivo criado: " << fs::current_path() << "/" << nome_arquivo << "\n";
                arquivo.close();
            } else {
                std::cerr << "Erro ao criar o arquivo!\n";
            }
        }

        else {
            std::cerr << "Comando inválido! Use 'touch <nome>' ou 'exit'.\n";
        }
    }

    return 0;
}

//novos comandos que aprendi: std::cer, na qual é usado para mensagens de erro.
//o substr, basicamente, ele pega tudo que vem depois do touch. ele so pegaria 1 palavra caso eu digitasse algo a mais.
//.find, ele procura pela palavra, se a pessoa digitou aquilo.