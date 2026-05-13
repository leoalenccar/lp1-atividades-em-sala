#include <iostream>
#include <vector>

class Produto
{
    std::string nome;
    double preco;

public:

    void set_nome(std::string n) {nome = n;}
    void set_preco(double p) {preco = p;}

    virtual void exibir_informacoes()
    {
        std::cout << "Nome: " << nome << ", Preço: R$ " << preco << std::endl;
    }
};


class ProdutoLimpeza : public Produto
{
    std::string tipoUso;

public:

    void set_tipo (std::string tipo) {tipoUso = tipo;}

    void exibir_informacoes() override
    {
        Produto::exibir_informacoes();
        std::cout << "Tipo de Uso: " << tipoUso << std::endl;
    }
};


class ProdutoAlimenticio : public Produto
{
    std::string validade;

public:

    void set_validade (std::string v) {validade = v;}

    void exibir_informacoes() override
    {
        Produto::exibir_informacoes();
        std::cout << "Validade: " << validade << std::endl;
    }
};


class ProdutoEletronico : public Produto
{
    std::string voltagem, garantia;

public:

    void set_voltagem (std::string v) {voltagem = v;}
    void set_garantia (std::string g) {garantia = g;}

    void exibir_informacoes() override
    {
        Produto::exibir_informacoes();
        std::cout << "Voltagem: " << voltagem << ", Garantia: " << garantia << std::endl;
    }
};


int main() {
    std::vector<Produto*> lista;
    int opcao;

    do 
    {
        std::cout << "1 - Cadastrar Produto Limpeza" << std::endl;
        std::cout << "2 - Cadastrar Produto Alimenticio" << std::endl;
        std::cout << "3 - Cadastrar Produto Eletronico" << std::endl;
        std::cout << "4 - Exibir Produtos" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;
        std::cout << std::endl;
        std::cin.ignore();

        if (opcao == 1)
        {
            ProdutoLimpeza* p = new ProdutoLimpeza();
            std::string n, tipo; 
            double preco;
            std::cout << "Nome: ";
            std::getline(std::cin, n);
            std::cout << "Preco: "; 
            std::cin >> preco; 
            std::cin.ignore();
            std::cout << "Tipo de Uso: ";
            std::getline(std::cin, tipo);
            p->set_nome(n);
            p->set_preco(preco);
            p->set_tipo(tipo);
            lista.push_back(p);

        }
        else if (opcao == 2)
        {
            ProdutoAlimenticio* p = new ProdutoAlimenticio();
            std::string n, val;
            double preco;
            std::cout << "Nome: ";
            std::getline(std::cin, n);
            std::cout << "Preco: ";
            std::cin >> preco;
            std::cin.ignore();
            std::cout << "Validade: ";
            std::getline(std::cin, val);
            p->set_nome(n);
            p->set_preco(preco);
            p->set_validade(val);
            lista.push_back(p);

        } 
        else if (opcao == 3)
        {
            ProdutoEletronico* p = new ProdutoEletronico();
            std::string n, volt, gar;
            double preco;
            std::cout << "Nome: ";
            std::getline(std::cin, n);
            std::cout << "Preco: ";
            std::cin >> preco;
            std::cin.ignore();
            std::cout << "Voltagem: ";
            std::getline(std::cin, volt);
            std::cout << "Garantia: ";
            std::getline(std::cin, gar);
            p->set_nome(n);
            p->set_preco(preco);
            p->set_voltagem(volt);
            p->set_garantia(gar);
            lista.push_back(p);
        }
        else if (opcao == 4)
        {
            std::cout << "Lista de Produtos:" << std::endl;
            for (Produto* p : lista)
            {
                p->exibir_informacoes();
                std::cout << std::endl;
            }
        }

    } while (opcao != 0);

    return 0;
}