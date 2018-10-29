#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QSettings>

class Parser{
public:
    Parser(QString doc);
    bool parse();
    void printExtractedData();
private:
    QString _doc, city, country;
    double temp, temp_max, temp_min, wind_speed, humidity, pressure;
    QStringList conditions;
};

#endif // PARSER_H
