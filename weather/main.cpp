#include <QCoreApplication>
#include "weather.cpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     QSettings settings("University","Weather");
     settings.setValue("path/input","D:/University/Sharamet/weather/id");
     settings.setValue("path/output","D:/University/Sharamet/weather/output.txt");

     ifstream in(settings.value("path/input").toString().toStdString());
     ofstream cleaning(settings.value("path/output").toString().toStdString());
     Weather weather;
     int id;
     for(in >> id; !in.eof(); in >> id)
        weather.getInfo(id);

    return a.exec();
}
