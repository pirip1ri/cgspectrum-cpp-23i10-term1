#include <string>
#include <iostream>

using namespace std;

class Button
{
protected:
	string m_label;
public:
	Button(string label)
		: m_label(label)
	{

	}
	virtual void Draw() = 0;
};

class CheckBox 
{
public:
	virtual void Draw() = 0;
};

class GUIFactory
{
public:
	virtual Button* CreateButton(string label) = 0;
	virtual CheckBox* CreateCheckBox() = 0;
};

//Purely abstract above, now you must put real elements in and have these real elements inherit from the classes above

//XBOX
#ifdef XBOX

class XboxButton : public Button
{
public:
	XboxButton(string label)
		: Button(label)
	{
	}

	virtual void Draw() override 
	{
		cout << "A: " << m_label << endl;
	}
};

class XboxCheckBox : public CheckBox
{
	virtual void Draw() override
	{
		cout << "Xbox CheckBox" << endl;
	}
};

class XboxFactory : public GUIFactory
{
public:
	virtual Button* CreateButton(string label) override
	{
		return new XboxButton(label);
	}

	virtual CheckBox* CreateCheckBox() override
	{
		return new XboxCheckBox();
	}
};

//PlayStation
#else
class PlayStationButton : public Button
{
public:
	PlayStationButton(string label)
		: Button(label)
	{
	}

	virtual void Draw() override
	{
		cout << "X: " << m_label << endl;
	}
};

class PlayStationCheckBox : public CheckBox
{
	virtual void Draw() override
	{
		cout << "PlayStation CheckBox" << endl;
	}
};

class PlayStationFactory : public GUIFactory
{
public:
	virtual Button* CreateButton(string label) override
	{
		return new PlayStationButton(label);
	}

	virtual CheckBox* CreateCheckBox() override
	{
		return new PlayStationCheckBox();
	}
};
#endif

GUIFactory* GetGUIFactory()
{
#ifdef XBOX
	return new XboxFactory();
#else
	return new PlayStationFactory();
#endif
}

int main()
{
	GUIFactory* pFactory = GetGUIFactory();
	Button* pButton = pFactory->CreateButton("Main Menu");
	CheckBox* pCheckBox = pFactory->CreateCheckBox();

	pButton->Draw();
	pCheckBox->Draw();

	delete pButton;
	pButton = nullptr;

	delete pFactory;
	pFactory = nullptr;
}