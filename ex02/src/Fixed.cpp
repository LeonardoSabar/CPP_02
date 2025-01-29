/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:58:15 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/29 19:58:15 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::Fixed(const int n) {
	this->_value = n << _fractionalBits;
}

Fixed::Fixed(const float f) : _value(f) {
	this->_value = roundf(f * (1 << _fractionalBits));
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(Fixed const &rSym) {
	if (this != &rSym)
		this->_value = rSym.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &rSym) const {
	return Fixed(this->toFloat() + rSym.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rSym) const {
	return Fixed(this->toFloat() - rSym.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rSym) const {
	return Fixed(this->toFloat() * rSym.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rSym) const {
	return Fixed(this->toFloat() / rSym.toFloat());
}

bool	Fixed::operator<(Fixed const &rSym) const {
	if (this->getRawBits() < rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(Fixed const &rSym) const {
	if (this->getRawBits() > rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &rSym) const {
	if (this->getRawBits() <= rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &rSym) const {
	if (this->getRawBits() >= rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &rSym) const {
	if (this->getRawBits() == rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &rSym) const {
	if (this->getRawBits() != rSym.getRawBits())
		return true;
	return false;
}

Fixed&	Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	operator--();
	return tmp;
}

int		Fixed::getRawBits() const {
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat() const {
	return (float)this->_value / (float)(1 << _fractionalBits);
}

int		Fixed::toInt() const {
	return this->_value >> _fractionalBits;
}

Fixed &	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) {
	o << rSym.toFloat();
	return o;
}