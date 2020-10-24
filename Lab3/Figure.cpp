#include "Figure.h"
#include <cmath>

figure::figure()
{
	this->speed_x_= rand() % 1000 / 100000.0 * pow(-1, rand() % 2);
	this->speed_y_ = rand() % 1000 / 100000.0 * pow(-1, rand() % 2);
	this->angle_ = rand() % 360;
	this->r_ = rand() % 255;
	this->g_ = rand() % 255;
	this->b_ = rand() % 255;
}

figure::figure(const double speed_x, const double speed_y)
{
	this->speed_x_ = speed_x;
	this->speed_y_ = speed_y;
	this->angle_ = rand() % 10 / 10.0;
	this->r_ = rand() % 255;
	this->g_ = rand() % 255;
	this->b_ = rand() % 255;
}

double figure::get_speed_x() const
{
	return this->speed_x_;
}

auto figure::get_speed_y() const -> double
{
	return this->speed_y_;
}

int figure::get_r() const
{
	return this->r_;
}

int figure::get_g() const
{
	return this->g_;
}

int figure::get_b() const
{
	return this->b_;
}

auto figure::get_angle() const -> double
{
	return this->angle_;
}

auto figure::set_angle( double angle) -> void
{
	this->angle_ = angle;
}
