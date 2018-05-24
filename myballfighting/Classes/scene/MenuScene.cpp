#include "MenuScene.h"
#include "MenuLayer.h"

enum MenuZOrder
{
	MENU_SCENE_BACKGROUND_Z,
	MENU_SCENE_LAYER_Z,
	MENU_SCENE_MENU_Z
};

Scene * MenuScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MenuScene::create();

	scene->addChild(layer);
	
	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}



	auto menu = Menu::create(_gameItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, MENU_SCENE_MENU_Z);

	auto background = Sprite::create("menu_background.png");
	background->setPosition(400, 225);
	this->addChild(background, MENU_SCENE_BACKGROUND_Z);

	_menuLayer = MenuLayer::create();
	this->addChild(_menuLayer, MENU_SCENE_LAYER_Z);


	_eventDispatcher->addCustomEventListener("Game Start", CC_CALLBACK_1(MenuScene::gameStartEvent, this));
	_gameStart = false;

	return true;
}

void MenuScene::menuGameCallback(Ref * pSender)
{
	
}



void MenuScene::gameStartEvent(EventCustom * event)
{
	_gameStart = true;
}

void MenuScene::onExit()
{
	_eventDispatcher->removeCustomEventListeners("Game Start");
	Layer::onExit();
	
}