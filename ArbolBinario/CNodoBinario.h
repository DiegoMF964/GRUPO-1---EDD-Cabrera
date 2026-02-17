#ifndef CNODOBINARIO_H
#define CNODOBINARIO_H

template <typename T>
struct CNodoBinario {
    T valor;
    CNodoBinario<T>* m_pLeft;
    CNodoBinario<T>* m_pRight;

    CNodoBinario(T v) : valor(v), m_pLeft(nullptr), m_pRight(nullptr) {}

    ~CNodoBinario() {
        if (m_pLeft) delete m_pLeft;
        if (m_pRight) delete m_pRight;
    }
};

#endif