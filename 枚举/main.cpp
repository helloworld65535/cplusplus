#include <iostream>


namespace CardGame_Scoped
{
    enum class Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs) //枚举符必须由枚举类型限定
        {
            std::cout << "CardGame_Scoped" << std::endl;
        }
    }
}

namespace CardGame_NonScoped
{
    enum Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Clubs) //枚举符是可见的，没有限定
        {
            std::cout << "CardGame_NonScoped" << std::endl;
        }
    }
}

int main(void)
{
    CardGame_Scoped::PlayCard(CardGame_Scoped::Suit::Clubs);

    CardGame_NonScoped::PlayCard(CardGame_NonScoped::Clubs);
    
    return 0;
}