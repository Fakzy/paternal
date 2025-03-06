#include <iostream>
#include <string>

// Абстрактный виджет
class Widget {
public:
    virtual void draw() = 0;
};

// Абстрактная фабрика
class WidgetFactory {
public:
    virtual Widget* createButton() = 0;
    virtual Widget* createCheckbox() = 0;
};

// Конкретная кнопка
class Button : public Widget {
public:
    void draw() override {
        std::cout << "Button" << std::endl;
    }
};

// Конкретная чекбокс
class Checkbox : public Widget {
public:
    void draw() override {
        std::cout << "Checkbox" << std::endl;
    }
};

// Конкретная фабрика виджетов
class WindowsWidgetFactory : public WidgetFactory {
public:
    Widget* createButton() override {
        return new Button();
    }
    Widget* createCheckbox() override {
        return new Checkbox();
    }
};

int main() {
    WidgetFactory* factory = new WindowsWidgetFactory();
    Widget* button = factory->createButton();
    Widget* checkbox = factory->createCheckbox();
    button->draw();
    checkbox->draw();
    delete button;
    delete checkbox;
    delete factory;
    return 0;
}
