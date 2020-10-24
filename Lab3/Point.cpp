#include "Point.h"
#include <glut.h>
#include <cmath>

constexpr auto pi = 3.14159265;

point::point():figure()
{
	this->x_ = rand() % 1000 / 1000.0 * pow(-1, rand() % 2);
	this->y_ = rand() % 1000 / 1000.0 * pow(-1, rand() % 2);
}

auto point::get_x() const -> double
{
	return this->x_;
}

auto point::get_y() const -> double
{
	return this->y_;
}

auto point::draw_circle() const -> void
{
	const auto radius = 0.05;

	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(static_cast<GLbyte>(figure::get_r()), 
		static_cast<GLbyte>(figure::get_g()), 
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_, y_);
	for (auto angle = 0; angle <= 360; angle += 10)
	{
		const auto x = radius * cos(static_cast<double>(angle) * pi / 180);
		const auto y = radius * sin(static_cast<double>(angle) * pi / 180);
		glColor3ub(static_cast<GLbyte>(figure::get_r()), 
			static_cast<GLbyte>(figure::get_g()),
			static_cast<GLbyte>(figure::get_b()));
		glVertex2d(x_ + x, y_ + y);
	}
	glEnd();
	glPopMatrix();
	set_angle();
}

auto point::draw_line() const -> void
{
	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_ + 0.1, y_ - 0.01);
	glVertex2d(x_ - 0.01, y_ + 0.01);
	glEnd();
	glPopMatrix();

}

auto point::draw_point() const -> void
{
	const auto radius = 0.005;

	
	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_, y_);
	for (auto angle = 0; angle <= 360; angle += 10)
	{
		const auto x = radius * cos(static_cast<double>(angle) * pi / 180);
		const auto y = radius * sin(static_cast<double>(angle) * pi / 180);
		glColor3ub(static_cast<GLbyte>(figure::get_r()),
			static_cast<GLbyte>(figure::get_g()),
			static_cast<GLbyte>(figure::get_b()));
		glVertex2d(x_ + x, y_ + y);
	}
	glEnd();
	glPopMatrix();
}

auto point::draw_ellipse() const -> void
{
	const auto rx = 0.05;
	const auto ry = 0.03;
	const auto step = static_cast<float>(2 * pi) / 360;

	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2f(x_, y_);
	for (float angle = 0; angle <= static_cast<float>(2 * pi); angle += step)
	{
		float a = (fabsf(angle - float(2 * pi)) < 0.00001f) ? 0.f : angle;
		const auto dx = rx * cosf(a);
		const auto dy = ry * sinf(a);
		glVertex2f(dx + x_, dy + y_);
	}
	glEnd();
	glPopMatrix();
}

auto point::draw_rhombus() const -> void
{
	const auto rx = 0.05;
	const auto ry = 0.03;

	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_ , y_ + ry);
	glVertex2d(x_ + rx, y_ );
	glVertex2d(x_ , y_ - ry);
	glVertex2d(x_ - rx, y_);
	glEnd();
	glPopMatrix();
}

auto point::draw_square() const -> void
{
	const auto radius = 0.05;

	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);

	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_ + radius, y_ + radius);
	glVertex2d(x_ + radius, y_ - radius);
	glVertex2d(x_ - radius, y_ - radius);
	glVertex2d(x_ - radius, y_ + radius);
	glEnd();
	glPopMatrix();
}

auto point::draw_parallelepiped() const -> void
{
	const auto rx = 0.05;
	const auto ry = 0.07;

	glPushMatrix();
	glRotated(this->get_angle(), 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glColor3ub(static_cast<GLbyte>(figure::get_r()),
		static_cast<GLbyte>(figure::get_g()),
		static_cast<GLbyte>(figure::get_b()));
	glVertex2d(x_ + rx, y_ + ry);
	glVertex2d(x_ + rx, y_ - ry);
	glVertex2d(x_ - rx, y_ - ry);
	glVertex2d(x_ - rx, y_ + ry);
	glEnd();
	glPopMatrix();
}
