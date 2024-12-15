# Estudo Dirigido 04
Esse projeto visou resolver um problema proposto pelo professor Edson Jackson de Medeiros Neto durante a disciplina de Boas Práticas de Programação na Universidade do Rio Grande do Norte. O trabalho tem como principal objetivo oferecer um problema em que o aluno possa realizar uma aplicação prática de testes unitários e de integração e aprender a utilizar ferramentas de depuração, incluindo loggers e breakpoints.

## Descrição do programa
O programa basicamente simula um sistema que gerencia o processamento de pedidos de uma loja virtual. Esse sistema possui as seguintes funcionalidades:

### Produtos
Podemos criar produtos em que cada um possui um ID (identificador único), um nome e um preço.

### Catálogo
Podemos criar um catálogo de produtos. As operações principais que podem ser realizadas nesse catálogo são:

 - Adicionar produtos ao catálogo;
 - Listar todos os produtos;
 - Buscar um produto por ID.

 ### Pedido
 Podemos criar um pedido, que contém uma lista de produtos, o nome do cliente que está fazendo o pedido e o catálogo de onde se está escolhendo os produtos. No pedido, as principais operações são:
  
  - Adicionar um produto ao pedido;
  - Calcular o valor total do pedido, dando um desconto de <b>10%</b> caso o valor do pedido ultrapasse <b>$100,00</b>. 

  ## Como compilar o programa

  ```
  cmake -S . -B build
  cmake --build build
  ```

  ## Como executar o programa
  Vá para a pasta build, digitando:
   ```
  cd build
  ```
  Depois disso, se você quiser executar os testes, digite:
  ```
  ./test/run_test
  ```
  Case queira executar o programa principal em si, escreva:
   ```
  ./source/main
  ```