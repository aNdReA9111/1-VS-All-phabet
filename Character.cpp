#include <iostream>
#include "Character.hpp"
#include "map.hpp"
#include "bullet.cpp"
#include "bullet.hpp"
#include "liste.hpp"
using namespace std;

Character::Character(int x, int y, char look, int hp, int atk, bool gun){
    this->x = x;
    this->y = y;
    this->look = look;
    this->hp = hp;
    this->atk = atk;
    this->gun = gun;
} 

void Character::SetHp(int hp){
    this->hp = hp;
}

int Character::getHp (){
    return this->hp;
};

//Considerando che le coordinate in alto a destra del terminale sono x=0, y=0
void Character::move(int new_x=0, int new_y=0, int mode = 0){
    //se la mode è 0 e la cella è vuota e nella mappa, sposta le coordinate correnti a quelle nuove (default)
    if(mode == 0)
        if(is_empty(m, new_x, new_y)==true && is_inside(m, new_x, new_y)==true) 
            (this->x) = new_x, (this->y) = new_y;
    
    //se la mode è 1 e la cella è vuota e nella mappa,muove verso destra di tot "new_x" posizioni (va avanti)
    else if(mode == 1)
        if(is_empty(m, this->x + new_x, this->y)==true && is_inside(m, this->x + new_x, this->y)==true)
            (this->x)+=new_x;
    
    //se la mode è 2 e la cella è vuota e nella mappa,muove verso sinistra di tot "new_x" posizioni (torna indietro)
    else if(mode == 2)
        if(is_empty(m, this->x - new_x, this->y)==true && is_inside(m, this->x - new_x, this->y)==true)
            (this->x)-=new_x;

    //se la mode è 3 e la cella è vuota e nella mappa,muove verso sopra di tot "new_x" posizioni
    else if(mode == 3)
        if(is_empty(m, this->x, this->y - new_y)==true && is_inside(m, this->x, this->y - new_y)==true)
            (this->y)-=new_y;

    //se la mode è 3 e la cella è vuota e nella mappa,muove verso sopra di tot "new_x" posizioni
    else if(mode == 4)
        if(is_empty(m, this->x, this->y + new_y)==true && is_inside(m, this->x, this->y + new_y)==true)
            (this->y)+=new_y;
}

/*
void Character::fire(int dir = 0, int pow = 1){
    if(this->gun){ 
        
        lista_bul = new_bulletp(lista_bul, ) //lista_bul da inizializzare come variabile globale di tipo "pbul"





    }
}
*/