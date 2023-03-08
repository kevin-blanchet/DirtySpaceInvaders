#include "ConsoleRenderer.h"

#include <thread>
#include <memory>

#include "Alien.h"
#include "PlayerShip.h"
#include "PlayField.h"
#include "Random.h"

int main()
{
	rGen.seed(1);

	Vector2D size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x- 1);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien& a = *(new Alien);
		a.pos.x = (float)xCoord(rGen);
		a.pos.x = (float)yCoord(rGen);
		world.AddObject(&a);
	}

	// Add player
	PlayerShip* p = new PlayerShip;
	p->pos = Vector2D(40, 27);
	world.AddObject(p);

	for (int i = 0; i < 1000; i++)
	{
		world.Update();

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->pos), it->sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
