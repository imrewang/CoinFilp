﻿#ifndef MYCOIN_H
#define MYCOIN_H

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QPushButton>
#include <QDebug>
#include <QTimer>


class MyCoin : public QPushButton
{
    Q_OBJECT
public:

    //参数 代表 传入的金币路径 还是银币路径
    MyCoin(QString btnImg);

    //金币的属性
    int posX; //x坐标位置
    int posY; //y坐标位置
    bool flag; //正反标示

    //改变标志的方法
    void changeFlag();
    QTimer * timer1; //正面翻反面的定时器
    QTimer * timer2; //反面翻正面的定时器
    int min = 1;
    int max = 8;

    //执行动画 标志
    bool isAnimation = false;

    //重写 按下
    void mousePressEvent(QMouseEvent *e);


    bool isWin = false; //是否胜利


signals:

public slots:
};

#endif // MYCOIN_H
