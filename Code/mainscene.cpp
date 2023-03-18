﻿#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound>  //多媒体模块下的 音效头文件
#include<QTime>
#include<QCoreApplication>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainsceneClass)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QPixmap("res/Coin0001.png"));
    

    //设置窗口标题
    this->setWindowTitle("翻金币主场景");


    //准备开始按钮的音效
    QSound * startSound = new QSound("res/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton * startBtn = new MyPushButton("res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
        this->setGeometry(chooseScene->geometry());
        
        this->show(); //重新显示主场景
        QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        chooseScene->hide(); //将选择关卡场景隐藏掉
    });


    connect(startBtn,&MyPushButton::clicked,[=](){
        //播放开始音效资源
        startSound->play();
        //做弹起特效
        //startBtn->zoom1(); //向下跳跃
        //startBtn->zoom2(); //向上跳跃     
        startBtn->zoom();
        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            
            //显示选择关卡场景
            chooseScene->show();
            QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
            while (QTime::currentTime() < dieTime) {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }
            //自身隐藏
            this->hide();
        });
    });

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("res/PlayLevelSceneBg.png");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    //加载标题
    pix.load("res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);
}


MainScene::~MainScene()
{
    delete ui;
}
