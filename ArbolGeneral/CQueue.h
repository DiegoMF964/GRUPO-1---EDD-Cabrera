#ifndef CQUEUE_H
#define CQUEUE_H
#include "CArray.h"
#include <stdexcept>

template <typename T>
class CQueue : public CArray<T> {
private:
    int m_front;
    int m_rear;
    int m_count;

public:
    CQueue() : m_front(0), m_rear(-1), m_count(0) {
        this->resize(8); 
    }

    void enqueue(const T& val) {
        if (m_count == this->m_capacity) {
            int newCap = this->m_capacity * 2;
            T* tmp = new T[newCap];
            for (int i = 0; i < m_count; i++) {
                tmp[i] = this->m_data[(m_front + i) % this->m_capacity];
            }
            delete[] this->m_data;
            this->m_data = tmp;
            m_front = 0;
            m_rear = m_count - 1;
            this->m_capacity = newCap;
        }
        m_rear = (m_rear + 1) % this->m_capacity;
        this->m_data[m_rear] = val;
        m_count++;
    }

    T dequeue() {
        if (m_count == 0) throw std::underflow_error("Cola vacia");
        T val = this->m_data[m_front];
        m_front = (m_front + 1) % this->m_capacity;
        m_count--;
        return val;
    }

    int count() const { return m_count; } 
    bool empty() const { return m_count == 0; }
};

#endif