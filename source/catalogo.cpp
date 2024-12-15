#include "catalogo.h"
#include "loggerManager.h"
#include <spdlog/spdlog.h>
#include <iomanip>

bool Catalogo::adicionarProduto(Produto produto, bool testeDesligado){
  return catalogo.insert({produto.obterId(),produto}).second;
}

std::map<int, Produto> Catalogo::listarProdutos(bool testeDesligado){
  return catalogo;
}

Produto Catalogo::buscarProdutoPorId(int id, bool testeDesligado){
  auto produto = catalogo.find(id);
  if(produto == catalogo.end()){
    return Produto(-1,"Produto não encontrado",0);
  }
  return produto->second;
}

size_t Catalogo::quantidadeProdutos(){
  return catalogo.size();
}