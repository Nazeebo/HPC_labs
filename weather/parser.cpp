#include "parser.h"

Parser::Parser(QString doc){
    _doc = doc;
}

bool Parser::parse(){
    QJsonDocument document = QJsonDocument::fromJson(_doc.toUtf8());

    if(document.isEmpty())
        return false;

    // Забираем из документа корневой объект
    QJsonObject root = document.object();


    QJsonObject tmp = root.value("main").toObject();
    temp = tmp.value("temp").toDouble();
    temp_min = tmp.value("temp_min").toDouble();
    temp_max = tmp.value("temp_max").toDouble();
    pressure = tmp.value("pressure").toDouble();
    humidity = tmp.value("humidity").toDouble();

    tmp = root.value("wind").toObject();
    wind_speed = tmp.value("speed").toDouble();
    city = root.value("name").toString();

    tmp = root.value("sys").toObject();
    country = tmp.value("country").toString();

    QJsonArray weather = root["weather"].toArray();

    foreach (const QJsonValue &value, weather){
        QJsonObject obj = value.toObject();
        conditions.append(obj["description"].toString());
    }

    return true;
}

void Parser::printExtractedData(){
    QSettings settings("University","Weather");
    QFile file(settings.value("path/output").toString()); //qsettings
    if(file.open(QFile::WriteOnly | QFile::Append)){
        QTextStream stream(&file);
        QString time = QDateTime::currentDateTime().toString().toUtf8();
        stream << time << " " << "Weather in " << city << " " << country << ":" << endl;
        stream << "Current temperature: " << temp << endl;
        stream << "Maximum temperature at the moment: " << temp_max << endl;
        stream << "Minimum temperature at the moment: " << temp_min << endl;
        stream << "Humidity: " << humidity << endl;
        stream << "Pressure: " << pressure << endl;
        stream << "Speed of wind: " << wind_speed << endl;
        stream << "Weather conditions: ";
        foreach(const QString &value, conditions){
            stream << value;
            if(value == conditions.back()){
                stream << "." << endl;
            }
            else stream << ", ";
        }
        stream << endl;
        file.close();
        if(stream.status() != QTextStream::Ok)
            qDebug() << "Ошибка записи файла";
    }
}
