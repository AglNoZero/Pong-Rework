#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
#include <sstream>
#define DELETEKEY 8
#define ENTERKEY 13
#define ESCAPEKEY 27

class TextBox
{
private:
	Text textBox; //chuoi hoan chinh cuoi cung cua doan text ma nguoi dung nhap vao
	ostringstream text; //doan text ma nguoi dung nhap vao (co the xoa, sua)
	bool isSelected = false; //tinh trang textbox co dang duoc chon de nhap hay khong
	bool hasLimit = false; //cho biet loai chuoi nhap vao textbox la co gioi han ki tu hay k
	int limit = 0; //neu chuoi co gioi han thi gioi han cua no la int limit
	void inputLogic(int charTyped); //xu li chuoi nhap vao textbox
	void deleteLastChar(); //xoa 1 ki tu cuoi cung cua chuoi dang nhap
public:
	void setTextBox(int size, Color color, bool sel);//input: size(kich co chu cua textbox), color(mau sac cua chu textbox), sel(tinh trang textbox co dang duoc chon hay khong)
	void setFont(Font& font);//input: font(font chu can cai dat), output: textbox da duoc cai dat font chu
	void setPosition(Vector2f pos);//input: pos (vi tri can cai dat cua textbox), output: textbox da duoc cai dat vi tri
	void setLimit(bool existLimit);//input: existLimit(loai textbox), output: textbox duoc cai dat la loai co gioi han hoac khong co gioi han
	void setLimit(bool existLimit, int lim);//input: existLimit(loai textbox), lim(so ki tu gioi han cua textbox)
											//output: textbox da duoc cai dat loai va gioi han so ki tu
	string getText(); ///ouput: lay ra chuoi da duoc nhap vao textbox
	void draw(RenderWindow& window);//input: man hinh ta muon ve textbox vao, output: textbox da duoc ve len man hinh window
	void typedOn(Event input); //xu li su kien  mot ki tu duoc truyen vao textbox, input: input(su kien bat phim), output: chuoi nhap vao textbox duoc xu li
	int getLimit();//output: lay ra so ki tu gioi han cua textbox
};
