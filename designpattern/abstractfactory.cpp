#include <iostream>
#include <random>

class Button {
public:
	virtual void paint() = 0;
};

class WinButton :public Button {
public:
	virtual void paint() override {
		std::cout << "WinButton" << std::endl;
	}
};

class OSXButton :public Button {
public:
	virtual void paint() override {
		std::cout << "OSXButton" << std::endl;
	}
};

class AbstractFactoryExample {
public:
	class GUIFactory {
	public:
		virtual Button* createButton() = 0;
	};

	class WinFactory :public GUIFactory {
	public:
		virtual Button* createButton() override {
			return new WinButton();
		}
	};

	class OSXFactory :public GUIFactory {
	public:
		virtual Button* createButton() override {
			return new OSXButton();
		}
	};
	
	static GUIFactory* factory(int i) {
		switch (i)
		{
		case 1:
			return new OSXFactory();
		case 0:
			return new WinFactory();
		default:
			return nullptr;
		}
	}


};

int main(void) {
	int i = 0;
	std::cin >> i;
	AbstractFactoryExample::GUIFactory *factory = AbstractFactoryExample::factory(i);
	if (factory)
	{
		Button *button = factory->createButton();
		button->paint();
	}
}