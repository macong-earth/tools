#include <iostream>

template<typename T>
class FinalClass {

    public:
        FinalClass(T clean);
        ~FinalClass();
    private:
        T m_clean;
};

template<typename T>
FinalClass<T>::FinalClass(T clean) : m_clean(clean)
{
}

template<typename T>
FinalClass<T>::~FinalClass()
{
    m_clean();
}

template<typename T>
FinalClass<T> createFinal(T clean)
{
    return FinalClass<T>(clean);
}


int main(int argc, char const* argv[])
{
    int i = 10;
    auto finalObj = createFinal([&](){
            std::cout << i << std::endl;
            });

    return 0;
}
