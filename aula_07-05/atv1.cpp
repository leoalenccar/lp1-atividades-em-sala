#include <iostream>

class Personagem
{
    double hp_atual, mp_atual;
    double hp_maximo, mp_maximo;
    int dano;

public:

    double get_hpA() {return hp_atual;}
    double get_mpA() {return mp_atual;}
    double get_hpM() {return hp_maximo;}
    double get_mpM() {return mp_maximo;}
    int get_dano() {return dano;}

    void set_hp(double hp)
    {
        hp_maximo = hp;
        hp_atual = hp;
    }

    void set_mp(double mp)
    {
        mp_maximo = mp;
        mp_atual = mp;
    }

    void set_dano (int d) {dano = d;}

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

    int usar_especial()
    {
        if ((mp_atual - mp_maximo * 0.15) >= 0)
        {
            gastar_mp();
            return dano * 2;
        }
        else
        {
            std::cout << "Pontos de MP insuficientes." << std::endl;
            return 0;
        }
    }
};