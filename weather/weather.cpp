#include "weather.h"

Weather::Weather(QObject *parent): QObject(parent){
    networkManager = new QNetworkAccessManager(this);
}

Weather::~Weather(){
}

void Weather::onResult(QNetworkReply *reply){ //обработчик ответа
    reply->deleteLater();
    // Если ошибки отсутсвуют - переходим к разбору файла
    if(!reply->error()){
        //создаём объект Json Document, считав в него все данные из ответа
        QString val = reply->readAll();
        //QString val2="{main:[1,2,6]"; проверка на валидность - finished
        Parser parser(val);
        if(parser.parse())
            parser.printExtractedData();
    }
    else {
        qDebug() << reply->errorString() << endl;
    }
}

void Weather::getInfo(const int id){
    QString link = "http://api.openweathermap.org/data/2.5/weather?id=";
    link.push_back(QString::number(id));
    link.push_back("&units=metric&appid=e3930878b6c2753ff62312ef645a09ef");
    qDebug() << link;
    // Подключаем networkManager к обработчику ответа
    connect(networkManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(onResult(QNetworkReply*)));
    // Получаем данные с сайта по определённому url
    QUrl url(link);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkManager->get(request);
}

