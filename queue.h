#pragma once

#include "defs.h"

struct queue
{
	T store[#define MAX_ELE];
	int count;
	int front_index;
};

struct queue *init_queue(struct queue *q);

struct queue *enter(struct queue *q, T e);
T leave(struct queue *q);

T front(struct queue *q);

bool is_empty(struct queue *q);






