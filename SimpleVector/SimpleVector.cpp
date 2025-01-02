#include <iostream>
using namespace std;

template <typename T>

class SimpleVector {
private:
    T* data;              // ���� �迭
    int currentsize;       // ���� ���� ����
    int currentCapacity;   // �ִ� �뷮

public:
    // ������ (�⺻���� 10���� ����)
    SimpleVector(int size = 10) {
        data = new T[size];       // ���� �迭 ����
        currentsize = 0;          // ���� ���� ���� �ʱ�ȭ   
        currentCapacity = size;   // �ִ� �뷮 �ʱ�ȭ
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] data; // ���� �޸� ����
    }

    // ���� ũ�� ��ȯ
    int size() const {
        return currentsize;
    }

    // ���� �뷮 ��ȯ
    int capacity() const {
        return currentCapacity;
    }

    // ���� �߰�
    void push_back(const T& value) {
        if (currentsize < currentCapacity) {
            data[currentsize] = value;
            currentsize++;
        }
        else {
            cout << "Vector is full" << endl;
        }
    }

    // ������ ���� ����
    void pop_back() {
        if (currentsize > 0) {
            currentsize--;
        }
        else {
            cout << "Vector is empty" << endl;
        }
    }

    // ������ �����ε� (�ε��� ����)
    T& operator[](int index) {
        if (index < 0 || index >= currentsize) {
            throw out_of_range("Index out of range.");
        }
        return data[index];
    }
};

int main() {
    SimpleVector<int> v(10); // ũ�Ⱑ 10�� ���� ����
    cout << "Initial size: " << v.size() << endl; // ���� ũ�� ���

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);// ���� �߰�

    cout << "Size after push_back: " << v.size() << endl; // �߰� �� ũ�� ���

    v.pop_back(); // ������ ���� ����
    cout << "Size after pop_back: " << v.size() << endl; // ���� �� ũ�� ���

    

    cout << "all data : " ;

    for (int i = 0; i < v.size(); i++) {
		
		cout << v[i] << " "; // ��� ���� ���
        
    }
    cout << endl;

    return 0;
}
