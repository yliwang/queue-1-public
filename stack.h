#pragma once

#include "defs.h"


struct stack
{
	T store[MAX_ELE];
	int count;
};

struct stack *init_stack(struct stack *t);
struct stack *create_stack();

struct stack *push(struct stack *t, T e);

T pop(struct stack *t);

bool is_empty(struct stack *t);

T top(struct stack *t);

