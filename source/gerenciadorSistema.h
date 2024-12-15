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
    bool saidaDoPrograma{false};
  public:
    void obterEscolhaDoUsuario();

    void escolhaDoUsuario();

    int retornarInterfaceAtual();

    void adicionarProdutoAoCatalogo();

    void listarProdutosDoCatalogo();

    void buscarProdutoNoCatalogoPorId();

    void realizarPedido();

    void adicionarProdutoAoPedidoPeloId();

    void mostrarValorTotalDoPedido();

    void mostrarListaDeProdutosdoPedido();

    void cancelarPedido();

    void finalizarPedido();

    void pagarPedido();

    void voltar();

    void sairDoPrograma();

    bool retornarSaidaDoProgama();
};

#endif