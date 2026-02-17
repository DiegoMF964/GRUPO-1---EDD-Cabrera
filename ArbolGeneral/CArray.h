#ifndef CARRAY_H
#define CARRAY_H

template <typename T>
class CArray {
protected:
    T* m_data;
    int m_size;
    int m_capacity;

public:
    CArray() : m_data(nullptr), m_size(0), m_capacity(0) {}
    ~CArray() { delete[] m_data; }

    T* begin() { return m_data; } 
    T* end() { return m_data + m_size; }

    void resize(int newCap) { 
        T* tmp = new T[newCap];
        for (int i = 0; i < m_size; i++) {
            tmp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = tmp;
        m_capacity = newCap; 
    } 

    void push_back(const T& val) {
        if (m_size == m_capacity) {
            int newCap = (m_capacity == 0) ? 4 : m_capacity * 2;
            this->resize(newCap); 
        }
        m_data[m_size++] = val;
    }

    int search(const T& val) const { 
        for (int i = 0; i < m_size; i++) 
            if (m_data[i] == val) return i; 
        return -1; 
    }

    void removeAt(int idx) { 
        for (int i = idx; i < m_size - 1; i++) 
            m_data[i] = m_data[i + 1]; 
        m_size--; 
    }

    bool removeByValue(const T& val) {
        int idx = search(val); 
        if (idx == -1) return false; 
        removeAt(idx); 
        return true; 
    }

    int size() const { return m_size; } 
    bool empty() const { return m_size == 0; }
    T& operator[](int i) { return m_data[i]; }

    template <typename ObjFunc, typename ...Args> 
    void Foreach(ObjFunc fn, Args... args) {
        for (auto iter = begin(); iter != end(); ++iter) 
            fn(*iter, args...); 
    }
};

#endif