#ifndef MQTTHELPER_H
#define MQTTHELPER_H

#include "PubSubClient.h"
#include "map.h"

#pragma push_macro("min")
#undef min

#pragma push_macro("max")
#undef max

#include <string>

class mqttHelper {
    protected:
        PubSubClient* mqtt;
        std::string mqttPrefix;
        boolean publish(std::string& topic, const std::string& value);
        long lastMapCRC;
    public:
        mqttHelper();
        mqttHelper(PubSubClient& mqttClient, const char* prefix);
        boolean publish(const char* topic, Map& map);
        boolean isInitialized();
};

#pragma pop_macro("min")
#pragma pop_macro("max")

#endif