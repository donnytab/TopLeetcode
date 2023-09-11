#include <iostream>

template <typename T>
class SmartPointer {
public:
    // 构造函数
    SmartPointer() : ptr(new T()), count(new int(1)) {}
    explicit SmartPointer(T* p) : ptr(p), count(new int(1)) {}
    explicit SmartPointer(T value) : ptr(new T(value)), count(new int(1)) {}

    // 拷贝构造函数
    SmartPointer(const SmartPointer<T>& rhs) : ptr(rhs.ptr), count(rhs.count) {
      ++(*count);  //增加引用计数
    }

    // 拷贝赋值运算符
    SmartPointer<T>& operator=(const SmartPointer<T>& rhs) {
        ++(*(rhs.count));
        if (--(*count) == 0) {
            delete ptr;
            delete count;
        }
        ptr = rhs.ptr;
        count = rhs.count;
        return *this;
    }

    // 析构函数
    ~SmartPointer() {
        if (--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    T* get() const { return ptr; }

    int use_count() const { return count ? *count : 0; }
private:
    T* ptr;
    int* count;
};

int main() {
    SmartPointer<int> ptr_a;
    SmartPointer<int> ptr_b(new int(8));
    SmartPointer<int> ptr_c(6);
    SmartPointer<int> ptr_d(ptr_b);
    SmartPointer<int> ptr_e = ptr_a;

    std::cout << &ptr_a << std::endl;
    std::cout << &ptr_b << std::endl;
    std::cout << &ptr_c << std::endl;
    std::cout << &ptr_d << std::endl;
    std::cout << &ptr_e << std::endl;

    std::cout << ptr_a.use_count() << std::endl;
    std::cout << ptr_b.use_count() << std::endl;
    std::cout << ptr_c.use_count() << std::endl;
    std::cout << ptr_d.use_count() << std::endl;
    std::cout << ptr_e.use_count() << std::endl;

    return 0;
}
