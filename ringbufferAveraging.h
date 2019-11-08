/*
 * approximaton.h
 *
 * Created: 07.11.2019 17:51:46
 *  Author: Kenan
 */ 


#ifndef RINGBUFFERAVERAGING_H_
#define RINGBUFFERAVERAGING_H_
#define bufferSizeShift 6

typedef struct _approximation_t ringbufferAveraging_t;

void InitRingbufferAveraging(ringbufferAveraging_t * _ringbufferAveraging);
void addValue(ringbufferAveraging_t * _approximation, int newValue);
int getRingbufferAverage(ringbufferAveraging_t * _approximation);

struct _approximation_t
{
	int * values;
	int bufferSize;
	int bufferHead;
};
#endif /*  RINGBUFFERAVERAGING_H_ */