#include "Text.h"

#include "../../Engine/Graphics/Graphics.h"

void Text::render() {
    Graphics::drawString(getX(), getY(), const_cast<char *>(_string));
}

void Text::update() {

}
