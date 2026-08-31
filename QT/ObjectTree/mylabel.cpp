#include "mylabel.h"
#include<iostream>
MyLabel::MyLabel(QWidget* parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    std::cout << "MyLabel 被销毁" << std::endl;
}
