#include "config.h"
#include "mqttHelper.h"

#undef min
#undef max
#include <iomanip>
#include <sstream>

mqttHelper::mqttHelper(PubSubClient& mqttClient, const char* prefix) {
    mqttPrefix = std::string(prefix); 
    mqtt = &mqttClient;
}

mqttHelper::mqttHelper() {
    lastMapCRC = -1;
};

boolean mqttHelper::isInitialized() {
    return !(mqtt == nullptr);
}

boolean mqttHelper::publish(std::string& topic, const std::string& value) {
    mqtt->publish((mqttPrefix+topic).c_str(), value.c_str());
    return true;
}

boolean mqttHelper::publish(const char* topic, Map& map) {
    if(lastMapCRC != map.mapCRC) {
        std::string t = std::string(topic);
        std::stringstream ss;
        ss << std::fixed << std::setprecision(3);
        // publish the perimeter points
        for(int i=0; i < map.perimeterPoints.numPoints;i++) {
            Point p = map.perimeterPoints.points[i];
            ss << p.x() << "," << p.y() << " ";
        }
        std::string r = ss.str();
        lastMapCRC = map.mapCRC;
        return publish(t.append("/perimeter"), r);
    } else {
        return false;
    }
}