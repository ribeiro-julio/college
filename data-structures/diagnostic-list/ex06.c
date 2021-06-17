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
    for(int i = 53; i >= 0; i--){
        if(!deck->cards[i].was_dealt)
            return &deck->cards[i];
    }

    printf("Nao existem mais cartas no baralho");
    return NULL;
}

Card* on_bottom(Deck *deck){
    for(int i = 0; i >= 53; i++){
        if(!deck->cards[i].was_dealt)
            return &deck->cards[i];
    }

    printf("Nao existem mais cartas no baralho");
    return NULL;
}

Card* deal_hand(Deck *deck){
    srand(time(NULL));

    Card hand[3];
    int r;
    for(int i = 0; i < 3; i++){
        r = rand() % 53;
        while(deck->cards[r].was_dealt)
            r = rand() % 53;
        hand[i] = deck->cards[i];
        deck->cards[i].was_dealt = true;
    }

    return hand;
}

void print_card(Card *card){
    printf("%c de %c\n", &card->value, &card->suit);
}

int main(){
    Deck *deck;

    create_deck(deck);
    printf("Quantidade de cartas no baralho: %d\n", non_dealt_cards(deck));
    printf("Carta no topo:\n");
    print_card(on_top(deck));
    printf("---------------------------------------\n");
    printf("Carta no fundo:\n");
    print_card(on_bottom(deck));
    printf("---------------------------------------\n");
    Card *hand = deal_hand(deck);
    printf("Carteado:\n");
    //print_card(hand[0]);
    //print_card(hand[1]);
    //print_card(hand[2]);
    return 0;
}