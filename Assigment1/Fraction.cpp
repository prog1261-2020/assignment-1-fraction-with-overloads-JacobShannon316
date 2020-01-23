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
#include "Fraction.h"
#include <sstream>
#include <numeric>
Fraction::Fraction()
{
}
Fraction::Fraction(int n, int d) : numerator(n), denomintor(d)
{
	if (denomintor == 0)				//this constructor takes a denominator and numerator
		denomintor = 1;

	reduce();
}

Fraction::Fraction(int n) : numerator(n)
{
	denomintor = 1;						//this constructor will take an int and turn it into a faction with a default denomintor of 1
}

Fraction Fraction::add(Fraction other) const {
	Fraction tmp(1, 1);

	tmp.denomintor = denomintor * other.denomintor;			//this function allows the factions to add other fractions
	tmp.numerator = numerator * other.denomintor + other.numerator * denomintor;
	tmp.reduce();
	return tmp;
}
Fraction Fraction::sub(Fraction other) const {
	Fraction tmp(1, 1);
	tmp.denomintor = denomintor * other.denomintor;
	tmp.numerator = numerator * other.denomintor - other.numerator * denomintor;	//this function allows the fractions to subtrack other fractions
	tmp.reduce();
	return tmp;
}
Fraction Fraction::multiply(Fraction other) const {
	Fraction tmp(1, 1);
	tmp.denomintor = denomintor * other.denomintor;			
	tmp.numerator = numerator * other.numerator;			//this function allows the fractions to multiply with other fractions
	tmp.reduce();
	return tmp;
}
Fraction Fraction::division(Fraction other) const
{
	Fraction tmp(1, 1);
	tmp.denomintor = other.numerator;						//this function allows the fractions to divide with other fractions
	tmp.numerator = other.denomintor;
	tmp = multiply(tmp);
	return tmp;
}
std::string Fraction::toString()
{
	std::stringstream ss;
	ss << numerator << "/" << denomintor;				
	return ss.str();
}
void Fraction::reduce()
{
	if (numerator < 0 && denomintor < 0)
	{
			numerator *= -1;
			denomintor *= -1;							//this function is used to tell if the fraction is negitive or not and make the fraction the in lowest terms
	}
	else if (denomintor < 0)
	{
			numerator *= -1;
			denomintor *= -1;
	}
	int divider;
	divider = std::gcd(denomintor, numerator);
	denomintor /= divider;
	numerator /= divider;
}
bool Fraction::operator==(const	Fraction& rhs) const {
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;		//this equel operator is checking two fractions to see if they are equel by giving them the same denomintor
	tmp1.numerator = numerator * rhs.denomintor;
	tmp2.numerator = rhs.numerator * denomintor;
	if (tmp1.numerator == tmp2.numerator)
		return true;
	else
		return false; 
}
bool Fraction::operator!=(const Fraction& rhs) const
{
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;
	tmp1.numerator = numerator * rhs.denomintor;					//this does the same thing as the last operator but instead checks if they are not equel
	tmp2.numerator = rhs.numerator * denomintor;
	if (tmp1.numerator != tmp2.numerator)
		return true;
	else
		return false;
}

bool Fraction::operator<(const Fraction& rhs) const
{
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;
	tmp1.numerator = numerator * rhs.denomintor;				    //this is doing the same thing it is making the two fractions have the same denominator but checking if the fraction on the
	tmp2.numerator = rhs.numerator * denomintor;					//has a larger denomintor
	if (tmp1.numerator < tmp2.numerator)
		return true;
	else
		return false; 
}
bool operator<(const Fraction& lhs, const int& rhs)
{
	int tmp1;
	tmp1 = rhs * lhs.denomintor;									//this time the fraction is being compared to an int so the int will be check to see if it is larger by mutiplying it by the 
	if (lhs.numerator < tmp1)										//the denominator of the fraction on the right
		return true;
	else
		return false;
}

bool operator<(const int& lhs, const Fraction& rhs)
{
	int tmp1;
	tmp1 = lhs * rhs.denomintor;									//Now this is doing the same thing as the last on but this time the int is on the right sign of the operator
	if (tmp1 < rhs.numerator)
		return true;
	else
		return false;
}
bool Fraction::operator>(const Fraction& rhs) const
{
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;
	tmp1.numerator = numerator * rhs.denomintor;				  //Now the next three oprators are the same as the last three but the is checking greater than
	tmp2.numerator = rhs.numerator * denomintor;
	if (tmp1.numerator > tmp2.numerator)
		return true;
	else
		return false;
}
bool operator>(const Fraction& lhs, const int& rhs)
{
	int tmp1;
	tmp1 = rhs * lhs.denomintor;
	if (lhs.numerator > tmp1)
		return true;
	else
		return false;
}

bool operator>(const int& lhs, const Fraction& rhs)
{
	int tmp1;
	tmp1 = lhs * rhs.denomintor;
	if (rhs.numerator < tmp1)
		return true;
	else
		return false;
}
bool Fraction::operator<=(const Fraction& rhs) const
{
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;	//here the i using the code from less then and equel to see if the left fraction meets either one
	tmp1.numerator = numerator * rhs.denomintor;
	tmp2.numerator = rhs.numerator * denomintor;
	if (tmp1.numerator == tmp2.numerator)
		return true;
	else
	{
		Fraction tmp1(1);
		Fraction tmp2(1);
		tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;
		tmp1.numerator = numerator * rhs.denomintor;
		tmp2.numerator = rhs.numerator * denomintor;
		if (tmp1.numerator < tmp2.numerator)
			return true;
		else
			return false;
	}

}

bool operator<=(const Fraction& lhs, const int& rhs)
{
	int tmp1;
	tmp1 = rhs * lhs.denomintor;
	if (lhs.numerator == tmp1)
		return true;													//this is the same as the last but this comparing a fraction to an int
	else
	{
		int tmp1;
		tmp1 = rhs * lhs.denomintor;
		if (lhs.numerator < tmp1)
			return true;
		else
			return false;
	}
}

bool operator<=(const int& lhs, const Fraction& rhs)
{
	int tmp1;
	tmp1 = lhs * rhs.denomintor;
	if (rhs.numerator == tmp1)										
		return true;
	else
	{
		int tmp1;
		tmp1 = lhs * rhs.denomintor;
		if (rhs.numerator > tmp1)
			return true;
		else
			return false;
	}
}
bool Fraction::operator>=(const Fraction& rhs) const
{
	Fraction tmp1(1);
	Fraction tmp2(1);
	tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;	//same as before just the sign has fliped
	tmp1.numerator = numerator * rhs.denomintor;
	tmp2.numerator = rhs.numerator * denomintor;
	if (tmp1.numerator == tmp2.numerator)
		return true;
	else
	{
		Fraction tmp1(1);
		Fraction tmp2(1);
		tmp1.denomintor, tmp2.denomintor = denomintor * rhs.denomintor;
		tmp1.numerator = numerator * rhs.denomintor;
		tmp2.numerator = rhs.numerator * denomintor;
		if (tmp1.numerator > tmp2.numerator)
			return true;
		else
			return false;
	}

}
bool operator>=(const Fraction& lhs, const int& rhs)
{
	int tmp1;
	tmp1 = rhs * lhs.denomintor;
	if (lhs.numerator == tmp1)
		return true;
	else
	{
		int tmp1;
		tmp1 = rhs * lhs.denomintor;
		if (lhs.numerator > tmp1)
			return true;
		else
			return false;
	}
}

bool operator>=(const int& lhs, const Fraction& rhs)
{
	int tmp1;
	tmp1 = lhs * rhs.denomintor;
	if (rhs.numerator == tmp1)
		return true;
	else
	{
		int tmp1;
		tmp1 = lhs * rhs.denomintor;
		if (rhs.numerator < tmp1)
			return true;
		else
			return false;
	}
}
Fraction Fraction::operator+(const Fraction& rhs) const				//this operator is going to make two fractions add together by making them into the same dennoimtor and the adding the numerators
{
	Fraction tmp(1);
	tmp.denomintor = rhs.denomintor * denomintor;
	tmp.numerator = (rhs.numerator * denomintor) + (numerator * rhs.denomintor);
	tmp.reduce();
	return tmp;
}
Fraction operator+(const Fraction& lhs, const int& rhs)				//this operator is adding a fracion to an int and it is doing this by making the fraction denomintor 1 so it can add the int to the numorator
 {
	Fraction tmp(1);
	tmp.denomintor = lhs.denomintor;
	tmp.numerator = (rhs * lhs.denomintor) + lhs.numerator;
	tmp.reduce();
	return tmp;
 }
Fraction operator+(const int& lhs, const Fraction& rhs)				//this is doing the same but in a different order
{
	Fraction tmp(1);
	tmp.denomintor = rhs.denomintor;
	tmp.numerator = (lhs * rhs.denomintor) + rhs.numerator;
	tmp.reduce();
	return tmp;
}
Fraction& Fraction::operator+=(const Fraction& rhs)					//this is doing the same as before with adding two fractions toegther but instead of useing a tmp it is changing values of current Fraction
{
	int tmp1;
	tmp1 = denomintor;
	denomintor = denomintor * rhs.denomintor;
	numerator = (numerator * rhs.denomintor) + (rhs.numerator * tmp1);
	reduce();
	return *this;
}
Fraction operator+=(Fraction& lhs, const int& rhs)
{
	int tmp1;
	tmp1 = rhs * lhs.denomintor;
	lhs.numerator += tmp1;
	lhs.reduce();
	return lhs;
}

Fraction operator+=(int& lhs, const Fraction& rhs)
{
	Fraction tmp1(lhs, 1);
	tmp1.numerator *= rhs.denomintor;
	tmp1.denomintor = rhs.denomintor;
	tmp1.numerator += rhs.numerator;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator-(const Fraction& rhs)				// subtraction is being done the same way as adding instead this time the numerators will subtrack instead of add
{
	Fraction tmp(1);
	tmp.denomintor = rhs.denomintor * denomintor;
	tmp.numerator = (numerator * rhs.denomintor)-(rhs.numerator * denomintor);
	tmp.reduce();
	return tmp;

}

Fraction Fraction::operator-(const int& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = denomintor;
	tmp1.numerator = numerator - (rhs * denomintor);
	tmp1.reduce();
	return tmp1;
}


Fraction operator-(const int& lhs, const Fraction& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = rhs.denomintor;
	tmp1.numerator = (lhs * rhs.denomintor) - rhs.numerator;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator-=(const Fraction& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = denomintor * rhs.denomintor;
	tmp1.numerator = (numerator * rhs.denomintor)-(rhs.numerator * denomintor);
	tmp1.reduce();
	*this = tmp1;
	return *this;
}
Fraction Fraction::operator-=(const int& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = denomintor;
	tmp1.numerator =  numerator - (rhs * denomintor);
	tmp1.reduce();
	*this = tmp1;
	return *this;
}
Fraction operator-=(const int& lhs, const Fraction& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = rhs.denomintor;
	tmp1.numerator = (lhs * rhs.denomintor - rhs.numerator);
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator*(const Fraction& rhs)//this is the mutiplcation operator and it will mutipley two fractions by mutiplyling there numerators and denomintors and puting the new value a tmp varible
{
	Fraction tmp1(1, 1);
	tmp1.numerator = numerator * rhs.numerator;
	tmp1.denomintor = denomintor * rhs.denomintor;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator*(const int& rhs)	//this is the operator when a faction gets mutiplyed by an int and how it is being done is that becuase we know int is a hole number we will treat it like a fraction with a denoinotor of 1
{
	Fraction tmp1(1, 1);
	tmp1.numerator = numerator * rhs;
	tmp1.denomintor = denomintor;
	tmp1.reduce();
	return tmp1;
}

Fraction operator*(const int& lhs, const Fraction& rhs) //same thing just int of the left instead of the right
{
	Fraction tmp1(1, 1);
	tmp1.numerator = rhs.numerator * lhs;
	tmp1.denomintor = rhs.denomintor;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator*=(const Fraction& rhs) //this is making so that when it does the caluclation it changes the current fraction
{
	numerator *= rhs.numerator;
	denomintor *= rhs.denomintor;
	reduce();
	return *this;
}

Fraction operator*=(Fraction& lhs, const int& rhs)
{
	lhs.numerator *= rhs;
	lhs.reduce();
	return lhs;
}

Fraction operator*=(const int& lhs, const Fraction& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.numerator = lhs * rhs.numerator;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator/(const Fraction& rhs)	//this is the divide operator and the way that i chose to divide the two fractions is by using the same change flip method
{
	Fraction tmp1(1,1);
	tmp1.numerator = numerator * rhs.denomintor;
	tmp1.denomintor = denomintor * rhs.numerator;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator/(const int& rhs)	//this is the same as the mutiplaction i just treated the int as a fraction with a denomintor of 1
{
	Fraction tmp1(1, 1);
	tmp1.numerator = numerator;
	tmp1.denomintor = denomintor * rhs;
	tmp1.reduce();
	return tmp1;
}

Fraction operator/(const int& lhs, const Fraction& rhs) 
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = rhs.numerator;
	tmp1.numerator = lhs * rhs.denomintor;
	tmp1.reduce();
	return tmp1;
}
Fraction Fraction::operator/=(const Fraction& rhs) // this is just doing the same as the other divide operators but it is changing the value of the fraction on the right
{
	Fraction tmp1(1, 1);
	tmp1.numerator = numerator * rhs.denomintor;
	tmp1.denomintor = denomintor * rhs.numerator;
	tmp1.reduce();
	numerator = tmp1.numerator;
	denomintor = tmp1.denomintor;
	return *this;
}
Fraction Fraction::operator/=(const int& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.numerator = numerator;
	tmp1.denomintor = denomintor * rhs;
	tmp1.reduce();
	numerator = tmp1.numerator;
	denomintor = tmp1.denomintor;
	return *this;
}
Fraction operator/=(const int& lhs, const Fraction& rhs)
{
	Fraction tmp1(1, 1);
	tmp1.denomintor = rhs.numerator;
	tmp1.numerator = lhs * rhs.denomintor;
	tmp1.reduce();
	return tmp1;
}

std::ostream& operator<<(std::ostream& os, const Fraction& rhs)
{
	os << rhs.numerator << "/" << rhs.denomintor;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& rhs)
{
	char c;
	is >> rhs.numerator >> c >> rhs.denomintor;
	return is;
}

