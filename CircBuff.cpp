#include "CircBuff.h"

CircBuff::CircBuff(int cap)
{
    _cap = cap;
    _count = 0;
    _head = -1;
    _buff = new float[cap];
}

void CircBuff::push(float val)
{
	int i = _head + 1;
	if(i >= _cap) {
		i = 0;
	}

	_buff[i] = val;
	_head = i;

	if(_count < _cap) {
		_count++;
	}
}

float* CircBuff::pull(float* rtn, int count)
{
	if(count > _cap) 
	{
		count = _cap;
	}

	int i = _head;
	for(int k = 0; k < count && k < _count; k++)
	{
		rtn[k] = _buff[i];
		
		i--;
		if(i < 0)
		{
			i = _cap - 1;
		}
	}

	return rtn;
}
