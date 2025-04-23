#include <iostream>
#include <memory>
#include <fstream>

void close(FILE* fileptr)
{
    if(!fileptr)
        return;
    
    fclose(fileptr);
    std::cout <<"file has been closed"<<std::endl;
}

int main()
{
    // // 储存c风格数组的 shared_ptr
    // std::shared_ptr<int []> m_IntSharedPtr {new int [10]};
    // for(size_t i = 0; i < 10; ++i){
    //     m_IntSharedPtr[i] = i * i;
    // }
    // for(size_t i = 0; i < 10; ++i){
    //     std::cout << m_IntSharedPtr[i] << std::endl;
    // }

    // // 使用 makeshared 生成c风格动态数组
    // auto m_DoubleSharedPtr = std::make_shared<double []>(10);
    // for(size_t i = 0; i < 10; ++i){
    //     m_DoubleSharedPtr [i] = i * i * i;
    // }
    // for(size_t i = 0; i < 10; ++i){
    //     std::cout << m_DoubleSharedPtr [i] << std::endl;
    // }

    // 自定义 deleter
    FILE* file {fopen("data.txt", "w")};
    std::shared_ptr<FILE> m_fileptr {file, close};
    if(!m_fileptr){
        std::cerr <<"file opening failed"<<std::endl;
    }else{
        std::cout <<"file opened"<<std::endl;
    }
}

