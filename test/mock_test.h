#ifndef _MOCK_TEST_H_
#define _MOCK_TEST_H_

#include <gmock/gmock.h>
#include "../source/produto.h"
#include "../source/catalogo.h"
#include "../source/pedido.h"

class MockCatalogo : public Catalogo {
  public:
    MOCK_METHOD(void, adicionarProduto, (Produto produto, bool testeDesligado), (override));
    MOCK_METHOD((std::map<int, Produto>), listarProdutos, (bool testeDesligado), (override));
    MOCK_METHOD(Produto, buscarProdutoPorId, (int id, bool testeDesligado), (override));
    MOCK_METHOD(size_t, quantidadeProdutos, (), (override));
};

#endif