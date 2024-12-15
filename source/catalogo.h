#ifndef _CATALOGO_H_
#define _CATALOGO_H_

#include "produto.h"
#include <map>

class Catalogo{
  private:
    std::map<int, Produto> catalogo;
  public:
    virtual bool adicionarProduto(Produto produto);

    virtual std::map<int, Produto> listarProdutos();

    virtual Produto buscarProdutoPorId(int id);

    virtual size_t quantidadeProdutos();
};

#endif