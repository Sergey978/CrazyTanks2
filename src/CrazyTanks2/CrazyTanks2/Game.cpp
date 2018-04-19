#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}


void Game::update() {
	for each (Entity *ent in entities)
	{
		ent->update();

	}
}

void Game::render() {
	for each (Entity *ent in entities)
	{
		ent->render();

	}
}

void Game::startGame() {
}

void Game::stopGame() {
}

void Game::addEntity(IEntity &entity) {
	entities.push_back(&entity);
}

void Game::onEntityDestroyed(Entity &entity) {
	// remove destroyed entity
}

vector<IEntity*> Game::getEntities()
{
	return this->entities;
}


Game::~Game()
{
}
