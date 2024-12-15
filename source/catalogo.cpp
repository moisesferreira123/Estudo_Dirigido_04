#include "catalogo.h"
#include "loggerManager.h"
#include <spdlog/spdlog.h>
#include <iomanip>

static auto logger = loggerManager::obterLogger();

void Catalogo::adicionarProduto(Produto produto, bool testeDesligado){
  bool conseguiuAdicionar = catalogo.insert({produto.obterId(),produto}).second;
  if(!conseguiuAdicionar){
    if(testeDesligado){
      spdlog::error("Não foi possível adicionar o novo produto ao catálogo. Id {} já existe no catálogo.", produto.obterId());
      logger->error("Não foi possível adicionar o novo produto ao catálogo. Id {} já existe no catálogo.", produto.obterId());
    }
  }else{
    if(testeDesligado){
      spdlog::info("Produto foi adicionado com sucesso ao catálogo.");
      logger->info("Produto foi adicionado com sucesso ao catálogo.");
    }
  }
}

std::map<int, Produto> Catalogo::listarProdutos(bool testeDesligado){
  if(testeDesligado){
    for(auto produto:catalogo){
      std::cout << produto.second.obterId() << " " << produto.second.obterNome() << " " << produto.second.obterPreco() << "\n";
    }
  }
  return catalogo;
}

Produto Catalogo::buscarProdutoPorId(int id, bool testeDesligado){
  auto produto = catalogo.find(id);
  if(produto == catalogo.end()){
    if(testeDesligado){
      spdlog::error("Esse produto não está presente no catálogo.");
      logger->error("Esse produto não está presente no catálogo.");
    }
    return Produto(-1,"Produto não encontrado",0);
  }else{
    if(testeDesligado){
      spdlog::info("Produto de id {} foi encontrado no catálogo!", id);
      logger->info("Produto de id {} foi encontrado no catálogo!", id);
      std::cout << "Informações do produto buscado:\nId: " << produto->first << "  Nome: " << produto->second.obterNome() << "  Preço: R$" << std::fixed << std::setprecision(2) << produto->second.obterPreco() << "\n";
    }
  }
  return produto->second;
}

size_t Catalogo::quantidadeProdutos(){
  return catalogo.size();
}