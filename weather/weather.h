#ifndef WEATHER_H
#define WEATHER_H
#include "parser.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>

class Weather: public QObject{
    Q_OBJECT
public:
    explicit Weather(QObject *parent = 0);
    ~Weather();
    void getInfo(const int id);

private:
    QNetworkAccessManager *networkManager;

private slots:
    void onResult(QNetworkReply *reply);
    //void errorCatcher(QNetworkReply::NetworkError *err);
};


#endif // WEATHER_H
