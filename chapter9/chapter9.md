# 精通类和对象

## 友元

c++ 中允许某个类将其他类、其它类的成员函数或者非成员函数声明为友元`friend`，友元可以访问类的`protect`、`private` 数据成员和方法。
```c++
class Foo;
class Bar{
public:
    Bar() = default;
    void processFoo(const Foo& foo) {};
};

class Foo {
private:
    int value;

public:
    Foo(int v) : value(v) {}

    friend void printValue(const Foo& foo);
    friend void Bar::processFoo(const Foo& foo);
};

void printValue(const Foo& foo) {
    std::cout << "Value: " << foo.value << std::endl;
}
```

## 对象中的动态内存分配