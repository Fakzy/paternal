#include <iostream>

class Singleton {
public:
    // Статический метод для доступа к экземпляру синглтона
    static Singleton& getInstance() {
        // Если экземпляр ещё не создан, создать его
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }
    // Публичный метод для выполнения какой-то операции
    void someOperation() {
        std::cout << "Singleton is performing some operation." << std::endl;
    }
    // Удалить конструктор копирования и оператор присваивания
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    // Частный конструктор для предотвращения внешнего создания экземпляра
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }
    // Частный деструктор для предотвращения внешнего удаления
    ~Singleton() {
        std::cout << "Singleton instance destroyed." << std::endl;
    }

    // Частная статическая переменная экземпляра
    static Singleton* instance;
};
// Инициализировать статическую переменную экземпляра значением nullptr
Singleton* Singleton::instance = nullptr;
int main() {
    // Доступ к экземпляру синглтона
    Singleton& singleton = Singleton::getInstance();
    // Использование экземпляра синглтона
    singleton.someOperation();
    // Попытка создать другой экземпляр не сработает
    // Singleton anotherInstance; // Эта строка не будет компилироваться
    return 0;
}
