/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:24:19 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 16:24:19 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &point);
	~Point();
	Point &operator=(const Point &point);

	const Fixed &getX(void) const;
	const Fixed &getY(void) const;
	void setX(Fixed x);
	void setY(Fixed y);

	bool operator==(const Point &other) const;
};

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

#endif