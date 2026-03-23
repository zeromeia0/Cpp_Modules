#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &f, T &s)
{
	T temp;
	temp = f;
	f = s;
	s = temp;
}
template <typename T>
T& min(T &f, T &s)
{
	if (f < s)
		return (f);
	else
		return (s);
}
template <typename T>
T& max(T &f, T &s)
{
	if (f > s)
		return (f);
	else
		return (s);
}

#endif