#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <vector>

// Classe gerada com auxilio de IA
template <typename T>
class CircularList {
private:
    std::vector<T> data;
    size_t currentIndex;

public:
    CircularList() : currentIndex(0) {}

    void add(const T& item) {
        data.push_back(item);
    }

    T& next() {
        T& item = data[currentIndex];
        currentIndex = (currentIndex + 1) % data.size();
        return item;
    }

    T& get(size_t index) {
        return data[index % data.size()];
    }
};

#endif // CIRCULARLIST_H
