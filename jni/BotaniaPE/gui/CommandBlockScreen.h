#pragma once

#include <mcpe/client/gui/Screen.h>
#include <mcpe/client/gui/TButton.h>
#include <mcpe/client/gui/TextBox.h>
#include <mcpe/client/gui/Label.h>
#include <PocketRed/tileentity/CommandBlockTileEntity.h>

class CommandBlockScreen: public Screen {
public:
	//CommandBlockTileEntity* commandblock;
	
	Touch::TButton* ok;
	Touch::TButton* cancel;
	Label* title;
	Label* commandlabel;
	TextBox* textbox;
	Label* nearestplayerlabel;
	Label* randomplayerlabel;
	Label* allplayerslabel;
	Label* allentitieslabel;
	Label* outputlabel;
	TextBox* output;
	Touch::TButton* hideoutput;
	
public:
	CommandBlockScreen() /*CommandBlockTileEntity* cb)*/: Screen() {
		//commandblock = cb;
		
		ok = NULL;
		cancel = NULL;
		title = NULL;
		commandlabel = NULL;
		textbox = NULL;
		nearestplayerlabel = NULL;
		randomplayerlabel = NULL;
		allplayerslabel = NULL;
		allentitieslabel = NULL;
		outputlabel = NULL;
		output = NULL;
		hideoutput = NULL;
	}
	
	~CommandBlockScreen() {
		delete ok;
		delete cancel;
		delete title;
		delete commandlabel;
		delete textbox;
		delete nearestplayerlabel;
		delete randomplayerlabel;
		delete allplayerslabel;
		delete allentitieslabel;
		delete outputlabel;
		delete output;
		delete hideoutput;
	}
	
	void init() {
		ok = new Touch::TButton(0, "gui.done", NULL, false, 0x7FFFFFFF);
		cancel = new Touch::TButton(1, "gui.cancel", NULL, false, 0x7FFFFFFF);
		title = new Label(*mc, "advMode.setCommand", Color::WHITE, 0, 0, 0, true);
		commandlabel = new Label(*mc, "advMode.command", Color::WHITE, 0, 0, 0, true);
		textbox = new TextBox(*mc, "advMode.command", 5, TextBox::extendedASCII, NULL, &Screen::onTextBoxUpdated, 0);
		nearestplayerlabel = new Label(*mc, "advMode.nearestPlayer", Color::WHITE, 0, 0, 0, true);
		randomplayerlabel = new Label(*mc, "advMode.randomPlayer", Color::WHITE, 0, 0, 0, true);
		allplayerslabel = new Label(*mc, "advMode.allPlayers", Color::WHITE, 0, 0, 0, true);
		allentitieslabel = new Label(*mc, "advMode.allEntities", Color::WHITE, 0, 0, 0, true);
		outputlabel = new Label(*mc, "advMode.previousOutput", Color::WHITE, 0, 0, 0, true);
		output = new TextBox(*mc, "advMode.previousOutput", 5, TextBox::extendedASCII, NULL, &Screen::onTextBoxUpdated, 0);
		hideoutput = new Touch::TButton(2, "O", NULL, true, 0x7FFFFFFF);
		title->centered = true;
		//textbox->setText(commandblock->command);
		output->setText("-"); //commandblock->output);
		//hideoutput->toggled = commandblock->hideoutput;
		
		ok->init(mc);
		cancel->init(mc);
		hideoutput->init(mc);
		
		buttonList.push_back(ok);
		buttonList.push_back(cancel);
		elementList2.push_back(title);
		elementList2.push_back(commandlabel);
		elementList2.push_back(textbox);
		elementList2.push_back(nearestplayerlabel);
		elementList2.push_back(randomplayerlabel);
		elementList2.push_back(allplayerslabel);
		elementList2.push_back(allentitieslabel);
		elementList2.push_back(outputlabel);
		buttonList.push_back(hideoutput);
	}
	
	bool renderGameBehind() {
		return true;
	}
	
	void render(int ur, int an, float fagit) {
		Screen::render(ur, an, fagit);
		
		if(!textbox->suppressOtherGUI()) output->render(mc, 0, 0);
	}
	
	void setupPositions() {
		ok->width = width / 5 * 2;
		ok->height = height / 6;
		ok->xPosition = width / 2 - ok->width - 5;
		ok->yPosition = height - ok->height - 5;
		
		cancel->width = width / 5 * 2;
		cancel->height = height / 6;
		cancel->xPosition = width / 2 + 5;
		cancel->yPosition = height - cancel->height - 5;
		
		title->xPosition = width / 2;
		title->yPosition = 5;
		
		commandlabel->xPosition = 20;
		commandlabel->yPosition = 20;
		
		textbox->width = width - 40;
		textbox->xPosition = 20;
		textbox->yPosition = commandlabel->yPosition + commandlabel->height / 2;
		
		nearestplayerlabel->xPosition = textbox->xPosition;
		nearestplayerlabel->yPosition = textbox->yPosition + textbox->height + 5;
		
		randomplayerlabel->xPosition = textbox->xPosition;
		randomplayerlabel->yPosition = nearestplayerlabel->yPosition + nearestplayerlabel->height / 2;
		
		allplayerslabel->xPosition = textbox->xPosition;
		allplayerslabel->yPosition = randomplayerlabel->yPosition + randomplayerlabel->height / 2;
		
		allentitieslabel->xPosition = textbox->xPosition;
		allentitieslabel->yPosition = allplayerslabel->yPosition + allplayerslabel->height / 2;
		
		outputlabel->xPosition = textbox->xPosition;
		outputlabel->yPosition = allentitieslabel->yPosition + allentitieslabel->height + 2;
		
		output->width = width - 40 - output->height - 2;
		output->xPosition = 20;
		output->yPosition = outputlabel->yPosition + outputlabel->height / 2;
		
		hideoutput->height = output->height;
		hideoutput->width = output->height,
		hideoutput->xPosition = output->xPosition + output->width + 2;
		hideoutput->yPosition = output->yPosition;
	}
	
	bool handleBackEvent(bool b) {
		if(!b) {
			if(textbox->suppressOtherGUI()) {
				if (textbox->backPressed(mc, false))
					return true;
			}
			mc->setScreen(NULL);
		}
		return true;
	}
	
	void buttonClicked(Button* button) {
		switch(button->id) {
			case 0:
				mc->setScreen(NULL);
				//commandblock->command = textbox->getText();
				break;
			case 1:
				mc->setScreen(NULL);
				break;
			case 2:
				hideoutput->text = hideoutput->text == "O"? "X" : "O";
				//commandblock->hideoutput = hideoutput->toggled;
				break;
		}
	}
};
