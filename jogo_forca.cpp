#include <iostream>
#include <cstdlib>
#define linha cout << "\n===================\n";
using namespace std;

int main(){
    char palavra[30],letra, secreta[30];
    int vidas = 5,tamanho = 0, index = 0,acertos = 0;
    bool letra_certa = false;

    linha;
    cout << "JOGO DA FORCA";
    linha;
    cout << "digite uma palavra para o seu amigo acertar: ";
    cin >> palavra;
    linha;

    while(palavra[index] != '\0'){
        index++;
        tamanho++;
    }
    for(index=0; index<30; index++){
        secreta[index] = '-';
    }

    while(vidas > 0 && acertos < tamanho){
        system("cls");
        linha;
        cout << "VIDAS: "<< vidas << "\npalavra secreta: ";
        for(index =0; index < tamanho; index++){
            cout << secreta[index];
        }
        cout <<" \ndigite uma letra: ";
        cin >> letra;


        for(index = 0; index < tamanho; index++){
            if(secreta[index] == '-'){
                if(palavra[index] == letra){
                    letra_certa = true;
                    acertos++;
                    break;
                }else{letra_certa = false;}
            }
        }
        if(letra_certa == true){
            secreta[index] = letra;
        }else{vidas--;}
    }

    system("cls");
    linha;
    if(acertos == tamanho){
        cout << "voce ganhou\n";
    }else{cout << "voce perdeu\n";}
    system("pause");

}


