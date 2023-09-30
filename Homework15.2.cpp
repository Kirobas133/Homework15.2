// Homework15.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <future>

template<typename T>
int some_func(T data) {
    return (data + 10);
}

template <typename It, typename T = int, size_t size = 3>
It foreachpar(It begin, It end, int(*some_func)(T)) {
    auto sizein = std::distance(begin, end);
    if (sizein <= size) {
        for (auto iter = begin; iter != end; iter++) {
           *iter = some_func(*iter);
        }
        return begin;
    }
    auto mid = begin;
    std::advance(mid, sizein / 2);
    auto f_res = std::async(foreachpar<It>, begin, mid, some_func);
    auto l_res = foreachpar(mid, end, some_func);
    return begin;
}

int main()
{
    std::vector<int> vec = { 1, 10, 59,/**/ 23, 57, 38,/**/ 785, 12, 35,/**/ 54, 86, 18,/**/
        867, 233, 8685,/**/ 234, 56, 3249};

    for (auto it : vec) {
        std::cout << it << "\t";
    
    }
    std::cout << std::endl;
    std::cout << "Hello World!\n";
    foreachpar(vec.begin(), vec.end(), some_func);

    for (auto it : vec) {
        std::cout << it << "\t";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
