/*
MOPA Wars Online
Produtores: Arthur Dionizio, Arthur Ruan, Samuel Laerte, Thiago Palacios.
versão alpha: 0.6
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define SETA_BAIXO 80
#define SETA_CIMA 72
#define ENTER 13
#define SKILLP 10
#define HEALTHP 25
#define STAMIN 100
#define STAMIN_DRAIN 10

typedef struct{
    int atk, def, life, pontos;
    char name[100], class[100];
    }tStatus;

//Função que remete as informações do jogo.
void SobreoJogo(){
    puts("-MOPA WARS eh um jogo online de RPG, baseado em turnos.\n"
        "-No inicio, configure seu personagem com seus pontos de habilidade.\n"
        "-Por padrao, cada personagem comeca com 25HP\n"
        "-Cabe a cada jogador atribuir seus pontos de habilidade em ataque, defesa ou HP adicional.\n"
        "-A cada turno, escolha entre atacar ou bloquear.\n"
        "-O vencedor sera o primeiro a reduzir todos os pontos de vida de seu oponente a 0.\n");
}
//Função menu do jogo.
int Menu(){
    int posicao = 1, tecla;

    while(1){
        system("cls");
        if(posicao == 1){
            printf("Escolha uma opcao:\n");
            printf("\t%s[1] - Comecar o jogo. \n", (posicao == 1) ? ">>" : "  ");
            printf("%s[2] - Sobre o jogo. \n", (posicao == 2) ? ">>" : "  ");
            printf("%s[3] - Sair do jogo. \n", (posicao == 3) ? ">>" : "  ");

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao++;
            else if(tecla == SETA_CIMA)
                posicao = 3;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 2){
            printf("Escolha uma opcao:\n");
            printf("%s[1] - Comecar o jogo. \n", (posicao == 1) ? ">>" : "  ");
            printf("\t%s[2] - Sobre o jogo. \n", (posicao == 2) ? ">>" : "  ");
            printf("%s[3] - Sair do jogo. \n", (posicao == 3) ? ">>" : "  ");

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao++;
            else if(tecla == SETA_CIMA)
                posicao--;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 3){
            printf("Escolha uma opcao:\n");
            printf("%s[1] - Comecar o jogo. \n", (posicao == 1) ? ">>" : "  ");
            printf("%s[2] - Sobre o jogo. \n", (posicao == 2) ? ">>" : "  ");
            printf("\t%s[3] - Sair do jogo. \n", (posicao == 3) ? ">>" : "  ");

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 1;
            else if(tecla == SETA_CIMA)
                posicao--;
            else if(tecla == ENTER)
                break;
        }
    }

    return posicao;
}
void Tiraenter(char *name){
    for(int i=0; name[i] != '\0'; i++){
        if(name[i] == '\n'){
            name[i] ='\0';
        }
    }
}
//Função que seta atributos
tStatus atributos(){
    int tecla, posicao = 1, flag = 0, ataque = 0, defesa = 0, HP = 0;
    FILE *fp;

    tStatus status;
    status.pontos=10;
    status.atk=0;
    status.def=0;
    status.life=HEALTHP;

    printf("Digite seu nick:\n");
    fgets(status.name, 100, stdin);
    Tiraenter(status.name);

     while(1){
            system("cls");
            if(posicao == 1){
                printf("Escolha uma opcao:\n");
                printf("\t%sCriar personagem. \n", (posicao == 1) ? ">>" : "  ");
                printf("%sEscolher classe. \n", (posicao == 2) ? ">>" : "  ");

                tecla = getch();

                if(tecla == SETA_BAIXO)
                    posicao++;
                else if(tecla == ENTER){
                    flag = 1;
                    break;
                }
            }
            else if(posicao == 2){
                printf("Escolha uma opcao:\n");
                printf("%sCriar personagem. \n", (posicao == 1) ? ">>" : "  ");
                printf("\t%sEscolher classe. \n", (posicao == 2) ? ">>" : "  ");

                tecla = getch();

                if(tecla == SETA_CIMA)
                    posicao--;
                else if(tecla == ENTER){
                    flag = 1;
                    break;
                }
            }
        }

    if (posicao == 1){
        while(1){
            while(1){
                system("cls");

                if(posicao == 1){
                    printf("Pontos disponiveis: %d\n", status.pontos);
                    printf("\t%sAtaque: %d\n", ">>" , status.atk);
                    printf("Armadura: %d\n", status.def);
                    printf("Vida: %d \n", status.life);

                    tecla = getch();

                    if(tecla == ENTER){
                        status.atk++;
                        status.pontos -= 1;
                        if(status.pontos <= 0 && tecla == ENTER){
                            break;
                        }
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao = 2;
                    else if(tecla == SETA_CIMA)
                        posicao = 3;
                }
                else if(posicao == 2){
                    printf("Pontos disponiveis: %d\n", status.pontos);
                    printf("Ataque: %d\n", status.atk);
                    printf("\t%sArmadura: %d\n", ">>", status.def);
                    printf("Vida: %d \n", status.life);

                    tecla = getch();

                    if(tecla == ENTER){
                        status.def++;
                        status.pontos -= 1;
                        if(status.pontos <= 0 && tecla == ENTER){
                            break;
                        }
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao = 3;
                    else if(tecla == SETA_CIMA)
                        posicao = 1;
                }
                else if(posicao ==3){
                    printf("Pontos disponiveis: %d\n", status.pontos);
                    printf("Ataque: %d\n", status.atk);
                    printf("Armadura: %d\n", status.def);
                    printf("\t%sVida: %d\n", ">>", status.life);

                    tecla = getch();

                    if(tecla == ENTER){
                        status.life++;
                        status.pontos -= 1;
                        if(status.pontos <= 0 && tecla == ENTER){
                            break;
                        }
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao = 1;
                    else if(tecla == SETA_CIMA)
                        posicao = 2;
                }
            }
            posicao = 1;

            while(1){
                system("cls");
                if(posicao == 1){
                    printf("Talentos jogador:\nAtaque: %d\nDefesa: %d\nvida: %d\n\n", status.atk, status.def, status.life);
                    printf("Suas atribuacoes de pontos foram feitas, pronto para comecar a batalha?\n");
                    printf("\t%sSim. \n", (posicao == 1) ? ">>" : "  ");
                    printf("%sResetar atributos. \n", (posicao == 2) ? ">>" : "  ");

                    tecla = getch();

                    if(tecla == SETA_BAIXO)
                        posicao++;
                    else if(tecla == ENTER){
                        flag = 1;
                        break;
                    }
                }
                else if(posicao == 2){
                    printf("Talentos jogador:\nAtaque: %d\nDefesa: %d\nvida: %d\n\n", status.atk, status.def, status.life);
                    printf("Suas atribuacoes de pontos foram feitas, pronto para comecar a batalha?\n");
                    printf("%sSim. \n", (posicao == 1) ? ">>" : "  ");
                    printf("\t%sResetar atributos. \n", (posicao == 2) ? ">>" : "  ");

                    tecla = getch();

                    if(tecla == SETA_CIMA)
                        posicao--;
                    else if(tecla == ENTER){
                        status.pontos = 10;
                        posicao = 1;
                        status.atk = status.def = 0;
                        status.life = HEALTHP;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
    }
    else if(posicao == 2){
        posicao = 1;
        while(1){
        //arquivo de personagens
            while(1){

                system("cls");

                if(posicao == 1){
                    printf("Classes: \n");
                    printf("\t%sGuerreiro\n", ">>");
                    printf("Paladino\n");
                    printf("Cacador\n");

                    tecla = getch();

                    if(tecla == ENTER){//arquivo guerreiro
                        fp = fopen("guerreiro.txt", "r");
                        if(fp == NULL){
                            puts("Impossivel abrir");
                            break;
                        }
                        while(1){
                            fscanf(fp,"%d %d %d", &ataque, &defesa, &HP);
                            if (feof(fp)){
                                break;
                            }
                            status.atk = ataque;
                            status.def = defesa;
                            status.life = HP;
                        }
                        fclose(fp);
                        break;
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao++;
                    else if(tecla == SETA_CIMA)
                        posicao = 3;
                }
                else if(posicao == 2){
                    printf("Classes: \n");
                    printf("Guerreiro\n");
                    printf("\t%sPaladino\n", ">>");
                    printf("Cacador\n");

                    tecla = getch();

                    if(tecla == ENTER){ //arquivo paladino
                        fp = fopen("paladino.txt", "r");
                        if(fp == NULL){
                            puts("Impossivel abrir");
                            break;
                        }
                        while(1){
                            fscanf(fp,"%d %d %d", &ataque, &defesa, &HP);
                            if (feof(fp)){
                                break;
                            }
                            status.atk = ataque;
                            status.def = defesa;
                            status.life = HP;
                        }
                        fclose(fp);
                        break;
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao = 3;
                    else if(tecla == SETA_CIMA)
                        posicao = 1;
                }
                else if(posicao ==3){
                    printf("Classes: \n");
                    printf("Guerreiro\n");
                    printf("Paladino\n");
                    printf("\t%sCacador\n", ">>");

                    tecla = getch();

                    if(tecla == ENTER){//arquivo cacador
                        fp = fopen("cacador.txt", "r");
                        if(fp == NULL){
                            puts("Impossivel abrir");
                            break;
                        }
                        while(1){
                            fscanf(fp,"%d %d %d", &ataque, &defesa, &HP);
                            if (feof(fp)){
                                break;
                            }
                            status.atk = ataque;
                            status.def = defesa;
                            status.life = HP;
                        }
                        fclose(fp);
                        break;
                    }
                    else if(tecla == SETA_BAIXO)
                        posicao = 1;
                    else if(tecla == SETA_CIMA)
                        posicao = 2;
                }
            }
            posicao = 1;

            while(1){
                system("cls");
                if(posicao == 1){
                    printf("Talentos jogador:\nAtaque: %d\nDefesa: %d\nvida: %d\n\n", status.atk, status.def, status.life);
                    printf("Seu personagem foi selecionado, pronto para comecar a batalha?\n");
                    printf("\t%sSim. \n", (posicao == 1) ? ">>" : "  ");
                    printf("%sResetar personagem. \n", (posicao == 2) ? ">>" : "  ");

                    tecla = getch();

                    if(tecla == SETA_BAIXO)
                        posicao++;
                    else if(tecla == ENTER){
                        flag = 1;
                        break;
                    }
                }
                else if(posicao == 2){
                    printf("Talentos jogador:\nAtaque: %d\nDefesa: %d\nvida: %d\n\n", status.atk, status.def, status.life);
                    printf("Seu personagem foi selecionado, pronto para comecar a batalha?\n");
                    printf("%sSim. \n", (posicao == 1) ? ">>" : "  ");
                    printf("\t%sResetar personagem. \n", (posicao == 2) ? ">>" : "  ");

                    tecla = getch();

                    if(tecla == SETA_CIMA)
                        posicao--;
                    else if(tecla == ENTER){
                        posicao = 1;
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
    }
    return status;
}
//Função de jogada do P1.
int OpPlayer1(tStatus player1, tStatus player2){
    //int op1;
    int posicao=1, tecla;

    while(1){
        system("cls");
        printf("Vez de: %s\n\n", player1.name);
        if(posicao == 1){
            printf("Escolha uma opcao:\n");
            printf("\t%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 2;
            else if(tecla == SETA_CIMA)
                posicao = 3;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 2){
            printf("Escolha uma opcao:\n");
            printf("%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("\t%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 3;
            else if(tecla == SETA_CIMA)
                posicao = 1;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 3){
            printf("Escolha uma opcao:\n");
            printf("%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("\t%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 1;
            else if(tecla == SETA_CIMA)
                posicao = 2;
            else if(tecla == ENTER)
                break;
        }
    }
    return posicao;
}
//Função de jogada do P2.
int OpPlayer2(tStatus player1, tStatus player2){
    int tecla, posicao=1;

    while(1){
        system("cls");
        printf("Vez de: %s\n\n", player2.name);
        if(posicao == 1){
            printf("Escolha uma opcao:\n");
            printf("\t%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 2;
            else if(tecla == SETA_CIMA)
                posicao = 3;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 2){
            printf("Escolha uma opcao:\n");
            printf("%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("\t%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 3;
            else if(tecla == SETA_CIMA)
                posicao = 1;
            else if(tecla == ENTER)
                break;
        }
        else if(posicao == 3){
            printf("Escolha uma opcao:\n");
            printf("%sAtacar. \n", (posicao == 1) ? ">>" : "  ");
            printf("%sBloquear. \n", (posicao == 2) ? ">>" : "  ");
            printf("\t%sEsquivar. \n", (posicao == 3) ? ">>" : "  ");
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1.name, player1.life, player1.def, player2.name, player2.life, player2.def);

            tecla = getch();

            if(tecla == SETA_BAIXO)
                posicao = 1;
            else if(tecla == SETA_CIMA)
                posicao = 2;
            else if(tecla == ENTER)
                break;
        }
    }
    return posicao;
}
//Função chance do contra-ataque
int Chances(tStatus *player1, tStatus *player2){

    if(player1->def > player2->atk || player2->def > player1->atk){
        if(((player1->life + player2->life) % 3) != 0){
            return 0;
        }else{
            return 1;
        }
    }
}
//Função esquiva p1
int EsquivaP1(tStatus *player1, tStatus *player2){

    if(player1->life >= player2->life){
        if((player1->life + player2->life) % 2  != 0){
            return 0;
        }else{
            return 1;
        }
    }
    else if(((player1->life + player2->life) % 3) != 0){
        return 0;
    }else{
        return 1;
    }
}
//Função esquiva p2
int EsquivaP2(tStatus *player1, tStatus *player2){

    if(player2->life >= player1->life){
        if(((player1->life + player2->life) % 2 ) != 0){

            return 0;
        }else{
            return 1;
        }
    }
    else if((player1->life + player2->life) % 3 != 0){
        return 0;
    }else{
        return 1;
    }
}
//Função de combate.
void Combate(int op1, int op2, tStatus *player1, tStatus *player2){
    int resto = 0,contraAtaque, esquiva;//variavel usada para descontar hp do jogador prejudicado.

    if(op1==2 && op2==2){ //caso de P1 bloqueio e P2 bloqueio.
        printf("\t*Resultado do turno*");
        printf("\n\n\nAmbos bloquearam!\n\n\n");
        printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

    }
    else if(op1==3 && op2==3){ //caso de P1 esquiva e P2 esquiva.
        printf("\t*Resultado do turno*");
        printf("\n\n\nAmbos esquivaram!\n\n\n");
        printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

    }
    else if(op1 == 2 && op2 == 3){//caso de P1 bloqueio e P2 esquiva.
        printf("\t*Resultado do turno*");
        printf("\n\n\n%s tentou bloquear e %s tentou esquivar!\n\n\n", player1->name, player2->name);
        printf("\n\nTurno sem ação!\n\n");
        printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

    }
    else if(op1 == 3 && op2 == 2){//caso de P1 esquiva e P2 bloqueio.
        printf("\t*Resultado do turno*");
        printf("\n\n\n%s tentou bloquear e %s tentou esquivar!\n\n\n", player2->name, player1->name);
        printf("\n\nTurno sem ação!\n\n");
        printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

    }
    else if(op1 == 3 && op2 == 1){//caso P1 esquiva e P2 ataque.
        esquiva = EsquivaP1(player1, player2);
        if(esquiva){
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s conseguiu esquivar de %s!\n\n\n", player1->name, player2->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }else{
            player1->life -= player2->atk;
            if(player1->life < 0){
                player1->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s atacou diretamente %s e desferiu %d pontos de dano!\n\n\n", player1->name, player2->name,player1->atk);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
    else if(op1 == 1 && op2 == 3){//caso P1 ataque e P2 esquiva.
        esquiva = EsquivaP2(player1, player2);
        if(esquiva==1){
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s conseguiu esquivar de %s!\n\n\n", player2->name, player1->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }else{
            player2->life -= player1->atk;
            if(player2->life < 0){
                player2->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s atacou diretamente %s e desferiu %d pontos de dano!\n\n\n", player1->name, player2->name,player1->atk);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
    else if(op1==1 && op2==1){ //caso de P1 ataque e P2 ataque.
        if(player1->atk > player2->atk){
            player2->life -= player1->atk;
            if(player2->life < 0){
                player2->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s atacou com mais forca e desferiu %d pontos de dano!\n\n\n", player1->name, player1->atk);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
       else if(player1->atk < player2->atk){
            player1->life -= player2->atk;
            if(player1->life < 0){
                player1->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s atacou com mais forca e desferiu %d pontos de dano!\n\n\n", player2->name, player2->atk);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
        else if(player1->atk == player2->atk){
            printf("\t*Resultado do turno*");
            printf("\n\n\nAs forcas dos ataques de %s e %s se igualaram!\n\n\n", player1->name, player2->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
    else if(op1==1 && op2==2){ //caso de P1 ataque e P2 bloqueio.
        if(player1->atk > player2->def){
            resto = player1->atk - player2->def;
            player2->life -= resto;
            player2->def--;
            if(player2->def < 0){
                player2->def = 0;
            }

            if(player2->life < 0){
                player2->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s nao conseguiu bloquear o ataque de %s, e recebeu %d pontos de dano!\n\n\n", player2->name, player1->name, resto);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
        else if(player1->atk < player2->def){
            resto = player2->def - player1->atk;
            contraAtaque = Chances(player1, player2);
            if(contraAtaque){
                player1->life -= resto;
                if(player1->life < 0){
                    player1->life = 0;
                }
                printf("\t*Resultado do turno*");
                printf("\n\n\n%s bloqueou o ataque de %s e contra-atacou com %d pontos de dano!\n\n\n", player2->name, player1->name, resto);
                printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

            }
            else{
                printf("\t*Resultado do turno*");
                printf("\n\n\n%s bloqueou o ataque de %s!\n\n\n", player2->name, player1->name);
                printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

            }
        }
        else if(player1->atk == player2->def){
            player2->def--;
            if(player2->def < 0){
                player2->def = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s bloqueou o ataque de %s!\n\n\n", player2->name, player1->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
    else if(op1==2 && op2==1){ //caso de P1 bloqueio e P2 ataque.
        if(player1->def > player2->atk){
            resto = player1->def - player2->atk;
            contraAtaque = Chances(player1, player2);
            if(contraAtaque){
                player2->life -= resto;
                if(player2->life < 0){
                    player2->life = 0;
                }
                printf("\t*Resultado do turno*");
                printf("\n\n\n%s bloqueou o ataque de %s e contra-atacou com %d pontos de dano!\n\n\n", player1->name, player2->name, resto);
                printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

            }
            else{
                printf("\t*Resultado do turno*");
                printf("\n\n\n%s bloqueou o ataque de %s!\n\n\n", player1->name, player2->name);
                printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

            }
        }
        else if(player1->def < player2->atk){
            resto = player2->atk - player1->def;
            player1->life -= resto;
            player1->def --;
            if(player1->def < 0)
            {
                player1->def = 0;
            }
            if(player1->life < 0){
                player1->life = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s nao conseguiu bloquear o ataque de %s, e recebeu %d pontos de dano!\n\n\n", player1->name, player2->name, resto);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
        else if(player1->def == player2->atk){
            player1->def --;
            if(player1->def < 0){
                player1->def = 0;
            }
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s bloqueou o ataque de %s!\n\n\n", player1->name, player2->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
    else if(op1==3 && op2==1){
        if(Chances(player1,player2)){
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s esquivou o ataque de %s!\n\n\n", player1->name, player2->name);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
        else{
            resto = player1->life-player2->atk;
            player1->life -= resto;
            printf("\t*Resultado do turno*");
            printf("\n\n\n%s nao conseguiu esquivar do ataque de %s e recebeu %d pontos de dano!\n\n\n", player1->name, player2->name,resto);
            printf("%s : %dHP e %d de Armadura  %s : %dHP e %d de Armadura\n\n", player1->name, player1->life, player1->def, player2->name, player2->life, player2->def);

        }
    }
}
//Função jogo principal.
void Jogo(tStatus player1, tStatus player2){
    while(1){
        int op1, op2, killp1=0, killp2=0;

        system("cls");
        op1 = OpPlayer1(player1, player2);

        system("cls");
        op2 = OpPlayer2(player1, player2);

        system("cls");
        printf("Talentos jogador %s:\nAtaque: %d\nDefesa: %d\nvida: %d\n", player1.name, player1.atk, player1.def, player1.life);
        printf("\nTalentos jogador %s:\nAtaque: %d\nDefesa: %d\nvida: %d\n", player2.name, player2.atk, player2.def, player2.life);
        system("cls");

        Combate(op1, op2, &player1, &player2);
        //flags para o caso de morte de algum player.

        if(player1.life<=0)
            killp1=1;
        else
            killp1=0;

        if(player2.life<=0)
            killp2=1;
        else
            killp2=0;

        if(killp1==1){
            printf("%s foi derrotado!\nVencedor: %s!\n\n", player1.name, player2.name);
            break;
        }
        else if(killp2==1){
            printf("%s foi derrotado!\nVencedor: %s!\n\n", player2.name, player1.name);
            break;
        }
        system("pause");
    }
}

//Função main.
int main(void){

    tStatus status, player1, player2;
    int flagmenu=0;

    while(1){

        switch(Menu()){
            case 1:
                flagmenu=1;
                system("cls");
                player1 = atributos();
                system("cls");
                player2 = atributos();
                system("cls");

                printf("\nTalentos jogador %s:\nAtaque: %d\nDefesa: %d\nvida: %d\n", player1.name, player1.atk, player1.def, player1.life);
                printf("\nTalentos jogador %s:\nAtaque: %d\nDefesa: %d\nvida: %d\n", player2.name, player2.atk, player2.def, player2.life);

                system("pause");
                system("cls");

                Jogo(player1 , player2);

                break;
            case 2:
                system("cls");
                SobreoJogo();
                system("pause");
                break;
            case 3:
                return 0;
        }
        if(flagmenu)
            break;
    }
    return 0;
}
