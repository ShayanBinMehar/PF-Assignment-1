#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime; 
    char encoding[50];
} ContentMetadata;

typedef struct {
    double* engagementScores; 
} UserProfile;

typedef struct {
    ContentMetadata** contentMatrix; 
    UserProfile* userProfiles; 
    double** engagementMatrix; 
    double** deviceMatrix; 
    int numUsers;
    int numCategories;
    int numDevices;
} StreamingPlatform;

StreamingPlatform* createPlatform(int numUsers, int numCategories, int numDevices) {
    StreamingPlatform* platform = (StreamingPlatform*)malloc(sizeof(StreamingPlatform));
    platform->numUsers = numUsers;
    platform->numCategories = numCategories;
    platform->numDevices = numDevices;

    platform->userProfiles = (UserProfile*)malloc(numUsers * sizeof(UserProfile));
    for (int i = 0; i < numUsers; i++) {
        platform->userProfiles[i].engagementScores = (double*)calloc(numCategories, sizeof(double));
    }

    platform->engagementMatrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        platform->engagementMatrix[i] = (double*)calloc(numCategories, sizeof(double));
    }

    platform->deviceMatrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        platform->deviceMatrix[i] = (double*)calloc(numDevices, sizeof(double));
    }

    platform->contentMatrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
    for (int i = 0; i < numCategories; i++) {
        platform->contentMatrix[i] = (ContentMetadata*)malloc(10 * sizeof(ContentMetadata)); 
    }

    return platform;
}

void freePlatform(StreamingPlatform* platform) {
    for (int i = 0; i < platform->numUsers; i++) {
        free(platform->userProfiles[i].engagementScores);
        free(platform->engagementMatrix[i]);
        free(platform->deviceMatrix[i]);
    }
    free(platform->userProfiles);
    free(platform->engagementMatrix);
    free(platform->deviceMatrix);

    for (int i = 0; i < platform->numCategories; i++) {
        free(platform->contentMatrix[i]);
    }
    free(platform->contentMatrix);
    free(platform);
}

int main() {
    int numUsers = 100;
    int numCategories = 5;
    int numDevices = 3;

    StreamingPlatform* platform = createPlatform(numUsers, numCategories, numDevices);

    platform->engagementMatrix[0][1] = 120.5; 

    freePlatform(platform);
    return 0;
}
