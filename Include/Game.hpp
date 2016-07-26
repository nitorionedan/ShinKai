#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"
#include "Image.hpp"
#include "Player.hpp"
#include "Stage.hpp"
#include "SeaCreature.hpp"
#include <memory>


// Game display class
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Initialize();
	void Update() override;
	void Draw() override;
	
private:
	std::unique_ptr<Image> img;
	std::unique_ptr<Player> player;
	std::unique_ptr<Stage> stage;
	std::unique_ptr<SeaCreature> seaCre;
	bool isPause;
};

#endif
// EOF