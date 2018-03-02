#pragma once
#include <chrono>
#include <thread>

//https://gist.github.com/svdamani/47b045c82cf9cfb8a392
//Svdamani


template <typename T = std::chrono::milliseconds>
class Timer {
	typedef std::chrono::high_resolution_clock clock;
public:
	Timer() : start(clock::now()) {}

	inline void reset() { start = clock::now(); }

	inline void sleep(int n) const { std::this_thread::sleep_for(T(n)); }

	inline double elapsed() const {
		return std::chrono::duration_cast<T>(clock::now() - start).count();
	}
private:
	std::chrono::time_point<clock> start;
};