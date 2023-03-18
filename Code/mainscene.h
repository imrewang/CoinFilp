#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"


namespace Ui {
class MainsceneClass;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *event);

    ChooseLevelScene * chooseScene = NULL;


private:
    Ui::MainsceneClass* ui;
};

#endif // MAINSCENE_H
