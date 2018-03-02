#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;  // p_error is the previous error until we set it again.
	p_error = cte;		// cross track error - how far from the center
	i_error += cte;		// sum of cte's 
}

double PID::TotalError() {
	return Kp * p_error + Ki * p_error + Kd * d_error;
}

