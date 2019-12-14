#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
#include <sstream>
#define DELETEKEY 8
#define ENTERKEY 13
#define ESCAPEKEY 27

class DynamicText
{
private:
	Text DynamicText; //chuoi hoan chinh cuoi cung cua doan text ma nguoi dung nhap vao
	ostringstream text; //doan text ma nguoi dung nhap vao (co the xoa, sua)
	bool isSelected = false; //tinh trang DynamicText co dang duoc chon de nhap hay khong
	bool hasLimit = false; //cho biet loai chuoi nhap vao DynamicText la co gioi han ki tu hay k
	int limit = 0; //neu chuoi co gioi han thi gioi han cua no la int limit
	void inputLogic(int charTyped); //xu li chuoi nhap vao DynamicText
	void deleteLastChar(); //xoa 1 ki tu cuoi cung cua chuoi dang nhap
public:
	void setDynamicText(int size, Color color, bool sel);//input: size(kich co chu cua DynamicText), color(mau sac cua chu DynamicText), sel(tinh trang DynamicText co dang duoc chon hay khong)
	void setFont(Font& font);//input: font(font chu can cai dat), output: DynamicText da duoc cai dat font chu
	void setPosition(Vector2f pos);//input: pos (vi tri can cai dat cua DynamicText), output: DynamicText da duoc cai dat vi tri
	void setLimit(bool existLimit);//input: existLimit(loai DynamicText), output: DynamicText duoc cai dat la loai co gioi han hoac khong co gioi han
	void setLimit(bool existLimit, int lim);//input: existLimit(loai DynamicText), lim(so ki tu gioi han cua DynamicText)
											//output: DynamicText da duoc cai dat loai va gioi han so ki tu
	string getText(); ///ouput: lay ra chuoi da duoc nhap vao DynamicText
	void draw(RenderWindow& window);//input: man hinh ta muon ve DynamicText vao, output: DynamicText da duoc ve len man hinh window
	void typedOn(Event input); //xu li su kien  mot ki tu duoc truyen vao DynamicText, input: input(su kien bat phim), output: chuoi nhap vao DynamicText duoc xu li
	int getLimit();//output: lay ra so ki tu gioi han cua DynamicText
};
