#include "DynamicText.h"
void DynamicText::setDynamicText(int size, Color color, bool sel)
{
	DynamicText.setCharacterSize(size);
	DynamicText.setFillColor(color);
	isSelected = sel;
	if (sel)
	{
		DynamicText.setString("_"); //hien thi dau "_" de nguoi choi biet text box dang duoc chon, co the nhap ki tu vao
	}
	else
	{
		DynamicText.setString("");
	}
}

void DynamicText::inputLogic(int charTyped)
{
	if (charTyped != DELETEKEY && charTyped != ENTERKEY && charTyped != ESCAPEKEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETEKEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	DynamicText.setString(text.str() + "_"); //ki tu cho biet DynamicText dang duoc nhap
}

void DynamicText::deleteLastChar()
{
	string t = text.str();
	string newT = "";
	//copy chuoi t vao chuoi newT tru phan tu cuoi cung (phan tu can duoc xoa)
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	DynamicText.setString(text.str());
}

void DynamicText::setFont(Font& font)
{
	DynamicText.setFont(font);
}

void DynamicText::setPosition(Vector2f pos)
{
	DynamicText.setPosition(pos);
}

void DynamicText::setLimit(bool existLimit)
{
	hasLimit = existLimit;
}

void DynamicText::setLimit(bool existLimit, int lim)
{
	hasLimit = existLimit;
	limit = lim;
}

string DynamicText::getText()
{
	return text.str();
}

void DynamicText::draw(RenderWindow& window)
{
	window.draw(DynamicText);
}

void DynamicText::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (charTyped == ENTERKEY) //khi nhan enter, limit duoc gan bang 0, tuc la DynamicText khong cho phep nguoi choi nhap ki tu vao nua
			{
				limit = 0;
			}
			else
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETEKEY)
					{
						deleteLastChar();
					}

				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
}

int DynamicText::getLimit()
{
	return limit;
}