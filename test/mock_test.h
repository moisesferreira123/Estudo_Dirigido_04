#ifndef _MOCK_TEST_H_
#define _MOCK_TEST_H_

#include <gmock/gmock.h>
#include "../source/produto.h"
#include "../source/catalogo.h"
#include "../source/pedido.h"

class MockCatalogo : public Catalogo {
  public:
    MOCK_METHOD(bool, adicionarProduto, (Produto produto), (override));
    MOCK_METHOD((std::map<int, Produto>), listarProdutos, (), (override));
    MOCK_METHOD(Produto, buscarProdutoPorId, (int id), (override));
    MOCK_METHOD(size_t, quantidadeProdutos, (), (override));
};

#endif