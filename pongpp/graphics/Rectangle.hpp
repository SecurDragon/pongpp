#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

struct Rectangle {
	float x, y, width, height;
	Rectangle(float x, float y, float width, float height);
	bool collidesWith(Rectangle& other) const;
};

#endif //_RECTANGLE_H_
