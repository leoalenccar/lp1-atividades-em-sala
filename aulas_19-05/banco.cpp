#include <iostream>
#include <string>

class Conta
{
    std::string numero;
    std::string titular;
    double saldo;

public:
    Conta(std::string nmr, std::string tit, double sal) : numero(nmr), titular(tit), saldo(sal) {};

    Conta &operator+=(double valor)
    {
        saldo += valor;
        return *this;
    }

    Conta &operator-(double valor)
    {
        if (valor <= saldo)
        {
            saldo -= valor;
            return *this;
        }
        else
        {
            throw std::runtime_error("Erro! Saldo insuficiente.");
        }
    }
    friend std::ostream &operator<<(std::ostream &out, const Conta &c);
};

std::ostream &operator<<(std::ostream &out, const Conta &conta)
{
    out << "Nº da conta: " << conta.numero << std::endl
    << "Titular: " << conta.titular << std::endl
    << "Saldo: R$ " << conta.saldo << std::endl;

    return out;
}

int main()
{
    Conta pessoa1 {"0001", "Fulano", 50};
    Conta pessoa2 {"0002", "Beltrano", 50};

    std::cout << pessoa1 << std::endl;
    std::cout << pessoa2 << std::endl;

    pessoa1 += 20;
    pessoa2 = pessoa2 - 10;

    std::cout << pessoa1 << std::endl;
    std::cout << pessoa2 << std::endl;

    return 0;
}