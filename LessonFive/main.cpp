#include <iostream>
#include <utility>
#include <vector>

template <class T>
class PairOne{
private:
    T m_first;
    T m_second;
public:
    PairOne(T a, T b): m_first(a), m_second(b){}

    T first(){
        return m_first;
    }

    T second(){
        return m_second;
    }
};

void TaskOne(){
    PairOne<int> p1(6, 9);
    std::cout << "PairOne: " << p1.first() << " " << p1.second() << "\n";

    PairOne<double> p2(3.4, 7.8);
    std::cout << "PairOne: " << p2.first() << " " << p2.second() << "\n";
}

template<class T, class S>
class PairTwo{
private:
    T m_first;
    S m_second;
public:
    PairTwo(T a, S b): m_first(a), m_second(b){}

    T first(){
        return m_first;
    }

    S second(){
        return m_second;
    }
};

void TaskTwo(){
    PairTwo<int, double> p1(6, 7.8);
    std::cout << "PairOne: " << p1.first() << " " << p1.second() << "\n";

    PairTwo<double, int> p2(3.4, 5);
    std::cout << "PairOne: " << p2.first() << " " << p2.second() << "\n";
}

template <class T, class U> class Pair{};
template <class U> class Pair<std::string, U>{
protected:
    std::string m_first;
    U m_second;

public:
    Pair(std::string str, U val) : m_first(std::move(str)), m_second(val){}

    std::string first(){
        return m_first;
    };

    U second(){
        return m_second;
    }
};

template<class U>
class StringValuePair : public Pair<std::string, U>{
public:
    StringValuePair(std::string str, U val) : Pair<std::string, U>(str, val){}
};

void TaskThree(){
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << " " << svp.second() << std::endl;
}

class Card{
public:
    enum suit {DIAMONDS = 'D', HEARTS = 'H', CLUBS = 'C', SPADES = 'S'};
    enum rank {SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10, ACE = 1};

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

};

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

class GenericPlayer : Hand{
private:
    std::string m_name;
public:
    virtual bool IsHitting() = 0;

    bool IsBoosted() {
        return (Hand::GetTotal() > 21);
    }

    void Bust(){
        std::cout << "\"" << m_name << "\" is bust!" << std::endl;
    }
};

int main() {
    TaskOne();
    TaskTwo();
    TaskThree();

    return 0;
}
