#pragma once

/* Generated with cbindgen:0.15.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

namespace quadtree {

struct Quadtree;

extern "C" {

Quadtree *quadtree_new(float x, float y, float w, float h, uint8_t capacity);

/// # Safety
void quadtree_free(Quadtree *qt);

/// # Safety
int quadtree_insert_point(Quadtree *qt, float x, float y, const void *data);

/// # Safety
const void *quadtree_query(const Quadtree *qt, float x, float y, float r, uintptr_t *count);

} // extern "C"

} // namespace quadtree
