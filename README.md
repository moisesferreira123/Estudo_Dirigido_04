# Estudo Dirigido 04
Esse projeto visou resolver um problema proposto pelo professor Edson Jackson de Medeiros Neto durante a disciplina de Boas Práticas de Programação na Universidade do Rio Grande do Norte. O trabalho tem como principal objetivo oferecer um problema em que o aluno possa realizar uma aplicação prática de testes unitários e de integração e aprender a utilizar ferramentas de depuração, incluindo loggers e breakpoints.

<b>Observação:</b> Relatório do projeto na pasta docs.

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