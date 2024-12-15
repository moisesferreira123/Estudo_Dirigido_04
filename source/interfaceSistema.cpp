#include "interfaceSistema.h"

#include <iostream>

void interfaceSistema::boasBindas(){
  std::cout << "Bem-vindo ao sistema de gerenciamento da loja virtual!!!\n\n";
}

void interfaceSistema::imprimirInterfaceAtual(int interfaceAtual){
  std::cout << "Escolha uma das opções abaixo (digite o número correspondente a opção):\n";
  if(interfaceAtual == 1){
    std::cout << "1) Adicionar produto ao cátalogo\n";
    std::cout << "2) Listar todos os produtos do catálogo\n";
    std::cout << "3) Buscar produto no catálogo pelo Id\n";
    std::cout << "4) Realizar pedido\n";
    std::cout << "5) Sair da loja virtual\n";
  }else if(interfaceAtual == 2){
    std::cout << "1) Listar todos os produtos do catálogo\n";
    std::cout << "2) Buscar produto no catálogo pelo Id\n";
    std::cout << "3) Adicionar produto ao pedido\n";
    std::cout << "4) Mostrar lista de produtos do pedido\n";
    std::cout << "5) Calcular e mostrar o valor total do pedido\n";
    std::cout << "6) Cancelar pedido\n";
    std::cout << "7) Finalizar pedido\n";
    std::cout << "8) Sair da loja virtual\n";
  }else{
    std::cout << "1) Pague o pedido\n";
    std::cout << "2) Volte\n";
  }
}