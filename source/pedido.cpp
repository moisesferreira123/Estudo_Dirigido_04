#include "pedido.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "loggerManager.h"
#include <iomanip>

#define VALOR_MAXIMO_QUE_NAO_RECEBE_DESCONTO 100

void Pedido::adicionarProduto(Produto produto, bool testeDesligado){
  static auto logger = loggerManager::obterLogger();
  if(produto == catalogo.buscarProdutoPorId(produto.obterId(), testeDesligado)){
    listaDeProdutos.push_back(produto);
    if(testeDesligado){
      spdlog::info("Produto foi adicionado com sucesso ao pedido.");
      logger->info("Produto foi adicionado com sucesso ao pedido.");
    } 
  }else{
    if(testeDesligado){
      spdlog::error("Esse produto não está presente no catálogo. Portanto, o produto não foi adicionado na lista de pedidos.");
      logger->error("Esse produto não está presente no catálogo. Portanto, o produto não foi adicionado na lista de pedidos.");
    }
  }
}

double Pedido::calcularTotal(bool testeDesligado){
  double total{0};
  for(auto produto:listaDeProdutos){
    total += produto.obterPreco();
  }
  if(total>VALOR_MAXIMO_QUE_NAO_RECEBE_DESCONTO){
    total -= total*DESCONTO;
    if(testeDesligado) std::cout << "Como o valor do pedido é maior que 100, o desconto de 10% será aplicado.\n";
  }
  if(testeDesligado) std::cout << "Valor total do pedido do cliente " << cliente << ": R$"  << std::fixed << std::setprecision(2)<< total << "\n";
  return total;
}

std::string Pedido::obterNomeCliente(){
  return cliente;
}

size_t Pedido::quantidadeProdutos(){
  return listaDeProdutos.size();
}

std::vector<Produto> Pedido::retornarListaDeProdutos(){
  return listaDeProdutos;
}