#include <math.h>

double calculate_mean(double values[], int count) {
 double sum = 0;
	 for (int i = 0; i < count; i++) {
		sum += values[i];
				    }
     return sum / count;
}

double calculate_std_deviation(double values[], int count) {
 double mean = calculate_mean(values, count);
 double sum_squared_diff = 0;
 for (int i = 0; i < count; i++) {
	 double diff = values[i] - mean; 
	 sum_squared_diff += diff * diff;
 }
 return sqrt(sum_squared_diff / count);
}

