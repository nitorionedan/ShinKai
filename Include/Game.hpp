#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"


//�Q�[����ʃN���X
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Update() override;     //�X�V�������I�[�o�[���C�h
	void Draw() override;       //�`�揈�����I�[�o�[���C�h
	
private:

};

#endif
// EOF