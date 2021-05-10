#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "queue.h"

struct queue *reallocate(struct queue *q);


struct queue *init_queue( struct queue *q, int init_cap )
{
	if( init_cap < 0 ) init_cap = 10;

	q->store = (T *)malloc( init_cap * sizeof(T) );
	q->capacity = init_cap;
	q->count = 0;
	q->front_index = 0;

	return q;
}

struct queue *enter( struct queue *q, T e )
{
	int index;

	if( q->count == q->capacity ) { /* the queue is full */
		reallocate(q);
	}

	index = (q->front_index+q->count)%q->capacity;

	q->store[index] = e;
	q->count ++;
	
	return q;
}

T leave( struct queue *q )
{
	T v;
	int index;

	assert( q->count > 0 );

	v = q->store[q->front_index];

	index = (q->front_index+1)%q->capacity;
	q->front_index = index;

	q->count --;

	return v;
}

T front(struct queue *q)
{
	T v;

	assert(q->count > 0);

	v = q->store[q->front_index];

	return v;
}

bool is_empty(struct queue *q)
{
	return q->count == 0 ? true : false;
}


struct queue *reallocate(struct queue *q)
{
	int j, index;

	assert(q->capacity == q->count);

	int new_cap = q->capacity * 2;

	T * new_store = (T *)malloc(sizeof(T) * new_cap);

	for (j = 0; j < q->count; j++) {
		index = (q->front_index + j) % q->capacity;
		new_store[j] = q->store[index];
	}

	q->capacity = new_cap;

	free(q->store);

	q->store = new_store;

	q->front_index = 0;	/* front has moved to 0 in new array */
	
	return q;
}

void uninit_queue(struct queue *q)
{
	assert(q->store != NULL);

	free(q->store);
}

