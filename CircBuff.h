#ifndef CircBuff_h
#define CircBuff_h

#include "Arduino.h"

class CircBuff
{
  public:
    CircBuff(int cap);
    void push(float val);
    float* pull(float* rtn, int count);
  private:
    int _cap;
    int _count;
    int _head;
    float* _buff;
};

#endif
