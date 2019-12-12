#include "TextBox.h"
void TextBox::setTextBox(int size, Color color, bool sel)
{
	textBox.setCharacterSize(size);
	textBox.setFillColor(color);
	isSelected = sel;
	if (sel)
	{
		textBox.setString("_"); //hien thi dau "_" de nguoi choi biet text box dang duoc chon, co the nhap ki tu vao
	}
	else
	{
		textBox.setString("");
	}
}

void TextBox::inputLogic(int charTyped)
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
	textBox.setString(text.str() + "_"); //ki tu cho biet textbox dang duoc nhap
}

void TextBox::deleteLastChar()
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
	textBox.setString(text.str());
}

void TextBox::setFont(Font& font)
{
	textBox.setFont(font);
}

void TextBox::setPosition(Vector2f pos)
{
	textBox.setPosition(pos);
}

void TextBox::setLimit(bool existLimit)
{
	hasLimit = existLimit;
}

void TextBox::setLimit(bool existLimit, int lim)
{
	hasLimit = existLimit;
	limit = lim;
}

string TextBox::getText()
{
	return text.str();
}

void TextBox::draw(RenderWindow& window)
{
	window.draw(textBox);
}

void TextBox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (charTyped == ENTERKEY) //khi nhan enter, limit duoc gan bang 0, tuc la textbox khong cho phep nguoi choi nhap ki tu vao nua
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

int TextBox::getLimit()
{
	return limit;
}