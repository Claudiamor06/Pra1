#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "list/List.h"
#include "list/Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Índice fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i)
            current = current->next;

        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

    // Métodos heredados de List<T>
    int size() const override { return n; }
    bool empty() const override { return n == 0; }

    void insert(int pos, const T& data) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida");

        if (pos == 0) {
            first = new Node<T>(data, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;

            prev->next = new Node<T>(data, prev->next);
        }
        ++n;
    }

    void erase(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");

        Node<T>* toDelete;
        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;

            toDelete = prev->next;
            prev->next = toDelete->next;
        }
        delete toDelete;
        --n;
    }
};

#endif

