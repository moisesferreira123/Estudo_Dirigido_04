#ifndef _GERENCIADOR_SISTEMA_H
#define _GERENCIADOR_SISTEMA_H

#include "catalogo.h"
#include "produto.h"
#include "pedido.h"

class gerenciadorSistema {
  private:
    Catalogo catalogo;
    std::vector<Pedido> pedido;
    int opcao{0};
    int interfaceAtual{1};
  public:
    void escolhaDoUsuario(int opcao, int interfaceAtual);

    int retornarInterfaceAtual();

    void adicionarProdutoAoCatalogo();

    void listarProdutosDoCatalogo();

    void buscarProdutoNoCatalogoPorId();

    void realizarPedido();

    void adicionarProdutoAoPedido();

    void mostrarValorTotalDoPedido();

    void mostrarListaDeProdutosdoPedido();

    void cancelarPedido();

    void finalizarPedido();

    void pagarPedido();

    void SairDoPrograma();
};

#endif