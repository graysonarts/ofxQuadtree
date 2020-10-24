#pragma once

#include "ofMain.h"
#include "quadtree.h"

class ofxQuadtree {
public:
	ofxQuadtree(ofRectangle& rect, uint8_t capacity);
	~ofxQuadtree();

	void clear();
	int insert(glm::vec2& pt, void* data);
	const void* query(glm::vec2& pt, float radius, size_t &count) const;

private:
	quadtree::Quadtree* tree;
	ofRectangle rect;
	uint8_t capacity;
};