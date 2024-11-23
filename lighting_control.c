#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMBIENT_THRESHOLD 30.0
#define PROXIMITY_THRESHOLD 10.0

void log_data(double ambient_light, double proximity, int headlights, int high_beams) {
    FILE *logfile = fopen("lighting_log.txt", "a");
    if (logfile) {
        fprintf(logfile, "Ambient: %.2f lux | Proximity: %.2f meters | Headlights: %s | High Beams: %s\n",
                ambient_light, proximity,
                headlights ? "ON" : "OFF",
                high_beams ? "ON" : "OFF");
        fclose(logfile);
    }
}

void control_lighting(double ambient_light, double proximity) {
    int headlights = (ambient_light < AMBIENT_THRESHOLD);
    int high_beams = (headlights && (proximity > PROXIMITY_THRESHOLD));

    printf("Ambient Light: %.2f lux | Proximity: %.2f meters | Headlights: %s | High Beams: %s\n",
           ambient_light, proximity,
           headlights ? "ON" : "OFF",
           high_beams ? "ON" : "OFF");

    log_data(ambient_light, proximity, headlights, high_beams);
}

int main() {
    srand(time(0)); // Seed random number generator

    for (int i = 0; i < 10; i++) {
        double ambient_light = (rand() % 100);
        double proximity = (rand() % 50);

        control_lighting(ambient_light, proximity);
    }
    return 0;
}
