//#include "templates.hpp"

template<typename T>
void swap(T& a, T& b) {
	 T tmp;

	 tmp = a;
	 a = b;
	 b = tmp;
}

template<typename T>
T min(T a, T b) {

	if (a < b)
		return a;
	else
	 	return b;
}

template<typename T>
T max(T a, T b) {

	if (a > b)
		return a;
	else
	 	return b;
}
// CRITICAL: Add explicit instantiations
//template void swap<int>(int& a, int& b);
//template int min<int>(int a, int b);
//template int max<int>(int a, int b);
//
//// Add other types you need
//template void swap<float>(float& a, float& b);
//template float min<float>(float a, float b);
//template float max<float>(float a, float b);
//
//template void swap<double>(double& a, double& b);
//template double min<double>(double a, double b);
//template double max<double>(double a, double b);
//
//template void swap<unsigned int>(unsigned int& a, unsigned int& b);
//template unsigned int min<unsigned int>(unsigned int a, unsigned int b);
//template unsigned int max<unsigned int>(unsigned int a, unsigned int b);
