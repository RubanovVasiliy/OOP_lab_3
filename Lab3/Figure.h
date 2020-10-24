#pragma once
class figure
{
	double speed_x_;
	double speed_y_;
	double angle_;
	
	int r_;
	int g_;
	int b_;
	
public:
	figure();
	figure(double speed_x, double speed_y);

	auto get_speed_x() const -> double;
	auto get_speed_y() const -> double;
	auto get_r() const -> int;
	auto get_g() const -> int;
	auto get_b() const -> int;
	auto get_angle() const -> double;
	
	auto set_angle(double angle) -> void;
};

