#include "Entities.h"

bool Entities::CollidesWith(Entities* body) {
	if (body->x + body->sizeX < x) return false;
	if (body->x > x + sizeX) return false;

	if (body->y + body->sizeY < y) return false;
	if (body->y > y + sizeY) return false;

	return true;
}