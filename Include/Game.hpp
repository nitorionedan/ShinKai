#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"
#include "Image.hpp"
#include "Player.hpp"

#include <memory>


// Game display class
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Update() override;
	void Draw() override;
	
private:
	std::unique_ptr<Image> img;
	std::shared_ptr<Player> player;
};

#endif
// EOF