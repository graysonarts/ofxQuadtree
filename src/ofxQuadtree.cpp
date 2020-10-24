#include "ofxQuadtree.h"

using namespace quadtree;

ofxQuadtree::ofxQuadtree(ofRectangle& rect, uint8_t capacity) : tree(nullptr), rect(rect), capacity(capacity) {
	tree = quadtree_new(rect.x, rect.y, rect.width, rect.height, capacity);
}

ofxQuadtree::~ofxQuadtree() {
	if (tree != nullptr) {
		quadtree_free(tree);
		tree = nullptr;
	}
}

int ofxQuadtree::insert(glm::vec2& pt, void* data) {
	if (tree == nullptr) {
		return -1;
	}

	return quadtree_insert_point(tree, pt.x, pt.y, data);
}

const void* ofxQuadtree::query(glm::vec2& pt, float radius, size_t& count) const {
	if (tree == nullptr) {
		count = 0;
		return nullptr;
	}

	return quadtree_query(tree, pt.x, pt.y, radius, &count);
}

void ofxQuadtree::clear() {
	if (tree != nullptr) quadtree_free(tree);
	tree = quadtree_new(rect.x, rect.y, rect.width, rect.height, capacity);
}