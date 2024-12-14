#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>

#define TOLERANCIA_PARA_DOUBLE 1e-9

class Produto {
  private:
    int id;
    std::string nome;
    double preco;
  public:
    Produto(int idProduto, std::string nomeProduto, double precoProduto) : id(idProduto), nome(nomeProduto), preco(precoProduto) {}
    
    Produto() = default;

    int obterId();
    
    std::string obterNome();
    
    double obterPreco();

    bool operator==(const Produto& outroProduto) const {
      return (id == outroProduto.id and nome == outroProduto.nome and abs(preco-outroProduto.preco) < TOLERANCIA_PARA_DOUBLE);
    }
};

#endif