#include <iostream>
#include <windows.h>

template<typename Function>

double timer(Function func) {
	double time1 = GetTickCount64();
	func();
	double time2 = GetTickCount64();
	return(time2 - time1);
}

int generic_function() {
	Sleep(200);
	return(0);
}

int main() {
	double time_bank[5] = { 0, 0, 0, 0, 0 };
	
	while (true) {
		double current_time = timer(generic_function);
		double average_time = 0;

		// Fill array with initial time
		if (time_bank[0] == 0) {
			for (int i = 0; i < 5; i++) {
				time_bank[i] = current_time;
			}
		}

		// If array has values
		if (time_bank[0] != 0) {
			for (int i = 0; i < 5; i++) {
				average_time = time_bank[i] + average_time;
			}
			average_time = average_time / 5;

			// Check if time is out of bounds and return if true
			if (current_time > average_time * 1.5 || current_time < average_time / 1.5) {
				std::cout << "out of bounds execution time: " << current_time << std::endl;
				return(0);
			}
			// Shift all and add new time
			else {
				for (int i = 0; i < 5; i++) {
					 time_bank[i] = time_bank[i + 1];
				}
				time_bank[4] = current_time;

				// Debug output
				std::cout << "[ " << time_bank[0] << " " << time_bank[1] << " " << time_bank[2] << " " << time_bank[3] << " " << time_bank[4] << " ]" << std::endl;
			}
		}
		Sleep(500);
	}
}