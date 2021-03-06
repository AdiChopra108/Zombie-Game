#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Bengine {

	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();

		void init(int screenWidth, int screenHeight);

		void update();

		glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

		bool isBoxInView(const glm::vec2& position, const glm::vec2 dimensions);

		//setters
		void setPosition(glm::vec2& newPosition) { 
			_position = newPosition; 
			_needsMatrixUpdate = true; 
		}

		void setScale(float newScale) { 
			_scale = newScale; 
			_needsMatrixUpdate = true;
		}

		//getters
		float getScale() { return _scale; }
		glm::vec2 getPosition() { return _position; }
		glm::mat4 getCameraMatrix() { return _cameraMatrix; }

	private:
		int _screenWidth = 1024;
		int _screenHeight = 720;
		bool _needsMatrixUpdate = true;
		float _scale = 1.0f;
		glm::vec2 _position = glm::vec2(0.0f);
		glm::mat4 _cameraMatrix = glm::mat4(1.0f);
		glm::mat4 _orthoMatrix = glm::mat4(1.0f);

	};

}
