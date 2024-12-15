#ifndef _PEDIDO_H_
#define _PEDIDO_H_

#include "produto.h"
#include "catalogo.h"
#include <vector>

#define DESCONTO 0.1

class Pedido {
  private:
    std::vector<Produto> listaDeProdutos;
    std::string cliente;
    Catalogo &catalogo;

  public:
    Pedido() = default;
    
    Pedido(std::string clienteC, Catalogo &catalogoC) : cliente(clienteC), catalogo(catalogoC) {}

    void adicionarProduto(Produto produto, bool testeDesligado = true);

    double calcularTotal(bool testeDesligado = true);

    std::string obterNomeCliente();

    size_t quantidadeProdutos();

    std::vector<Produto> retornarListaDeProdutos();

    
};

#endif