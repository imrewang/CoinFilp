#ifndef DATACONFIG_H
#define DATACONFIG_H

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = 0);

public:

    QMap<int, QVector< QVector<int> > >mData;



signals:

public slots:
};

#endif // DATACONFIG_H
