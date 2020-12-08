#pragma once

#define FATAL_ERROR(msg)			{ std::cout << msg << "\n\n\t" << "Press any key to continue..." << "\n"; \
									  std::cin.get(); exit(1); }

#define SINGLETONIZE(T)				static T & get_instance() { static T instance; return instance; } \
									T(const T &) = delete; \
									T operator = (const T &) = delete; \
									T(T &&) = delete; \
									T operator = (T &&) = delete; 

#define PARTIAL_SINGLETONIZE(T)		static T & get_instance() { static T instance; return instance; } \

#define PI										3.141592653f
#define TO_RAD(angle)							angle = angle * (PI / 180)
#define DEG_TO_RAD								0.017453293