#ifndef CHARACTER_HPP
	#define CHARACTER_HPP
#include <vector>
#include "globals.hpp"
#include "tiles.hpp"
#include "npc.hpp"
#include "particle.hpp"
#include "timer.hpp"

class Character {
	public:
		//The dimensions of the character

		const int CHARACTER_WIDTH;// = 65;
		const int CHARACTER_HEIGHT;// = 80;
		static const int ANIMATION_FRAMES = 16;
		static const int JUMPING_FRAMES = 6;
		static const int FALLING_FRAMES = 6;
		static const int ATTACKING_FRAMES = 12;
		static const int SECOND_ATTACKING_FRAMES = 10;
		static const int SPRITESHEET_WIDTH = 858;
		//static const int SPRITESHEET_HEIGHT = 40;

		// Clip containers.
		LTexture characterTexture;
		SDL_Rect spriteClips[ANIMATION_FRAMES];
		SDL_Rect jumpClips[JUMPING_FRAMES];
		SDL_Rect fallClips[FALLING_FRAMES];
		SDL_Rect attackClips[ATTACKING_FRAMES];
		SDL_Rect secondAttackClips[SECOND_ATTACKING_FRAMES];

		//Maximum axis velocity of the character
		const int CHARACTER_VELY = 15 * 60; // * SCREEN_FPS; // 15;
		const int CHARACTER_VELX = 7 * 60; // * SCREEN_FPS; //10;

		bool headJump;
		bool isAttacking;

		bool tileTap = false;
		bool oscillate = false;

		// Animation.
		SDL_Rect *currentClip = NULL;
		int frameRate;

		int attackingFrame;
		int walkingFrame;
		int fallingFrame;

		LTimer attackingTimer;
		LTimer fallingTimer;
		LTimer walkingTimer;

		bool firstAttack = false;
		bool secondAttack = false;
		bool firstWalk = false;

		//Initializes the variables allocates particles.
		Character(int width, int height);

		// Deallocates particles.
		~Character();

		//Takes key presses and adjusts the character's velocity
		void handleEvent(SDL_Event &e);

		//Moves the character and check collision against tiles
		void move(Tile *tiles[], std::vector<Npc *> &npcVector, float timeStep);

		//Centers the camera over the character
		void setCamera(SDL_Rect &camera);

		//Shows the character on the screen
		void render(SDL_Rect &camera, bool toggleParticles, float scale = 1.0, float heightScale = 1.0);
		SDL_Rect dstrect = { 0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT };

		bool isJumping;
		bool isMoving;
		SDL_RendererFlip flip;

		inline SDL_Rect getBoxPosition() {
			return mBox;
		}

		inline float getPosX() {
			return mPosX;
		}

		inline float getPosY() {
			return mPosY;
		}

		inline float getVelocityX() {
			return mVelX;
		}

		inline float getVelocityY() {
			return mVelY;
		}

		inline void setVelocityX(float velocity) {
			mVelX = velocity;
		}

		inline void setVelocityY(float velocity) {
			mVelY = velocity;
		}


	private:

		// Particles.
		Particle *particles[TOTAL_PARTICLES];

		// Render particles.
		void renderParticles(SDL_Rect &camera, bool toggleParticles);

		//Collision box of the character
		SDL_Rect mBox;

		//Collision box of weapon.
		SDL_Rect mWeapon;
		float mPosX, mPosY;

		//The velocity of the character
		float mVelX, mVelY;
};

#endif
