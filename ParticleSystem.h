//Adam Coffman 
//Particle System Class
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <time.h>

const int NUMBER_OF_PARTICLES = 5000;
const float MAX_ROTATION = 360;
const float MIN_ROTATION = 0;
const float MIN_TRANS = .01;
const float MAX_TRANS = .10;
const float MIN_DELTA_ROTATION = 1.0;
const float MAX_DELTA_ROTATION = 5.0;
const float MIN_DELTA_SURFACE = .005;
const float MAX_DELTA_SURFACE = .01;
const int MIN_LIFETIME = 10;
const int MAX_LIFETIME = 25;
const int DELTA_LIFETIME = 1;


struct Particle{
		//Used For Randomizing The Initial Position of the Particle
		float azimuthRoation, zenithRotation, surfaceTranslationFactor;

		//Used For Randomizing The Delta or Change In Position of Each Particle
		float deltaAz, deltaZe, deltaSurface;

		//Lifetime In "Refreshes"
		int lifetime;
};
		
class ParticleSystem{
	
	public: 
		//Gets the next particle in the array
		Particle getNextParticle();
		//Modify all particles by their deltas, destroy old ones and create new ones
		//if the lifetime is 0
		void updateAll();
		int getNumberOfParticles();
		ParticleSystem();


	private:
		//Marker used by getNextParticle to keep track of position.
		int currentParticle;

		//Array of all particle structs
		Particle particles[NUMBER_OF_PARTICLES];
	
		float generateRandomNumber(float lower, float upper);
		Particle generateNewParticle();

};

ParticleSystem::ParticleSystem(){
	currentParticle = 0;
	for(int i = 0; i < NUMBER_OF_PARTICLES; i++){
		particles[i] = generateNewParticle();
	}
}

Particle ParticleSystem::generateNewParticle(){
	Particle newPart;
		newPart.azimuthRoation = generateRandomNumber(MIN_ROTATION, MAX_ROTATION);
		newPart.zenithRotation = generateRandomNumber(MIN_ROTATION, MAX_ROTATION);
		newPart.surfaceTranslationFactor = generateRandomNumber(MIN_TRANS, MAX_TRANS);
		newPart.deltaAz = generateRandomNumber(MIN_DELTA_ROTATION, MAX_DELTA_ROTATION);
		newPart.deltaZe = generateRandomNumber(MIN_DELTA_ROTATION, MAX_DELTA_ROTATION);
		newPart.deltaSurface = generateRandomNumber(MIN_DELTA_SURFACE, MAX_DELTA_SURFACE);
		newPart.lifetime = (int)generateRandomNumber(MIN_LIFETIME, MAX_LIFETIME);
		return newPart;
}

Particle ParticleSystem::getNextParticle(){
	currentParticle = (currentParticle == NUMBER_OF_PARTICLES) ? 0 : currentParticle;
	return particles[currentParticle++];
}

int ParticleSystem::getNumberOfParticles(){
	return NUMBER_OF_PARTICLES;
}

float ParticleSystem::generateRandomNumber(float lower, float upper){
	static bool firstTime = true;
	time_t randomNumberSeed;

	if (firstTime){
		time(&randomNumberSeed);
		srand(randomNumberSeed);
		firstTime = false;
	}
	return (lower + ((upper - lower) * (float(rand()) / RAND_MAX)));
}

void ParticleSystem::updateAll(){
	for(int i = 0; i < NUMBER_OF_PARTICLES; i++){
		if(particles[i].lifetime == 0){
			particles[i] = generateNewParticle();
		}else{
			particles[i].azimuthRoation += particles[i].deltaAz;
			particles[i].zenithRotation += particles[i].deltaZe;
			particles[i].surfaceTranslationFactor += particles[i].deltaSurface;
			particles[i].lifetime -= DELTA_LIFETIME;
		}
	}
}


