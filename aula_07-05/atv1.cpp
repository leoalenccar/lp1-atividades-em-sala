#include <iostream>
#include <vector>

class Personagem
{
    double hp_atual, mp_atual;
    double hp_maximo, mp_maximo;
    int dano;
    std::string nome;

public:
    Personagem(std::string n, double hp, double mp, int d)
        : nome(n), hp_maximo(hp), hp_atual(hp), mp_maximo(mp), mp_atual(mp), dano(d) {}

    virtual ~Personagem() {}

    double get_hpA() {return hp_atual;}
    double get_mpA() {return mp_atual;}
    double get_hpM() {return hp_maximo;}
    double get_mpM() {return mp_maximo;}
    int get_dano() {return dano;}
    std::string get_nome() {return nome;}
    bool esta_vivo() {return hp_atual > 0;}

    void recuperar_hp()
    {
        hp_atual += hp_maximo * 0.1;
        if(hp_atual > hp_maximo)
        {
            hp_atual = hp_maximo;
        }
    }

    void perder_hp(double d)
    {
        hp_atual -= d;
    }

    void recuperar_mp()
    {
        mp_atual += mp_maximo * 0.1;
        if(mp_atual > mp_maximo)
        {
            mp_atual = mp_maximo;
        }
    }

    void gastar_mp()
    {
        mp_atual -= mp_maximo * 0.15;
    }

    bool tem_mp_suficiente()
    {
        return (mp_atual >= mp_maximo * 0.15);
    }

    virtual int ataque_simples() = 0;
    virtual int ataque_especial() = 0;
};

class Guerreiro : public Personagem
{
public:
    Guerreiro(std::string n) : Personagem(n, 150, 50, 20) {}

    int ataque_simples() override
    {
        std::cout << get_nome() << " ataca com a espada!" << std::endl;
        return get_dano();
    }

    int ataque_especial() override
    {
        if (tem_mp_suficiente())
        {
            gastar_mp();
            std::cout << get_nome() << " usa corte dimesional!" << std::endl;
            return get_dano() * 2;
        }
        else
        {
            std::cout << "MP insuficiente! Ataque simples usado." << std::endl;
            return ataque_simples();
        }
    }
};

class Mago : public Personagem
{
public:
    Mago(std::string n) : Personagem(n, 80, 120, 15) {}

    int ataque_simples() override
    {
        std::cout << get_nome() << " lança uma magia!" << std::endl;
        return get_dano();
    }

    int ataque_especial() override
    {
        if (tem_mp_suficiente())
        {
            gastar_mp();
            std::cout << get_nome() << " usa magia suprema!" << std::endl;
            return get_dano() * 3;
        }
        else
        {
            std::cout << "MP insuficiente! Ataque simples usado." << std::endl;
            return ataque_simples();
        }
    }
};

class Arqueiro : public Personagem
{
public:
    Arqueiro(std::string n) : Personagem(n, 100, 80, 18) {}
    int ataque_simples() override
    {
        std::cout << get_nome() << " lança uma flecha!" << std::endl;
        return get_dano();
    }
    int ataque_especial() override
    {
        if (tem_mp_suficiente())
        {
            gastar_mp();
            std::cout << get_nome() << " usa flecha perfurante" << std::endl;
            return get_dano() * 2.5;
        }
        else
        {
            std::cout << "MP insuficiente! Ataque simples usado." << std::endl;
            return ataque_simples();
        }
    }
};

void vez_jogador(Personagem* atacante, std::vector<Personagem*>& jogadores)
{
    std::cout << "\n" << atacante->get_nome() << " (HP: " << atacante->get_hpA() 
              << " | MP: " << atacante->get_mpA() << ")" << std::endl;
 
    std::cout << "Escolha quem atacar:" << std::endl;
    std::vector<Personagem*> vitimas_vivas;

    int opcao = 1;
    for (int i = 0; i < jogadores.size(); i++)
    {
        if (jogadores[i] != atacante && jogadores[i]->esta_vivo())
        {
            std::cout << opcao << " - Atacar " << jogadores[i]->get_nome()
                      << " (HP: " << jogadores[i]->get_hpA() << ")" << std::endl;
            vitimas_vivas.push_back(jogadores[i]);
            opcao++;
        }
    }

    int escolha_vitima;
    std::cin >> escolha_vitima;
    while (escolha_vitima < 1 || escolha_vitima > vitimas_vivas.size())
    {
        std::cout << "Digite um número válido: ";
        std::cin >> escolha_vitima;
        std::cout << std::endl;
    }
    Personagem* vitima = vitimas_vivas[escolha_vitima - 1];
 
    std::cout << "Escolha: 1-Ataque Simples | 2-Ataque Especial: ";
    int escolha_ataque;
    std::cin >> escolha_ataque;
    while (escolha_ataque < 1 || escolha_ataque > 2)
    {
        std::cout << "Digite um número válido: ";
        std::cin >> escolha_ataque;
        std::cout << std::endl;
    }

    int dano_causado = 0;
    if (escolha_ataque == 1)
    {
        dano_causado = atacante->ataque_simples();
    }
    else
    {
        dano_causado = atacante->ataque_especial();
    }

    vitima->perder_hp(dano_causado);
    
    std::cout << atacante->get_nome() << " causa " << dano_causado 
              << " de dano a " << vitima->get_nome() << "!" << std::endl;
    std::cout << "Vida atual de " << vitima->get_nome() << ": " 
              << vitima->get_hpA() << std::endl;
 
    if (!vitima->esta_vivo())
    {
        std::cout <<vitima->get_nome() << " FOI DERROTADO!" << std::endl;
    }
}


int main()
{
    std::vector<std::string> nomes;
    std::vector<std::string> classes {"Guerreiro", "Mago", "Arqueiro"};

    std::cout << "=== BEM-VINDO ===" << std::endl << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Nome do personagem " << classes[i] << ": ";
        std::string nome;
        std::cin >> nome;
        nomes.push_back(nome);
    }
    std::cout << std::endl;

    Guerreiro g(nomes[0]);
    Mago m(nomes[1]);
    Arqueiro a(nomes[2]);

    std::vector<Personagem*> jogadores = {&g, &m, &a};

    int turno = 1;

    while (true)
    {
        std::cout << "=== TURNO " << turno << " ===" << std::endl;

        for (int i = 0; i < jogadores.size(); i++)
        {
            if (jogadores[i]->esta_vivo())
            {
                jogadores[i]->recuperar_hp();
                jogadores[i]->recuperar_mp();
            }
        }

        for (int i = 0; i < jogadores.size(); i++)
        {
            if (jogadores[i]->esta_vivo())
            {
                int vivos = 0;
                for (int j = 0; j < jogadores.size(); j++)
                {
                    if (jogadores[j]->esta_vivo())
                    {
                        vivos++;
                    }
                }

                if (vivos <= 1)
                {
                    std::cout << jogadores[i]->get_nome() << " É O VENCEDOR!" << std::endl;
                    return 0;
                }

                vez_jogador(jogadores[i], jogadores);
            }
        }

        turno++;
    }

    return 0;
}