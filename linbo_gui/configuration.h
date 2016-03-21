#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <qstring.h>
#include <qstringlist.h>

#include <vector>
#include <fstream>
#include <istream>

#include "image_description.h"

using namespace  std;

class Configuration
{
private:
    ifstream input;
    void read_qstring(QString& tmp);
    void read_bool(bool& tmp);
    bool read_pair(QString& key, QString& value);
    bool toBool(const QString& value);
    void read_os( os_item& tmp_os, image_item& tmp_image );
    void read_partition( diskpartition& p );
    void read_globals();
    void init(const char name[]);

public:
    globals config;
    vector<os_item> elements;
    vector<diskpartition> partitions;

    Configuration(const char name[] );
    Configuration();
    ~Configuration();

};

#endif // CONFIGURATION_H
