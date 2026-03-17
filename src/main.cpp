#include <Geode/Geode.hpp>
#include <Geode/modify/AccountLayer.hpp>

using namespace geode::prelude;

class $modify(AccountLayer) {
    bool init() {
	        if (!AccountLayer::init()) return false;

			        // Find the main menu container inside the popup
					        auto menu = this->getChildByID("main-menu");
							        
									        if (menu) {
											            // Create the sprite for your button (using a standard GD icon)
														            auto spr = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
																	            
																				            // Create the button and tell it to run 'onAltAccount' when tapped
																							            auto btn = CCMenuItemSpriteExtra::create(
																										                spr, this, menu_selector(AccountLayer::onAltAccount)
																														            );
																																	            
																																				            // Give the button an ID so other mods can see it
																																							            btn->setID("alt-account-button");

																																										            // Add it to the menu
																																													            menu->addChild(btn);
																																																            
																																																			            // Refresh the layout so the buttons don't overlap
																																																						            menu->updateLayout();
																																																									        }

																																																											        return true;
																																																													    }

																																																														    // This is what happens when you tap the button
																																																															    void onAltAccount(CCObject* sender) {
																																																																        FLAlertLayer::create(
																																																																		            "Alt Switcher", 
																																																																					            "This is where your account logic will go!", 
																																																																								            "OK"
																																																																											        )->show();
																																																																													    }
																																																																														};
																																																																														