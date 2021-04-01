#pragma once

long double operator"" _Kelvin (long double degrees)
{
	return degrees - 273.15f;
}
long double operator"" _Fahrenheit (long double degrees)
{
	return (degrees - 32) / 1.8f;
}
