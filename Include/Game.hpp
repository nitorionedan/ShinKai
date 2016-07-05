#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"
#include "Image.hpp"
#include "Player.hpp"

#include <memory>


//ゲーム画面クラス
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Update() override;     //更新処理をオーバーライド
	void Draw() override;       //描画処理をオーバーライド
	
private:
	std::unique_ptr<Image> img;
	std::shared_ptr<Player> player;
};

#endif
// EOF