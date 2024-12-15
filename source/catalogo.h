#ifndef _CATALOGO_H_
#define _CATALOGO_H_

#include "produto.h"
#include <map>

class Catalogo{
  private:
    std::map<int, Produto> catalogo;
  public:
    virtual bool adicionarProduto(Produto produto, bool testeDesligado = true);

    virtual std::map<int, Produto> listarProdutos(bool testeDesligado = true);

    virtual Produto buscarProdutoPorId(int id, bool testeDesligado = true);

    virtual size_t quantidadeProdutos();
};

#endif