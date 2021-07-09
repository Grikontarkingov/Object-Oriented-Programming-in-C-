#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

bool isInteger(const std::string& str){
    bool isInt = true;

    for(auto& n : str){
        if(!(isdigit(n))){
            isInt = false;
        }
    }

    return isInt;
}

void TaskOne(){
    int count = 0;
    std::string a;
    std::cout << "Enter integer: ";
    std::cin >> a;

    while(!(isInteger(a))){
        std::cout << "You entered not a number. Please re-entered: ";
        std::cin >> a;
        count++;

        if(count >= 3){
            std::cerr << "You attempts are over!";
            return;
        }
    }

    std::stringstream strStr;
    strStr << a;

    int b;
    strStr >> b;
    std::cout << "You are entered - " << b << std::endl;
    strStr.clear();
}

std::ostream& endll(std::ostream &out){
    out << "\n\n";
    out.flush();
    return out;
}

void TaskTwo(){
    std::cout << "Task " << endll << "two" << std::endl;
}

class Card{
public:
    enum suit {CLUBS = 'C', DIAMONDS = 'D', HEARTS = 'H',  SPADES = 'S'};
    enum rank {TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 1};

    Card(rank r = ACE, suit s = SPADES, bool isUP = true) : m_rank(r), m_suit(s), m_isFaceUp(isUP){}
    void Flip(){
        if(!m_isFaceUp){
            m_isFaceUp = true;
        }
    }

    int GetValue() const{
        return m_rank;
    }

private:
    suit m_suit;
    rank m_rank;
    bool m_isFaceUp;

    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
};

std::ostream& operator<<(std::ostream& os, const Card& aCard){
    const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const std::string SUITS[] = {"c", "d", "h", "s"};

    if(aCard.m_isFaceUp){
        os << RANKS[aCard.m_rank] << SUITS[aCard.m_suit];
    }
    else{
        os << "XX";
    }

    return os;
}

class Hand{
public:
    Hand(){ m_Cards.reserve(7); }

    virtual ~Hand(){
        Clear();
    }

    void Add(Card* pCard){
        m_Cards.push_back(pCard);
    }

    void Clear(){
        std::vector<Card*>::iterator iter = m_Cards.begin();
        for(iter = m_Cards.begin(); iter != m_Cards.end();++iter){
            delete *iter;
            *iter = 0;
        }

        m_Cards.clear();
    }

    int GetTotal() const{
        int maxSumForAce = 10;
        int aceSmall = 1;
        int aceBig = 11;
        int total = 0;
        bool isAce = false;

        for(auto& n : m_Cards){
            if(n->GetValue() != Card::ACE){ total += n->GetValue(); }
            else{ isAce = true; }
        }

        if(isAce && total <= maxSumForAce){ total += aceBig; }
        else{ total += aceSmall; }

        return total;
    }
protected:
    std::vector<Card* > m_Cards;
};

class GenericPlayer : public Hand{
    friend std::ostream&  operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string&  name = "") : m_name(name){}

    virtual ~GenericPlayer(){}

    virtual bool IsHitting() const = 0;

    bool IsBoosted() const{
        return (GetTotal() > 21);
    }

    void Bust(){
        std::cout << "\"" << m_name << "\" busts!" << std::endl;
    }

protected:
    std::string m_name;
};

std::ostream& operator<<(std::ostream &os, const GenericPlayer &aGenericPlayer) {
    os << aGenericPlayer.m_name << ":\t";

    std::vector<Card*>::const_iterator pCard;
    if(!aGenericPlayer.m_Cards.empty()){
        for(pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard){
            os << *pCard << "\t";
        }

        if(aGenericPlayer.GetTotal() != 0){
            std::cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else{
        os << "empty";
    }

    return os;
}

class Player : public GenericPlayer{
public:
    Player(const std::string& name = "");

    virtual ~Player(){}

    virtual bool isHitting() const {
        std::cout << m_name << " , do you want a hit? (Y/N): ";
        char answer;
        std::cin >> answer;

        return (answer == 'y' || answer == 'Y');
    }

    void Win() const{
        std::cout << m_name << " wins!" << std::endl;
    }

    void Lose() const{
        std::cout << m_name << " loses!" << std::endl;
    }

    void Push() const{
        std::cout << m_name << " pushes!" << std::endl;
    }
};

class House : public GenericPlayer{
public:
    House(const std::string& name = "House");

    virtual ~House();

    virtual bool isHitting() const{
        return (GetTotal() <= 16);
    }

    void FlipFirstCard(){
        if(!m_Cards.empty()){
            m_Cards[0]->Flip();
        }
        else{
            std::cout << "No card to flip!\n";
        }
    }
};

int main() {
    TaskOne();
    TaskTwo();

    return 0;
}
