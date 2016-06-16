#pragma once

#include <SFML\Graphics.hpp>

class aux_state {
public:
	virtual void Initialize(sf::RenderWindow* window) {

	}
	virtual void Update(sf::RenderWindow* window) {

	}
	virtual void Render(sf::RenderWindow* window) {

	}
	virtual void Destroy(sf::RenderWindow* window) {

	}
	~aux_state() {
	}
};

class state_manager {
public:
	state_manager() {
		this->state = NULL;
	}
	void SetWindow(sf::RenderWindow* _window) {
		this->window = _window;
	}

	void SetState(aux_state* _state) {
		if (this->state != NULL) {
			this->state->Destroy(this->window);
		}
		delete this->state;
		this->state = _state;
		if (this->state != NULL) {
			this->state->Initialize(this->window);
		}
	}

	void Update() {
		if (this->state != NULL) {
			this->state->Update(this->window);
		}
	}
	void Render() {
		if (this->state != NULL) {
			this->state->Render(this->window);
		}
	}

	~state_manager(){
		if (this->state != NULL) {
			this->state->Destroy(this->window);
		}
	}
private:
	aux_state* state;
	sf::RenderWindow* window;
};

extern state_manager coreState;
extern bool quitGame;