#pragma once
#include "Figure.h"

class point:public figure
{
	double x_;
	double y_;

public:
	point();

	auto get_x() const -> double;
	auto get_y() const -> double;

	auto draw_circle() const -> void;
	auto draw_line() const -> void;
	auto draw_point() const -> void;
	auto draw_ellipse() const -> void;
	auto draw_rhombus() const -> void;
	auto draw_square() const -> void;
	auto draw_parallelepiped() const -> void;
};

