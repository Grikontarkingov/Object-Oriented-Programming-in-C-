#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class ArrayInt{
private:
    int m_length;
    int m_size;
    int *m_data;

public:
    ArrayInt()
    : m_length(0),m_size(0), m_data(nullptr){}
    ArrayInt(int length)
    : m_length(length), m_size(length){
        assert(length >= 0);

        if(length > 0){ m_data = new int[length]; }
        else{ m_data = nullptr; }
    }

    ~ArrayInt(){ delete[] m_data; }

    void erase(){
        delete[] m_data;

        m_data = nullptr;
        m_size = 0;
        m_length = 0;
    }

    int getSize() const { return m_size; }
    int getLength() const { return m_length; }

    int &operator[](int index){
        assert(index >= 0 && index < m_size);

        return m_data[index];
    }

    void resize(int newSize){
        if(newSize == m_size) {

            return;
        }
        if(newSize <= 0){
            erase();

            return;
        }

        int *data;
        if(newSize > m_length){
            m_length = newSize + 5;
            data = new int[m_length];
        }
        else{
            data = new int[m_length];
        }

        if(m_size > 0){
            int elementsToCopy = (newSize > m_size) ? m_size : newSize;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_size = newSize;
    }

    void resize(int newSize, int value){
        if(newSize == m_size) {

            return;
        }
        if(newSize <= 0){
            erase();

            return;
        }

        int *data;
        if(newSize > m_length){
            m_length = newSize + 5;
            data = new int[m_length];
        }
        else{
            data = new int[m_length];
        }

        if(m_size > 0){
            int elementsToCopy = (newSize > m_size) ? m_size : newSize;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
            for(int index = elementsToCopy; index < newSize; index++){
                data[index] = value;
            }
        }

        delete[] m_data;
        m_data = data;
        m_size = newSize;
    }

    void reserve(int newLength){
        if(newLength <= m_length) {
            return;
        }

        int *data = new int[m_length];

        if(m_size > 0){
            int elementsToCopy = (newLength > m_size) ? m_size : newLength;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void shrink(){
        if(m_size == m_length) {
            return;
        }

        int *data = new int[m_size];

        if(m_size > 0){
            for(int index = 0; index < m_size; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_length = m_size;
    }

    void insertBefore(int value, int index){
        assert(index >= 0 && index <= m_size);

        if(m_size + 1 > m_length){
            m_length += 5;
        }
        int *data = new int[m_length];

        for(int before = 0; before < index; before++){
            data[before] = m_data[before];
        }

        data[index] = value;

        for(int after = index; after < m_length; after++){
            data[after + 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        m_size++;
    }

    void push_back(int value){
        insertBefore(value, m_size);
    }

    void pop_back(){
        m_size--;
    }

    void pop_front(){
        for(int i = 1; i < m_size; i++){
            m_data[i - 1] = m_data [i];
        }

        m_size--;
    }

    static void swap(int* a, int* b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    void qsort(int first, int last){
        int i = first;
        int j = last;
        int x = m_data[(first + last) / 2];

        do{
            while (m_data[i] < x) i++;
            while (m_data[j] > x) j--;
            if(i <= j){
                swap(&m_data[i], &m_data[j]);
                i++;
                j--;
            }
        }while(i <= j);

        if(i < last){
            qsort(i, last);
        }
        if(first < j){
            qsort(first, j);
        }
    }

    void printArr(){
        for(int i = 0; i < m_size; i++){
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

void TaskOne(){
    ArrayInt arrInt;
    arrInt.reserve(4);
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.reserve(1);
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.push_back(1);
    arrInt.push_back(2);
    arrInt.push_back(3);
    arrInt.push_back(4);

    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.resize(5, 5);
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.resize(10, 6);
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.resize(15, 7);
    arrInt.push_back(4);
    arrInt.push_back(1);
    arrInt.push_back(8);
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.printArr();
    arrInt.pop_back();
    arrInt.printArr();
    arrInt.pop_front();
    arrInt.printArr();
    arrInt.qsort(0, arrInt.getSize());
    arrInt.printArr();
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
    arrInt.shrink();
    std::cout << "Size: " << arrInt.getSize() << " Capacity: " << arrInt.getLength() << std::endl;
}

void TaskTwo(){
    int count = 0;
    std::vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);

    std::cout << "Your vector: ";
    for(auto& n : v){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i - 1]){
            count++;
        }
    }

    int unique = (int)v.size() - count;
    std::cout << "In vector have unique value is: " << unique << std::endl;
}

enum suit {DIAMONDS = 'D', HEARTS = 'H', CLUBS = 'C', SPADES = 'S'};
enum rank {SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10, ACE = 1};

class Card{
private:
    suit m_suit;
    rank m_rank;
    bool m_isFaceUp;

public:
    void Flip(){
        if(!m_isFaceUp){
            m_isFaceUp = true;
        }
    }

    int GetValue(){
        return m_rank;
    }
};

class Hand{
private:
    std::vector<Card* > m_Cards;
public:
    void Add(Card* pCard){
        m_Cards.push_back(pCard);
    }

    void Clear(){
        m_Cards.clear();
    }

    int GetTotal(){
        int limitWin = 21;
        int aceSmall = 1;
        int aceBig = 11;
        int total = 0;
        bool isAce = false;

        for(auto& n : m_Cards){
            if(n->GetValue() != 1){ total += n->GetValue(); }
            else{ isAce = true; }
        }

        if(total + aceBig > limitWin){ total += aceSmall; }
        else{ total += aceBig; }

        return total;
    }
};

int main() {
    std::cout << "Task one" << std::endl;
    TaskOne();
    std::cout << "Task two" << std::endl;
    TaskTwo();

    return 0;
}
