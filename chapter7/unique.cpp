#include <iostream>
#include <memory>

void my_deleter(int* p)
{
    delete p;
    std::cout << "resource has been free!"<<std::endl; 
}

int main()
{   
    // 自定义删除器的 unique_ptr
    std::unique_ptr<int, decltype(&my_deleter)> SmartIntPtr(new int{}, my_deleter);
}

