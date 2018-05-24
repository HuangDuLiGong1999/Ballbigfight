#pragma execution_character_set("utf-8")
#include "MenuLayer.h"
#include "SceneManager.h"

enum MenuTag
{
	TAG_MENU_1,
	TAG_MAX
};

enum MenuZOrder
{
	MENU_BACKGROUND_Z,
	MENU_SPRITE_Z,
	MENU_MENU_Z,
	MENU_LABEL_Z,
	MENU_TEXTFIELD_Z,
	MENU_DROPDOWNLIST_Z,
	MENU_LAYER_Z,
	MENU_PROMPT_Z,
	MENU_MAX_Z
};

MenuLayer::MenuLayer()
{

}

MenuLayer::~MenuLayer()
{

	_eventDispatcher->removeCustomEventListeners("GameStart");
}

bool MenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}


	auto settingItem = MenuItemImage::create(
		"menu_setting_btn.png",
		"menu_setting_btn.png",
		CC_CALLBACK_1(MenuLayer::menuSettingCallback, this));
	settingItem->setPosition(757, 410);


	auto strategyItem = MenuItemImage::create(
		"menu_strategy_btn0.png",
		"menu_strategy_btn1.png",
		CC_CALLBACK_1(MenuLayer::menuStrategyCallback, this));
	strategyItem->setPosition(757, 44);

	auto menu1 = Menu::create(settingItem,strategyItem, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setVisible(true);
	this->addChild(menu1, MENU_MENU_Z, TAG_MENU_1);
	_menuList.pushBack(menu1);


	auto rankItem = MenuItemImage::create(
		"menu_rank_btn0.png",
		"menu_rank_btn1.png",
		CC_CALLBACK_1(MenuLayer::menuRankCallback, this));
	rankItem->setPosition(400, 100);

	auto menu2 = Menu::create(rankItem, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, MENU_MENU_Z);
	_menuList.pushBack(menu2);




	auto startItem = MenuItemImage::create(
		"menu_start_btn.png",
		"menu_start_btn.png",
		CC_CALLBACK_1(MenuLayer::menuStartCallback, this));
	startItem->setPosition(400,225);






	auto menu3 = Menu::create(startItem,
		NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, MENU_MENU_Z);
	_menuList.pushBack(menu3);


	/*Ìí¼Ó´óÌü±³¾°*/
	auto background = Sprite::create("menu_background.png");
	background->setPosition(400, 225);
	this->addChild(background, MENU_BACKGROUND_Z);

	

	/*ÊÂ¼þ¼àÌýÆ÷*/
	_eventDispatcher->addCustomEventListener("GameStart", CC_CALLBACK_1(MenuLayer::gameStartEvent, this));

	return true;
}


void MenuLayer::menuExtendCallback(Ref * pSender)
{
	if (_extendItem1->isVisible())
	{
		_extendItem1->setVisible(false);
		_extendItem2->setVisible(true);
		auto menu = this->getChildByTag(TAG_MENU_1);
		menu->setVisible(true);
	}
	else
	{
		_extendItem1->setVisible(true);
		_extendItem2->setVisible(false);
		auto menu = this->getChildByTag(TAG_MENU_1);
		menu->setVisible(false);
	}
}


void MenuLayer::menuSettingCallback(Ref * pSender)
{

}



void MenuLayer::menuStrategyCallback(Ref * pSender)
{

}


void MenuLayer::menuRankCallback(Ref * pSender)
{

}


void MenuLayer::menuStartCallback(Ref * pSender)
{

	for (auto menu : _menuList)
	{
		menu->setEnabled(false);
	}

	_eventDispatcher->dispatchCustomEvent("GameStart");


}


void MenuLayer::setMenuEnable(Ref * pSender)
{
	auto item = dynamic_cast<MenuItemImage *>(pSender);
	item->setEnabled(true);
}




void MenuLayer::menuServerCallback(int index)
{
	log("%d", index);
}


void MenuLayer::gameStartEvent(EventCustom * event)
{
	SceneManager::getInstance()->changeScene(SceneManager::en_GameScene);
}

void MenuLayer::onExit()
{
	this->unscheduleAllCallbacks();
	Layer::onExit();
}

void MenuLayer::gameNameEvent(Ref * pSender, TextField::EventType type)
{

}