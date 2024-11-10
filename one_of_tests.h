#pragma once
#include "one_of.h"

struct A {};
struct B {};
struct C {};

static_assert(is_one_of<A, A>::value == true);
static_assert(is_one_of<A, B>::value == false);

static_assert(is_one_of<A, B, C>::value == false);
static_assert(is_one_of<A, A, B>::value == true);
static_assert(is_one_of<A, B, A>::value == true);

static_assert(is_one_of<A, A, B, C>::value == true);

static_assert(is_one_of_v<A, A> == true);
static_assert(is_one_of_v<A, B> == false);

static_assert(is_one_of_v<A, B, C> == false);
static_assert(is_one_of_v<A, A, B> == true);
static_assert(is_one_of_v<A, B, A> == true);

static_assert(is_one_of_v<A, A, B, C> == true);