/*
 * approximation.c
 *
 * Created: 07.11.2019 17:51:14
 *  Author: Kenan
 */ 
#include "ringbufferAveraging.h"
#include <stdlib.h>

void InitRingbufferAveraging(ringbufferAveraging_t * _ringbufferAveraging)
{
	
	_ringbufferAveraging->bufferSize = (1 << bufferSizeShift);
	_ringbufferAveraging->bufferHead = 0;
	_ringbufferAveraging->values = (int*)calloc(_ringbufferAveraging->bufferSize,sizeof(int));
}

void addValue(ringbufferAveraging_t * _ringbufferAveraging, int newValue)
{
	 _ringbufferAveraging->values[_ringbufferAveraging->bufferHead] = newValue;
	_ringbufferAveraging->bufferHead = (_ringbufferAveraging->bufferHead+1)%_ringbufferAveraging->bufferSize;
}

int getRingbufferAverage(ringbufferAveraging_t * _ringbufferAveraging)
{
	int approximation = 0;
	for(int i = 0; i < _ringbufferAveraging->bufferSize; i++)
	{
		approximation = +_ringbufferAveraging->values[i];
	}
	//shifting instead of div to be faster!!
	approximation = approximation >> bufferSizeShift;
	return approximation;
}