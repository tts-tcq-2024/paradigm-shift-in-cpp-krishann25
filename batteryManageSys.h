
#ifndef BATTERYMANAGESYS_H
#define BATTERYMANAGESYS_H

#include <string>

enum class BreachStatus {
    NO_BREACH,
    LOW_BREACH,
    HIGH_BREACH
};

enum class WarningStatus {
    NO_WARNING,
    LOW_WARNING,
    HIGH_WARNING
};

struct ParameterRange {
    float lowBreach;
    float lowWarning;
    float highWarning;
    float highBreach;
};

// Function prototypes for checking breach and warning status
BreachStatus getBreachStatus(float value, const ParameterRange& range);
WarningStatus getWarningStatus(float value, const ParameterRange& range);

// Function prototype for translating status to a message
std::string statusToMessageTranslation(const std::string& parameter, BreachStatus breachStatus, WarningStatus warningStatus);

// Function prototypes for checking individual battery parameters
bool checkTemperature(float temperature, BreachStatus& breachStatus, WarningStatus& warningStatus);
bool checkSoc(float soc, BreachStatus& breachStatus, WarningStatus& warningStatus);
bool checkChargeRate(float chargeRate, BreachStatus& breachStatus, WarningStatus& warningStatus);

// Function prototype for checking overall battery health
bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERYMANAGESYS_H
