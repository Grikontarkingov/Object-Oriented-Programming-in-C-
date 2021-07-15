#ifndef _DECK_H_
#define _DECK_H_

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    void Populate();

    void Shuffle();

    void Deal(Hand& aHand);

    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif //_DECK_H_
