#include "Update.h"

void ProjectShipwreckLowClass::Update::render_AllFilesRenderFunctions()
{

}

void ProjectShipwreckLowClass::Update::update_AllFilesUpdateFunctions(SDL_Event & tempEvent)
{
	ProjectShipwreckHighClass::S_EventHandler::get_Instance()->HandleInputEvents(tempEvent);
}