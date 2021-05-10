#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "queue.h"

struct queue *init_queue( struct queue *q )
{
	q->count = 0;
	q->front_index = 0;

	return q;
}

