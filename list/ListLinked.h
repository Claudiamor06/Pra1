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

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida!");

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;

            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida!");

        T value;
        if (pos == 0) {
            value = first->data;
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;

            Node<T>* toDelete = prev->next;
            value = toDelete->data;
            prev->next = toDelete->next;
            delete toDelete;
        }
        --n;
        return value;
    }

    T get(int pos) override {
        return (*this)[pos];
    }

    int search(T e) override {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e)
                return index;
            current = current->next;
            ++index;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Índice fuera de rango!");

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i)
            current = current->next;

        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "List => [\n";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << "  " << current->data << "\n";
            current = current->next;
        }
        out << "]\n";
        return out;
    }
};

#endif

