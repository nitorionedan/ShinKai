#ifndef DEF_MENU_HPP
#define DEF_MENU_HPP

#include "BaseScene.hpp"
#include "Image.hpp"
#include <memory>


class Menu : public BaseScene
{
public:
	Menu(ISceneChanger* changer);
	~Menu();

private:
	void Update() override;
	void Draw() override;

	std::unique_ptr<Image> img;
};

#endif
// EOF
