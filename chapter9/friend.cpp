#include <iostream>

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


int main(){
    Foo foo1 {100};
    Bar bar1;
    printValue(foo1);
    bar1.processFoo(foo1);
}