/*
Copyright (c) 2016 Ryan L. Guy

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgement in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#include "fluidsource.h"

FluidSource::FluidSource() {
}

FluidSource::FluidSource(vmath::vec3 pos) : position(pos),
                                            direction(1.0, 0.0, 0.0) {
}

FluidSource::FluidSource(vmath::vec3 pos, vmath::vec3 vel) : 
                                          position(pos),
                                          velocity(vel),
                                          direction(vmath::normalize(velocity)) {
    if (!(vmath::length(velocity) > 0.0)) {
        direction = vmath::vec3(1.0, 0.0, 0.0);
    }
}


FluidSource::~FluidSource() {
}

void FluidSource::setPosition(vmath::vec3 pos) {
    position = pos;
}

vmath::vec3 FluidSource::getPosition() {
   return position;
}

void FluidSource::translate(vmath::vec3 trans) {
    position += trans;
}

void FluidSource::setVelocity(vmath::vec3 v) {
    velocity = v;
    if (vmath::length(v) > 0.0) {
        direction = vmath::normalize(v);
    } else {
        direction = vmath::vec3(1.0, 0.0, 0.0);
    }
}

void FluidSource::setDirection(vmath::vec3 dir) {
    float length = vmath::length(dir);
    if (!(length > 0.0f)) {
        return;
    }

    direction = vmath::normalize(dir);
    velocity = vmath::length(velocity) * velocity;
}

vmath::vec3 FluidSource::getVelocity() {
    return velocity;
}

void FluidSource::setAsInFlow() {
    sourceType = FluidSourceType::inflow;
}

void FluidSource::setAsOutFlow() {
    sourceType = FluidSourceType::outflow;
}

FluidSourceType FluidSource::getSourceType() {
    return sourceType;
}

bool FluidSource::isInflow() {
    return sourceType == FluidSourceType::inflow;
}

bool FluidSource::isOutflow() {
    return sourceType == FluidSourceType::outflow;
}

void FluidSource::activate() {
    isRunning = true;
}

void FluidSource::deactivate() {
    isRunning = false;
}

bool FluidSource::isActive() {
    return isRunning;
}

GridIndexVector FluidSource::getNewFluidCells(FluidMaterialGrid&, double) {
    return GridIndexVector();
}

GridIndexVector FluidSource::getFluidCells(FluidMaterialGrid&, double) {
    return GridIndexVector();
}

GridIndexVector FluidSource::getCells(FluidMaterialGrid&, double) {
    return GridIndexVector();
}

AABB FluidSource::getAABB() {
    return AABB();
}

bool FluidSource::containsPoint(vmath::vec3 p) {
  return false;
}

int FluidSource::getID() {
    return id;
}

void FluidSource::setID(int identifier) {
    id = identifier;
}