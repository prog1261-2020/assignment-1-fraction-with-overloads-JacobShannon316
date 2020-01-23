/**
* @Jacob Shannon
*
* @OperatorOverloadFractions
* @version <1.0>
*
* change log
* name Jacob Shannon date jan 22 2020
*
*
* (file, auther, version, and change log are depricated with modern source code management system)
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  this program is an example of how to use operatorOverload to make so that we can before operations on objects such as the fractions in the program
*  
*
* @section LICENSE
*  <any necessary attributions>
*
*  CopyLeft 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/
#pragma once
#include <string>
class Fraction
{
public:
	Fraction();
	Fraction(int n, int d);
	Fraction(int n);

	Fraction add(Fraction other) const;
	Fraction sub(Fraction other) const;
	Fraction multiply(Fraction other) const;
	Fraction division(Fraction other) const;
	std::string toString();

	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;
	
	bool operator<(const Fraction& rhs) const;
	friend bool operator<(const Fraction& lhs, const int& rhs);
	friend bool operator<(const int& lhs, const Fraction& rhs);

	bool operator>(const Fraction& rhs) const;
	friend bool operator>(const Fraction& lhs, const int& rhs);
	friend bool operator>(const int& lhs, const Fraction& rhs);

	bool operator<=(const Fraction& rhs) const;
	friend bool operator<=(const Fraction& lhs, const int& rhs);
	friend bool operator<=(const int& lhs, const Fraction& rhs);

	bool operator>=(const Fraction& rhs) const;
	friend bool operator>=(const Fraction& lhs, const int& rhs);
	friend bool operator>=(const int& lhs, const Fraction& rhs);

	Fraction operator+(const Fraction& rhs)const;
	friend Fraction operator+(const Fraction& lhs, const int& rhs);
	friend Fraction operator+(const int& lhs, const Fraction& rhs);

	Fraction& operator+=(const Fraction& rhs);
	friend Fraction operator+=(Fraction& lhs, const int& rhs);
	friend Fraction operator+=(int& lhs, const Fraction& rhs);

	Fraction operator-(const Fraction& rhs);
    Fraction operator-(const int& rhs);
    friend Fraction operator-(const int& lhs, const Fraction& rhs);

	Fraction operator-=(const Fraction& rhs);
	Fraction operator-=(const int& rhs);
	friend Fraction operator-=(const int& lhs, const Fraction& rhs);

	Fraction operator*(const Fraction& rhs);
	Fraction operator*(const int& rhs);
	friend Fraction operator*(const int& lhs, const Fraction& rhs);

	Fraction operator*=(const Fraction& rhs);
	friend Fraction operator*=(Fraction& lhs, const int& rhs);
	friend Fraction operator*=(const int& lhs, const Fraction& rhs);

	Fraction operator/(const Fraction& rhs);
	Fraction operator/(const int& rhs);
	friend Fraction operator/(const int& lhs, const Fraction& rhs);

	Fraction operator/=(const Fraction& rhs);
	Fraction operator/=(const int& rhs);
	friend Fraction operator/=(const int& lhs, const Fraction& rhs);

	friend std::ostream& operator << (std::ostream& os, const Fraction& rhs);
	friend std::istream& operator >> (std::istream& is,  Fraction& rhs);

	int numerator;
	int denomintor;

private:
	void reduce();



};
