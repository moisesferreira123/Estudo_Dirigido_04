#include "gerenciadorSistema.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "loggerManager.h"

static auto logger = loggerManager::obterLogger();

void gerenciadorSistema::escolhaDoUsuario(int opcao, int interfaceAtual){
  
}

int gerenciadorSistema::retornarInterfaceAtual(){
  return interfaceAtual;
}

void gerenciadorSistema::adicionarProdutoAoCatalogo(){
  std::string idProdutoString, nomeProduto, precoProdutoString;
  std::cout << "Digite o ID do produto: ";
  std::cin >> idProdutoString;
  try{
    int num = std::stoi(idProdutoString);
    if(num<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo\n");
    logger->error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo\n");
  }
  std::cout << "Digite o nome do produto: ";
  std::cin >> nomeProduto;
  std::cout << "Digite o preço do produto: ";
  std::cin >> precoProdutoString;
  try{
    double num = std::stod(precoProdutoString);
    if(num<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O preço fornecido não é um número maior que zero. Não foi possível adicionar produto ao catálogo\n");
    logger->error("O preço fornecido não é um número maior que zero. Não foi possível adicionar produto ao catálogo\n");
  }
  int idProduto = std::stoi(idProdutoString);
  double precoProduto = std::stod(precoProdutoString);
  Produto produto(idProduto, nomeProduto, precoProduto);
  catalogo.adicionarProduto(produto);
}

void gerenciadorSistema::listarProdutosDoCatalogo(){
  if(catalogo.quantidadeProdutos() == 0){
    std::cout << "O catálogo está vazio. Não há produto para ser listado.\n";
  }else{
    catalogo.listarProdutos();
  }
}