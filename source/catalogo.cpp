#include "catalogo.h"
#include <spdlog/spdlog.h>
#include <iomanip>

bool Catalogo::adicionarProduto(Produto produto){
  return catalogo.insert({produto.obterId(),produto}).second;
}

std::map<int, Produto> Catalogo::listarProdutos(){
  return catalogo;
}

Produto Catalogo::buscarProdutoPorId(int id){
  auto produto = catalogo.find(id);
  if(produto == catalogo.end()){
    return Produto(-1,"Produto não encontrado",0);
  }
  return produto->second;
}

size_t Catalogo::quantidadeProdutos(){
  return catalogo.size();
}