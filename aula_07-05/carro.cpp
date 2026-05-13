#include <iostream>
using namespace std;

class Veiculo
{
public:
    virtual ~Veiculo() {}
};

class CarroGasolina : public Veiculo
{
public:
    void abastecer()
    {
        cout << "Veiculo abastecido com gasolina.\n";
    }
};

// Carro elétrico
class CarroEletrico : public Veiculo
{
public:
    void carregarBateria()
    {
        cout << "Bateria carregada.\n";
    }
};

void prepararViagem(CarroGasolina& veiculo)
{
    veiculo.abastecer();
}

int main()
{
    CarroGasolina carro;
    CarroEletrico eletrico;

    prepararViagem(carro);

    eletrico.carregarBateria();

    return 0;
}