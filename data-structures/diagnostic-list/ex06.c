#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    char value;
    char suit;
    bool was_dealt;
}Card;

typedef struct{
    Card cards[54];
}Deck;

void create_deck(Deck *deck){
    char values[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K' };
    char suites[4] = { 'P', 'E', 'C', 'O' };

    for(int i = 0; i < 52; i++){
        deck->cards[i].value = values[i%13];
        deck->cards[i].suit = suites[i%4];
        deck->cards[i].was_dealt = false;
    }

    deck->cards[52].value = 'C';
    deck->cards[52].suit = ' ';
    deck->cards[52].was_dealt = false;

    deck->cards[53].value = 'C';
    deck->cards[53].suit = ' ';
    deck->cards[53].was_dealt = false;
}

int non_dealt_cards(Deck *deck){
    int count = 0;
    for(int i = 0; i < 54; i++){
        if(!deck->cards[i].was_dealt)
            count++;
    }
    return count;
}

Card* on_top(Deck *deck){
    if(non_dealt_cards(deck) == 0)
        return NULL;

    for(int i = 53; i >= 0; i--){
        if(!deck->cards[i].was_dealt)
            return &deck->cards[i];
    }
}

Card* on_bottom(Deck *deck){
    if(non_dealt_cards(deck) == 0)
        return NULL;

    for(int i = 0; i < 53; i++){
        if(!deck->cards[i].was_dealt)
            return &deck->cards[i];
    }
}

Card* deal_hand(Deck *deck){
    if(non_dealt_cards(deck) <= 2)
        return NULL;
    
    if(non_dealt_cards(deck) == 3){
        Card *hand = malloc(sizeof(Card)*3);

        int index = 0;
        for(int i = 0; i < 54; i++){
            if(!deck->cards[i].was_dealt){
                hand[index] = deck->cards[i];
                deck->cards[i].was_dealt = true;
                index++;
            }
        }

        return hand;
    }

    srand(time(NULL));

    Card *hand = malloc(sizeof(Card)*3);
    int r;
    for(int i = 0; i < 3; i++){
        r = rand() % 53;
        while(deck->cards[r].was_dealt)
            r = rand() % 53;
        hand[i] = deck->cards[r];
        deck->cards[r].was_dealt = true;
    }

    return hand;
}

void print_card(Card *card){
    if(card == NULL)
        return;
    
    if(card->value == 'C')
        printf("Coringa\n");
    else{
        if(card->value == 'D')
            printf("Dez de ");
        else
            printf("%c de ", card->value);
        switch(card->suit){
            case 'P': printf("Paus\n"); return;
            case 'E': printf("Espadas\n"); return;
            case 'C': printf("Copas\n"); return;
            case 'O': printf("Ouros\n"); return;
        }
    }
}

int main(){
    Deck deck;
    Card *hand;

    create_deck(&deck);

    while(non_dealt_cards(&deck) != 0 && hand != NULL){
        printf("Quantidade de cartas no baralho: %d\n", non_dealt_cards(&deck));

        printf("Carta no topo:\n");
        if(on_top(&deck) != NULL)
            print_card(on_top(&deck));
        else
            printf("Nao existem mais cartas no baralho\n");
        printf("---------------------------------------\n");

        printf("Carta no fundo:\n");
        if(on_bottom(&deck) != NULL)
            print_card(on_bottom(&deck));
        else
            printf("Nao existem mais cartas no baralho\n");
        printf("---------------------------------------\n");

        hand = deal_hand(&deck);
        if(hand != NULL){
            printf("Carteado:\n");
            print_card(hand);
            print_card(hand+1);
            print_card(hand+2);
        }
    }
    
    return 0;
}