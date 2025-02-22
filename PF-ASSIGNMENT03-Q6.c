#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    struct WeatherForecast* weather;
} Crop;

typedef struct {
    float latitude;
    float longitude;
    float soilHealth;
    float moistureLevel;
    Crop* crops;
    int cropCount;
    struct Equipment* equipment;
    int equipmentCount;
    struct Sensor* sensors;
    int sensorCount;
} Field;

typedef struct {
    char name[50];
    float fuelLevel;
    char operationalStatus[50];
    char activitySchedule[100];
} Equipment;

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    float nutrientLevel;
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct {
    Field* fields;
    int fieldCount;
} RegionalHub;

typedef struct {
    RegionalHub* hubs;
    int hubCount;
} CentralAnalyticsServer;

void initializeField(Field* field, float latitude, float longitude) {
    field->latitude = latitude;
    field->longitude = longitude;
    field->soilHealth = 0.0;
    field->moistureLevel = 0.0;
    field->crops = NULL;
    field->cropCount = 0;
    field->equipment = NULL;
    field->equipmentCount = 0;
    field->sensors = NULL;
    field->sensorCount = 0;
}

void addCrop(Field* field, const char* cropType, const char* growthStage, float expectedYield) {
    field->crops = realloc(field->crops, (field->cropCount + 1) * sizeof(Crop));
    strcpy(field->crops[field->cropCount].cropType, cropType);
    strcpy(field->crops[field->cropCount].growthStage, growthStage);
    field->crops[field->cropCount].expectedYield = expectedYield;
    field->crops[field->cropCount].weather = NULL; 
    field->cropCount++;
}

void freeField(Field* field) {
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

int main() {
    Field myField;
    initializeField(&myField, 34.0522, -118.2437);
    addCrop(&myField, "Corn", "Vegetative", 2000.0);

    printf("Field at (%f, %f) has %d crops.\n", myField.latitude, myField.longitude, myField.cropCount);
    
    freeField(&myField);
    
    return 0;
}
