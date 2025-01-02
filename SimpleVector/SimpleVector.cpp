#include <iostream>
using namespace std;

template <typename T>

class SimpleVector {
private:
    T* data;              // 동적 배열
    int currentsize;       // 현재 원소 개수
    int currentCapacity;   // 최대 용량

public:
    // 생성자 (기본값을 10으로 설정)
    SimpleVector(int size = 10) {
        data = new T[size];       // 동적 배열 생성
        currentsize = 0;          // 현재 원소 개수 초기화   
        currentCapacity = size;   // 최대 용량 초기화
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data; // 동적 메모리 해제
    }

    // 현재 크기 반환
    int size() const {
        return currentsize;
    }

    // 현재 용량 반환
    int capacity() const {
        return currentCapacity;
    }

    // 원소 추가
    void push_back(const T& value) {
        if (currentsize < currentCapacity) {
            data[currentsize] = value;
            currentsize++;
        }
        else {
            cout << "Vector is full" << endl;
        }
    }

    // 마지막 원소 삭제
    void pop_back() {
        if (currentsize > 0) {
            currentsize--;
        }
        else {
            cout << "Vector is empty" << endl;
        }
    }

    // 연산자 오버로딩 (인덱스 접근)
    T& operator[](int index) {
        if (index < 0 || index >= currentsize) {
            throw out_of_range("Index out of range.");
        }
        return data[index];
    }
};

int main() {
    SimpleVector<int> v(10); // 크기가 10인 벡터 생성
    cout << "Initial size: " << v.size() << endl; // 현재 크기 출력

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);// 원소 추가

    cout << "Size after push_back: " << v.size() << endl; // 추가 후 크기 출력

    v.pop_back(); // 마지막 원소 제거
    cout << "Size after pop_back: " << v.size() << endl; // 제거 후 크기 출력

    

    cout << "all data : " ;

    for (int i = 0; i < v.size(); i++) {
		
		cout << v[i] << " "; // 모든 원소 출력
        
    }
    cout << endl;

    return 0;
}
