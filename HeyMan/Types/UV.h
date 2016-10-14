#ifndef HEYMAN_UV_H
#define HEYMAN_UV_H

struct UV
{
	UV(float _u = 0, float _v = 0)
		: u(_u), v(_v)
	{
	}

	float u, v;
};

#endif
