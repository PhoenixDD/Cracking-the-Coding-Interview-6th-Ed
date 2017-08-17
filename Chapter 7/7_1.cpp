#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define CARDS_IN_DECK 13
#define SUITS_IN_DECK 4
enum Suit
{
    Spades,Hearts,Diamond,Clubs
};
enum Face
{
    Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King
};
class Card
{
    public:
        Card(Suit suit,Face face):suit(suit),face(face){}
        Card(){};
        Suit getSuit(){return suit;}
        Face getFace(){return face;}
    private:
        Suit suit;
        Face face;
};
class Deck
{
    public:
        Deck()
        {
            srand(time(NULL));
            Size=SUITS_IN_DECK*CARDS_IN_DECK-1;
            for(int i=0;i<SUITS_IN_DECK;i++)
                for(int j=0;j<CARDS_IN_DECK;j++)
                {
                    cards[i*CARDS_IN_DECK+j]=Card((Suit)i,(Face)j);
                }
        }
        void deal()
        {
            cout<<cards[Size].getSuit()<<cards[Size].getFace();
            Size--; .

        }
        Card Shuffle()
        {
            for(int i=Size;i>0;i--)
            {
                int random=rand()%i+1;
                swap(cards[i],cards[random]);
            }
        }
        void printdeck()
        {
            for(int i=0;i<=Size;i++)
            {
                cout<<cards[i].getSuit()<<cards[i].getFace()<<"\t";
                if((i+1)%4==0)
                    cout<<endl;
            }
        }
    private:
        Card cards[SUITS_IN_DECK*CARDS_IN_DECK];
        int Size;


};
int main()
{
    Deck deck;
    deck.printdeck();
    cout<<endl<<endl;
    deck.Shuffle();
    deck.printdeck();
    cout<<endl<<endl;
    deck.deal();
    cout<<endl<<endl;
    deck.printdeck();
    cout<<endl<<endl;
}
