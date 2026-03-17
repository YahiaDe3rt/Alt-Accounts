#include <Geode/Geode.hpp>
#include <Geode/modify/AccountHelpLayer.hpp>

using namespace geode::prelude;

class $modify(MyAccountHelpLayer, AccountHelpLayer) {
    bool init() {
        if (!AccountHelpLayer::init()) return false;

        auto menu = this->getChildByID("main-menu");
        
        auto sprite = CircleButtonSprite::createWithSpriteFrameName("gj_fbIcon_001.png");
        auto btn = CCMenuItemSpriteExtra::create(
            sprite, this, menu_selector(MyAccountHelpLayer::onCustomButton)
        );
        btn->setID("alt-button");
        menu->addChild(btn);
        menu->updateLayout();

        return true;
    }

    void onCustomButton(CCObject* sender) {
        FLAlertLayer::create(
            "Alt Switcher",
            "This is where your account logic will go!",
            "OK"
        )->show();
    }
};
																																																																												
