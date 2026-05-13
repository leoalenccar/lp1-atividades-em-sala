#include <iostream>

class Autenticacao
{
public:

    virtual void coletar_dados() = 0;
    virtual bool validar_dados() = 0;

    virtual void iniciar_sessao()
    {
        std::cout << "Sessão iniciada com sucesso!" << std::endl;
    }

    void autenticar ()
    {
        coletar_dados();
        if (validar_dados())
        {
            iniciar_sessao();
        }
        else
        {
            std::cout << "Autenticacão falhou!" << std::endl;
        }
    }

};

class LoginSenha : public Autenticacao
{
    std::string login, senha;

public:

    void coletar_dados() override
    {
        std::cout << "Login: ";
        std::cin  >> login;
        std::cout << std::endl;
        
        std::cout << "Senha: ";
        std::cin >> senha;
        std::cout << std::endl;
    }

    bool validar_dados() override
    {
        return login.size() > 4 && senha.size() > 8;
    }
};

class GoogleAuth : public Autenticacao
{
    std::string email;

public:

    void coletar_dados() override
    {
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << std::endl;
    }

    bool validar_dados() override
    {
        std::string final = "@gmail.com";
        return email.size() > final.size() && email.substr(email.size() - final.size()) == final;
    }

};

class QRCodeAuth : public Autenticacao
{
    std::string codigo;

public:

    void coletar_dados() override
    {
        std::cout << "Código QR: ";
        std::cin >> codigo;
        std::cout << std::endl;
    }

    bool validar_dados() override
    {
        return codigo == "QR12345";
    }
};


int main()
{
    int opcao;

    do
    {
        std::cout << std::endl;
        std::cout << "1 - Login e Senha" << std::endl;
        std::cout << "2 - Google" << std::endl;
        std::cout << "3 - QR Code" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;
        std::cout << std::endl;

        if (opcao == 1)
        {
            LoginSenha *a = new LoginSenha();
            a->autenticar();
            delete a;
        }
        else if (opcao == 2)
        {
            GoogleAuth *auth = new GoogleAuth();
            auth->autenticar();
            delete auth;
        }
        else if (opcao == 3)
        {
            QRCodeAuth *auth = new QRCodeAuth();
            auth->autenticar();
            delete auth;
        }

    } while (opcao != 0);

    return 0;
}