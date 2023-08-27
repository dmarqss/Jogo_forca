#include <iostream>
#include <cstdlib>
#include <stdio.h>

#define linha cout << "\n===================\n";
using namespace std;

int main(){
    char *palavra,letra, *secreta;
    int vidas = 5,tamanho = 0, index = 0,acertos = 0;
    bool letra_certa = false;

    palavra = (char *)malloc(sizeof(char));
    secreta = (char *)malloc(sizeof(char));

    linha;
    cout << "JOGO DA FORCA";
    linha;
    cout << "digite uma palavra para o seu amigo acertar: ";
    gets(palavra);
    linha;

    while(palavra[index] != '\0'){
        index++;
        tamanho++;
    }
    for(index=0; index<tamanho; index++){
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


