# Atividade - Liskov Substitution Principle

## Problema

A classe `CarroEletrico` herda de `Carro`, mas não consegue usar corretamente o método `abastecer()`.

## Violação do Princípio da Substituição de Liskov (LSP)

O problema acontece pois a função `prepararViagem()` espera que qualquer objeto do tipo `Carro` consiga ser abastecido normalmente.

Isso funciona com um carro normal, mas se um `CarroEletrico` é usado no lugar o programa lança uma exceção, já que carro elétrico não usa gasolina.

Ou seja, o `CarroEletrico` não consegue substituir a classe `Carro` sem mudanças, o que acaba violando o princípio da substituição de Liskov.

## Solução

A solução foi criar uma estrutura mais genérica para os veículos e separar os carros a gasolina dos carros elétricos.

Assim, só os carros que realmente usam gasolina possuem o método `abastecer()`, evitando comportamentos incorretos.